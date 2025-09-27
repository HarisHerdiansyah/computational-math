#include <iostream>
#include <cmath>
#include <stdexcept>

double f(const double x) {
    return x*x*x - 6*x*x + 11*x - 6;
}

double tabulation(const double a, const double b, const int iter) {
    if (iter <= 0) {
        throw std::invalid_argument("Number of iterations must be positive.");
    }

    if (a >= b) {
        throw std::invalid_argument("Lower bound must be less than upper bound.");
    }

    double step = (b - a) / iter;
    for (int i = 0; i < iter; i++) {
        double current_x = a + i * step;
        double next_x = current_x + step;

        double f1 = f(current_x);
        double f2 = f(next_x);

        if (f1 * f2 < 0) {
            if (std::fabs(f1) < std::fabs(f2)) {
                return current_x;
            }
            return next_x;
        }
    }

    throw std::domain_error("No root found in the given interval.");
}

int main() {
    return 0;
}