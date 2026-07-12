#include "RVector.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>



namespace {

bool approximately_equal(double first, double second)
{
    return std::abs(first - second) < 1e-12;
}



void expect(bool condition, const char* message)
{
    if(!condition){
        throw std::runtime_error(message);
    }
}



template <typename Operation>
void expect_invalid_argument(Operation operation, const char* message)
{
    try {
        operation();
    } catch (const std::invalid_argument&) {
        return;
    }
    throw std::runtime_error(message);
}

}  // namespace

int main()
{
    try {
        const RVector a{1.0, 2.0, 3.0};
        const RVector b{4.0, 5.0, 6.0};
        const RVector r2{3.0, 4.0};

        expect(approximately_equal(r2.magnitude(), 5.0), "R2 magnitude failed");
        expect(approximately_equal(a.dot(b), 32.0), "dot product failed");

        const RVector sum = a + b;
        expect(sum[0] == 5.0 && sum[1] == 7.0 && sum[2] == 9.0,
               "addition failed");

        const RVector difference = b - a;
        expect(difference[0] == 3.0 && difference[1] == 3.0 && difference[2] == 3.0,
               "subtraction failed");

        const RVector scaled = 2.0 * r2;
        expect(scaled[0] == 6.0 && scaled[1] == 8.0, "scalar multiplication failed");

        const RVector cross = a.cross(b);
        expect(cross[0] == -3.0 && cross[1] == 6.0 && cross[2] == -3.0,
               "cross product failed");

        expect_invalid_argument([&] { static_cast<void>(a + r2); },
                                "mixed-dimension addition was accepted");
        expect_invalid_argument([&] { static_cast<void>(r2.cross(r2)); },
                                "R2 cross product was accepted");
        expect_invalid_argument([] { static_cast<void>(RVector{1.0}); },
                                "R1 vector was accepted");
    } catch (const std::exception& error) {
        std::cerr << "Test failure: " << error.what() << '\n';
        return EXIT_FAILURE;
    }

    std::cout << "All RVector tests passed.\n";
    return EXIT_SUCCESS;
}
