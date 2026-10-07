#include <gtest/gtest.h>
#include "solve.h"

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
    double a = 1, b = 2, c = 1;  // x^2+2x+1 = 0

    // Act
    auto roots = solve(a, b, c);

    // Assert
    ASSERT_EQ(roots.size(), 2);
    EXPECT_EQ(roots[0], -1);
    EXPECT_EQ(roots[1], -1);
}