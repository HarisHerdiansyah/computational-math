#include <iostream>
#include <cmath>
#include <stdexcept>

double f(const double x) {
    return x*x*x - 6*x*x + 11*x - 6;
}

double get_x(const double a, const double b) {
    return (a * f(b) - b * f(a)) / (f(b) - f(a));
}

double regula_falsi(double a, double b, const double tol, const int max_iter) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) {
        throw std::invalid_argument("f(a) and f(b) must have different signs.");
    }

    for (int i = 0; i < max_iter; i++) {
        double x = get_x(a, b);
        double fx = f(x);

        if (std::fabs(b - a) < tol || std::fabs(fx) < tol) {
            return x;
        }

        if (fa * fx < 0) {
            b = x; fb = fx;
        } else {
            a = x; fa = fx;
        }
    }

    throw std::domain_error("Maximum iterations reached without convergence.");
}

int main() {
    return 0;
}