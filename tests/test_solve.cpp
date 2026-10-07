#include <gtest/gtest.h>
#include "solve.h"
#include <stdexcept>

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