#pragma once

#include <vector>
#include <cstddef>
#include <initializer_list>



// A vector in a finite-dimensional real coordinate space R^n, where n >= 1.
class RVec{

    public:
    explicit RVec(std::vector<double> components);
    RVec(std::initializer_list<double> components);

    [[nodiscard]] std::size_t dimension() const noexcept;
    [[nodiscard]] double operator[](std::size_t index) const;
    [[nodiscard]] RVec operator+(const RVec& other) const;
    [[nodiscard]] RVec operator-(const RVec& other) const;

private:
    std::vector<double> components_;
};
