#include "solve.h"
#include <cmath>
#include <stdexcept>


std::vector<double> solve(double a, double b, double c) {
    

    if (std::isnan(a) || std::isnan(b) || std::isnan(c) || std::isinf(a) || std::isinf(b) || std::isinf(c)) {
        throw std::invalid_argument("invalid_argument");
    }

    double epsilon = 1e-9;
    if (std::abs(a) < epsilon) {
        throw std::invalid_argument("invalid_argument a");
    }


    double D = b * b - 4 * a * c;
    
    if (std::abs(D) < epsilon) {
        double x = -b / (2 * a);
        return {x, x};
    }


    if (D > 0) {
        double x1 = (-b + std::sqrt(D))/(2 * a);
        double x2 = (-b - std::sqrt(D))/(2 * a);
        return {x1, x2};
    }
  
    return {};
}