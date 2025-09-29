#include <iostream>
#include <cmath>
#include <stdexcept>

double f(const double x) {
    return x*x*x - 6*x*x + 11*x - 6;
}

double secant(double x0, double x1, const double tol, const int max_iter) {
    for (int i = 0; i < max_iter; i++) {
        double y0 = f(x0);
        double y1 = f(x1);

        if (std::fabs(y1 -y0) < 1e-12) throw std::domain_error("Denominator too small or zero. No solution found.");
        double x2 = (x1 - y1) * (x1 - x0) / (y1 - y0);

        if (std::fabs(x2 - x1) < tol || std::fabs(f(x2)) < tol) return x2;
        x0 = x1; x1 = x2;
    }

    throw std::domain_error("Maximum iterations reached without convergence.");
}

int main() {
    return 0;
}