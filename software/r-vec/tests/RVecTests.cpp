#include "RVec.h"

#include <cmath>
#include <cstdlib>
#include <limits>
#include <stdexcept>

namespace {

void expect(bool condition, const char* message)
{
    if(!condition){
        throw std::runtime_error(message);
    }
}

template <typename Exception, typename Operation>
void expect_exception(Operation operation, const char* message)
{
    try {
        operation();
    } catch(const Exception&){
        return;
    }

    throw std::runtime_error(message);
}

} // namespace

int main()
{
    const RVec r1{4.0};
    const RVec r4{1.0, 2.0, 3.0, 4.0};

    expect(r1.dimension() == 1, "R^1 dimension is incorrect");
    expect(r4.dimension() == 4, "R^4 dimension is incorrect");
    expect(r4[0] == 1.0 && r4[3] == 4.0, "component access is incorrect");

    const RVec sum = r4 + RVec{4.0, 3.0, 2.0, 1.0};
    expect(sum.dimension() == 4, "addition changed the dimension");
    expect(sum[0] == 5.0 && sum[1] == 5.0 &&
           sum[2] == 5.0 && sum[3] == 5.0,
           "R^4 addition is incorrect");
    expect(r4[0] == 1.0 && r4[3] == 4.0,
           "addition modified an operand");

    const RVec difference = r4 - r4;
    expect(difference.dimension() == 4,
           "subtraction changed the dimension");
    expect(difference[0] == 0.0 && difference[1] == 0.0 &&
           difference[2] == 0.0 && difference[3] == 0.0,
           "subtracting a vector from itself did not produce the null vector");
    expect(r4[0] == 1.0 && r4[3] == 4.0,
           "subtraction modified an operand");

    const RVec chained_sum = r4 + RVec{1.0, 1.0, 1.0, 1.0} +
                             RVec{2.0, 2.0, 2.0, 2.0};
    expect(chained_sum[0] == 4.0 && chained_sum[3] == 7.0,
           "chained addition is incorrect");

    expect_exception<std::invalid_argument>(
        [] { static_cast<void>(RVec{}); },
        "R^0 vector was accepted");
    expect_exception<std::invalid_argument>(
        [] { static_cast<void>(RVec{std::numeric_limits<double>::infinity()}); },
        "infinite component was accepted");
    expect_exception<std::invalid_argument>(
        [] { static_cast<void>(RVec{std::nan("")}); },
        "NaN component was accepted");
    expect_exception<std::out_of_range>(
        [&r4] { static_cast<void>(r4[4]); },
        "out-of-range component access was accepted");
    expect_exception<std::invalid_argument>(
        [&r1, &r4] { static_cast<void>(r1 + r4); },
        "mixed-dimension addition was accepted");
    expect_exception<std::invalid_argument>(
        [&r1, &r4] { static_cast<void>(r1 - r4); },
        "mixed-dimension subtraction was accepted");

    return EXIT_SUCCESS;
}
