#pragma once

#include <cstddef>
#include <initializer_list>
#include <iosfwd>
#include <vector>

// A vector in a finite-dimensional real coordinate space.
// Currently restricted to R2 and R3.
class RVector{
public:
    explicit RVector(std::vector<double> components);
    RVector(std::initializer_list<double> components);

    [[nodiscard]] std::size_t dimension() const noexcept;
    [[nodiscard]] double magnitude() const;
    [[nodiscard]] double dot(const RVector& other) const;
    [[nodiscard]] RVector cross(const RVector& other) const;

    [[nodiscard]] RVector operator+(const RVector& other) const;
    [[nodiscard]] RVector operator-(const RVector& other) const;
    [[nodiscard]] RVector operator*(double scalar) const;

    [[nodiscard]] double operator[](std::size_t index) const;

private:
    std::vector<double> components_;

    void require_same_dimension(const RVector& other) const;
};

RVector operator*(double scalar, const RVector& vector);
std::ostream& operator<<(std::ostream& output, const RVector& vector);
