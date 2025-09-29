#include <iostream>
#include <vector>

typedef std::vector<double> row;
typedef std::vector<row> matrix;

void print_mtx(const matrix &mtx) {
    for (const auto& r: mtx) {
        for (const auto& a: r) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
}

void scalar_multiplication(matrix &mtx, const double scalar, const int row_index) {
    for (auto &val: mtx[row_index]) val *= scalar;
}

int main() {
    matrix mtx_a = {
        {6, -2, 3, 1},
        {3, 6, -3, -2},
        {6, 6, 3, 5},
    };

    scalar_multiplication(mtx_a, 1.0 / mtx_a[0][0], 0);
    print_mtx(mtx_a);
    return 0;
}