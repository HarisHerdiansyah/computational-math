#include <iostream>
#include <vector>

std::vector<double> deflation(const std::vector<double> &coef_mtx, const double x) {
    std::vector<double> solution(coef_mtx.size() + 1);
    solution[coef_mtx.size()] = 0;

    for (int i = coef_mtx.size() - 1; i >= 0; i--) {
        solution[i] = coef_mtx[i] + x * solution[i + 1];
    }

    return solution;
}

int main() {
    const double x = 1;
    const std::vector<double> b_coef_mtx = {3, -5, 2, -1, 4, -2, 1};

    double fx = deflation(b_coef_mtx, x)[0];
    double dfx = deflation(deflation(b_coef_mtx, x), x)[1];

    std::cout << "f(x): " << fx << std::endl;   // Expected output
    std::cout << "f'(x): " << dfx << std::endl;

    return 0;
}