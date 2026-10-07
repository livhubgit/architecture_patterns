#include <gtest/gtest.h>
#include "solve.h"
#include <stdexcept>
#include <limits>

TEST(SolveTest, NoRealRoots) {
    // Arrange
    double a = 1, b = 0, c = 1;  // x^2 + 1 = 0

    // Act
    auto roots = solve(a, b, c);

    // Assert
    EXPECT_TRUE(roots.empty());
}

TEST(SolveTest, TwoRootsMultiplicity1) {
    // Arrange
    double a = 1, b = 0, c = -1;  // x^2-1 = 0

    // Act
    auto roots = solve(a, b, c);

    // Assert
    ASSERT_EQ(roots.size(), 2);
    EXPECT_EQ(roots[0], 1);
    EXPECT_EQ(roots[1], -1);
}

TEST(SolveTest, OneRootMultiplicity2) {
    // Arrange
    double a = 1, b = 2, c = 1 - 1e-10;  // x^2+2x+1 = 0

    // Act
    auto roots = solve(a, b, c);

    // Assert
    ASSERT_EQ(roots.size(), 2);
    EXPECT_EQ(roots[0], -1);
    EXPECT_EQ(roots[1], -1);
}


TEST(SolveTest, ZeroACoefficientThrows) {
    // Arrange
    double a = 0, b = 1, c = 1;  // a = 0, недопустимое значение

    // Act + Assert
    EXPECT_THROW(solve(a, b, c), std::invalid_argument);
}


TEST(SolveTest, ThrowsOnNonNumericCoefficients) {
    // Arrange
    std::vector<double> invalidValues = {
        std::numeric_limits<double>::quiet_NaN(),
        std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity()
    };
    double validCoefficient = 1; 

    
    // Act + Assert
    for (double invalid : invalidValues) {
        double a = invalid, b = validCoefficient, c = validCoefficient;
        EXPECT_THROW(solve(a, b, c), std::invalid_argument);

        a = validCoefficient; b = invalid; c = validCoefficient;
        EXPECT_THROW(solve(a, b, c), std::invalid_argument);

        a = validCoefficient; b = validCoefficient; c = invalid;
        EXPECT_THROW(solve(a, b, c), std::invalid_argument);
    }
}