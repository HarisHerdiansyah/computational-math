#include <iostream>
#include <cmath>
#include <stdexcept>

double f(const double x) {
    return x*x*x - 6*x*x + 11*x - 6;
}

double df(const double x) {
    return 3*x*x - 12*x + 11;
}

double newton_rapshon(double x, const double tol, const int max_iter) {
    for (int i = 0; i < max_iter; i++) {
        double dfx = df(x);
        if (std::fabs(dfx) < 1e-12) {
            throw std::runtime_error("Derivative too small");
        }
        x = x - f(x) / dfx;
        if (std::fabs(f(x)) < tol) return x;
    }
    throw std::domain_error("Maximum iterations reached without convergence.");
}

int main() {
    return 0;
}