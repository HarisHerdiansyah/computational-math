#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

typedef std::vector<double> row;
typedef std::vector<row> matrix;

std::vector<double> backward_substitution(const matrix &coef_mtx, const row &b_mtx) {
    const int n = coef_mtx[0].size();
    std::vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += coef_mtx[i][j] * solution[j];
        }

        if (coef_mtx[i][i] == 0) {
            if (b_mtx[i] - sum != 0) {
                throw std::domain_error("No solution exists.");
            }
            solution[i] = std::numeric_limits<double>::quiet_NaN();
        } else {
            solution[i] = (b_mtx[i] - sum) / coef_mtx[i][i];
        }
    }

    return solution;
}

int main() {
    return 0;
}
