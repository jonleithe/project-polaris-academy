#pragma once

#include <cstddef>
#include <initializer_list>
#include <iosfwd>
#include <vector>

// A vector in a finite-dimensional real coordinate space.
// Currently restricted to R2 and R3.
//
// Unlike a C-style struct, this class protects its invariant: every RVector
// must contain exactly two or three finite numbers. Clients can inspect and
// operate on a vector, but cannot directly mutate its stored components.
class RVector {
public:
    // "explicit" prevents an implicit conversion such as:
    //     std::vector<double> values{1, 2};
    //     RVector v = values;                 // deliberately not allowed
    // Callers must write RVector(values), making the conversion visible.
    //
    // Taking the vector by value is intentional. An lvalue is copied into the
    // parameter, while an rvalue can be moved into it; the implementation then
    // moves that parameter into components_. This is the modern "sink
    // parameter" idiom for an object the class intends to own.
    explicit RVector(std::vector<double> components);

    // std::initializer_list enables the convenient RVector{1.0, 2.0, 3.0}
    // syntax. Curly-brace initialization was greatly expanded in C++11.
    RVector(std::initializer_list<double> components);

    // [[nodiscard]] (C++17) asks the compiler to warn if a caller ignores the
    // result. The trailing "const" means these functions do not modify *this.
    // noexcept is a promise that dimension() cannot throw an exception.
    [[nodiscard]] std::size_t dimension() const noexcept;
    [[nodiscard]] double magnitude() const;
    [[nodiscard]] double dot(const RVector& other) const;
    [[nodiscard]] RVector cross(const RVector& other) const;

    // Operator overloads let vectors use mathematical notation. They return a
    // new RVector and leave both operands unchanged, hence the trailing const.
    [[nodiscard]] RVector operator+(const RVector& other) const;
    [[nodiscard]] RVector operator-(const RVector& other) const;
    [[nodiscard]] RVector operator*(double scalar) const;

    // This overload offers read-only indexing. std::size_t is the unsigned
    // type used by standard containers for sizes and indexes.
    [[nodiscard]] double operator[](std::size_t index) const;

private:
    // std::vector owns and frees its dynamic storage automatically (RAII), so
    // this class needs no destructor, copy constructor, or assignment operator.
    // The compiler-generated versions do the correct thing: the "rule of zero".
    // The trailing underscore is simply this project's member-naming convention.
    std::vector<double> components_;

    // Centralizing this precondition avoids duplicating the same check in dot,
    // addition, and any future two-vector operations.
    void require_same_dimension(const RVector& other) const;
};

// These are non-member operators. scalar * vector must be non-member because
// the left operand is a double, not an RVector. Stream insertion is conventionally
// non-member too, since its left operand is std::ostream.
RVector operator*(double scalar, const RVector& vector);
std::ostream& operator<<(std::ostream& output, const RVector& vector);
