#include "solve.h"
#include "cmath"


std::vector<double> solve(double a, double b, double c) {
    
    double D = b * b - 4 * a * c;
    if (D > 0) {
        double x1 = (-b + std::sqrt(D))/(2 * a);
        double x2 = (-b - std::sqrt(D))/(2 * a);
        return {x1, x2};
    }

    if (D == 0) {
        double x = -b / (2 * a);
        return {x, x};
    }
    
    return {};
}