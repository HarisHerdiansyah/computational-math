#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

typedef std::vector<double> row;
typedef std::vector<row> matrix;

std::vector<double> backward_substitution(const matrix &mtx) {
    const int n = mtx[0].size() - 1;
    std::vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += mtx[i][j] * solution[j];
        }

        if (mtx[i][i] == 0) {
            if (mtx[i][n] - sum != 0) {
                throw std::domain_error("No solution exists.");
            }
            solution[i] = std::numeric_limits<double>::quiet_NaN();
        } else {
            solution[i] = (mtx[i][n] - sum) / mtx[i][i];
        }
    }

    return solution;
}

int main() {
    return 0;
}
