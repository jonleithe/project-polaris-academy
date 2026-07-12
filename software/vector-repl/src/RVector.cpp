#include "RVector.h"

#include <cmath>
#include <ostream>
#include <stdexcept>
#include <utility>



RVector::RVector(std::vector<double> components)
    : components_(std::move(components))
{
    if(components_.size() != 2 && components_.size() != 3){
        throw std::invalid_argument("an RVector must be in R2 or R3");
    }

    for(const double component : components_){
        if(!std::isfinite(component)){
            throw std::invalid_argument("vector components must be finite numbers");
        }
    }
}



RVector::RVector(std::initializer_list<double> components)
    : RVector(std::vector<double>(components))
{
}



std::size_t RVector::dimension() const noexcept
{
    return components_.size();
}



double RVector::magnitude() const
{
    return std::sqrt(dot(*this));
}



double RVector::dot(const RVector& other) const
{
    require_same_dimension(other);
    double result = 0.0;

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

    return {
        components_[1] * other.components_[2] - components_[2] * other.components_[1],
        components_[2] * other.components_[0] - components_[0] * other.components_[2],
        components_[0] * other.components_[1] - components_[1] * other.components_[0]
    };
}



RVector RVector::operator+(const RVector& other) const
{
    require_same_dimension(other);
    std::vector<double> result(dimension());

    for(std::size_t index = 0; index < dimension(); ++index){
        result[index] = components_[index] + other.components_[index];
    }

    return RVector(std::move(result));
}



RVector RVector::operator-(const RVector& other) const
{
    return *this + (other * -1.0);
}



RVector RVector::operator*(double scalar) const
{
    if(!std::isfinite(scalar)){
        throw std::invalid_argument("scalar must be a finite number");
    }

    std::vector<double> result = components_;
    for(double& component : result){
        component *= scalar;
    }
    return RVector(std::move(result));
}



double RVector::operator[](std::size_t index) const
{
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
    return vector * scalar;
}



std::ostream& operator<<(std::ostream& output, const RVector& vector)
{
    output << '(';
    for(std::size_t index = 0; index < vector.dimension(); ++index){
        if(index != 0){
            output << ", ";
        }
        output << vector[index];
    }
    return output << ')';
}
