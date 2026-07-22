#include "RVec.h"

#include <cmath>
#include <stdexcept>
#include <utility>

RVec::RVec(std::vector<double> components)
    : components_(std::move(components))
{
    if(components_.empty()){
        throw std::invalid_argument("an RVec must have at least one component");
    }

    for(const double component : components_){
        if(!std::isfinite(component)){
            throw std::invalid_argument("RVec components must be finite numbers");
        }
    }
}

RVec::RVec(std::initializer_list<double> components)
    : RVec(std::vector<double>(components))
{
}

std::size_t RVec::dimension() const noexcept
{
    return components_.size();
}

double RVec::operator[](std::size_t index) const
{
    return components_.at(index);
}

RVec RVec::operator+(const RVec& other) const
{
    if(dimension() != other.dimension()){
        throw std::invalid_argument("vectors must have the same dimension");
    }

    std::vector<double> sum(dimension());
    for(std::size_t index = 0; index < dimension(); ++index){
        sum[index] = components_[index] + other.components_[index];
    }

    return RVec(std::move(sum));
}

RVec RVec::operator-(const RVec& other) const
{
    if(dimension() != other.dimension()){
        throw std::invalid_argument("vectors must have the same dimension");
    }

    std::vector<double> difference(dimension());
    for(std::size_t index = 0; index < dimension(); ++index){
        difference[index] = components_[index] - other.components_[index];
    }

    return RVec(std::move(difference));
}
