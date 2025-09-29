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
        double fx = f(x);
        double dfx = df(x);
        if (std::fabs(dfx) < 1e-12) throw std::domain_error("Denominator too small or zero. No solution found.");
        if (std::fabs(fx) < tol) return x;

        double x_new = x - (fx / dfx);
        if (std::fabs(x_new - x) < tol) return x_new;
        x = x_new;
    }

    throw std::domain_error("No solution exists");
}

int main() {
    return 0;
}