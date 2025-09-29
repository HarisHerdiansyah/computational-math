#include <iostream>
#include <cmath>
#include <stdexcept>

double f(const double x) {
    return x*x*x - 6*x*x + 11*x - 6;
}

double g1(const double x) {
    return std::cbrt(6*x*x - 11*x + 6); // cbrt -> cube root -> akar pangkat tiga
}

double dg1(const double x) {
    double u = 6*x*x - 11*x + 6;
    return (1.0/3.0) * (12*x - 11) / std::cbrt(u*u);
}

double g2(const double x) {
    return std::sqrt((x*x*x + 11*x - 6) / 6.0);
}

double dg2(const double x) {
    double v = (x*x*x + 11*x - 6) / 6.0;
    return (3*x*x + 11) / (12.0 * std::sqrt(v));
}

double g3(const double x) {
    return (6*x*x - x*x*x + 6) / 11.0;
}

double dg3(const double x) {
    return (12*x - 3*x*x) / 11.0;
}

double fixed_point_iteration(double x, const double tol, const int max_iter) {
    if (std::fabs(dg1(x)) >= 1) {
        throw std::domain_error("Iteration is divergent.");
    }

    for (int i = 0; i < max_iter; i++) {
        double x_new = g1(x);
        if (std::fabs(x_new - x) < tol || std::fabs(f(x_new)) < tol)
            return x_new;
        x = x_new;
    }

    throw std::domain_error("Maximum iterations reached without convergence.");
}

int main() {
    return 0;
}