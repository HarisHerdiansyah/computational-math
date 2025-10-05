#include <iostream>
#include <vector>

double deflation(const std::vector<double> &coef_mtx, const double x) {
    std::vector<double> solution(coef_mtx.size() + 1);
    solution[coef_mtx.size()] = 0;

    for (int i = coef_mtx.size() - 1; i >= 0; i--) {
        solution[i] = coef_mtx[i] + x * solution[i + 1];
    }

    return solution[0];
}

int main() {
    const std::vector<double> coef_mtx = {3, -5, 2, -1, 4, -2, 1};
    const double x = 1;
    double y = deflation(coef_mtx, x);
    std::cout << "Result: " << y << std::endl; // Expected output
    return 0;
}