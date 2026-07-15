#include "../include/RVector.h"

#include <cmath>
#include <ostream>
#include <stdexcept>
#include <utility>

// Definitions outside the class use ClassName:: to say which class scope the
// function belongs to. The interface stays in RVector.h; implementation details
// and heavier standard-library headers stay here to reduce recompilation.
RVector::RVector(std::vector<double> components)
    // A member-initializer list constructs components_ directly. std::move does
    // not itself move anything; it marks components as eligible to have its
    // storage transferred. std::vector's move constructor then performs that
    // cheap transfer instead of copying every double (C++11 move semantics).
    : components_(std::move(components))
{
    // Establish the class invariant at its boundary. Throwing from a constructor
    // means no partially valid RVector can escape to the caller.
    if(components_.size() != 2 && components_.size() != 3){
        throw std::invalid_argument("an RVector must be in R2 or R3");
    }

    // A range-based for loop (C++11) visits each value without manual indexes.
    // "const double" documents that validation will not alter the component.
    for(const double component : components_){
        if(!std::isfinite(component)){
            throw std::invalid_argument("vector components must be finite numbers");
        }
    }
}



RVector::RVector(std::initializer_list<double> components)
    // This is a delegating constructor (C++11): first make a std::vector from
    // the brace-list, then reuse the main constructor and all its validation.
    : RVector(std::vector<double>(components))
{
}



std::size_t RVector::dimension() const noexcept
{
    return components_.size();
}



double RVector::magnitude() const
{
    // *this is the current RVector object. Reusing dot() implements |v| as
    // sqrt(v dot v), keeping the arithmetic in one place.
    return std::sqrt(dot(*this));
}



double RVector::dot(const RVector& other) const
{
    require_same_dimension(other);
    double result = 0.0;

    // Prefix ++ is a long-standing style preference for iterators. For this
    // integer index it has the same practical effect as index++.
    for(std::size_t index = 0; index < dimension(); ++index){
        result += components_[index] * other.components_[index];
    }

    return result;
}



RVector RVector::cross(const RVector& other) const
{
    if(dimension() != 3 || other.dimension() != 3){
        throw std::invalid_argument("cross product is defined here only for R3 vectors");
    }

    // The braced return value constructs an RVector via its initializer-list
    // constructor. Since C++17, returning a newly constructed value like this
    // is guaranteed not to create an extra temporary copy (copy elision).
    return {
        components_[1] * other.components_[2] - components_[2] * other.components_[1],
        components_[2] * other.components_[0] - components_[0] * other.components_[2],
        components_[0] * other.components_[1] - components_[1] * other.components_[0]
    };
}



RVector RVector::operator+(const RVector& other) const
{
    require_same_dimension(other);
    // vector(size) creates the requested number of value-initialized doubles
    // (all 0.0), after which the loop fills them in.
    std::vector<double> result(dimension());

    for(std::size_t index = 0; index < dimension(); ++index){
        result[index] = components_[index] + other.components_[index];
    }

    // result is no longer needed, so transfer its allocation to the RVector.
    return RVector(std::move(result));
}



RVector RVector::operator-(const RVector& other) const
{
    // Express subtraction in terms of already-tested addition and scaling.
    return *this + (other * -1.0);
}



RVector RVector::operator*(double scalar) const
{
    if(!std::isfinite(scalar)){
        throw std::invalid_argument("scalar must be a finite number");
    }

    // This line intentionally copies: scaling must not mutate the original.
    std::vector<double> result = components_;
    // double& is a reference to each actual element, so *= changes result.
    for(double& component : result){
        component *= scalar;
    }
    return RVector(std::move(result));
}



double RVector::operator[](std::size_t index) const
{
    // at() checks its bounds and throws std::out_of_range. vector's own [] is
    // unchecked, despite this public function itself being named operator[].
    return components_.at(index);
}



void RVector::require_same_dimension(const RVector& other) const
{
    if(dimension() != other.dimension()){
        throw std::invalid_argument("vectors must have the same dimension");
    }
}



RVector operator*(double scalar, const RVector& vector)
{
    // Delegate to the member overload, so 2.0 * v and v * 2.0 behave alike.
    return vector * scalar;
}



std::ostream& operator<<(std::ostream& output, const RVector& vector)
{
    // Return the same stream by reference so insertions can be chained:
    // std::cout << vector << '\n'. No stream is copied.
    output << '(';
    for(std::size_t index = 0; index < vector.dimension(); ++index){
        if(index != 0){
            output << ", ";
        }
        output << vector[index];
    }
    return output << ')';
}
