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