#include <iostream>
#include <iomanip>
#include <vector>

typedef std::vector<double> row;
typedef std::vector<row> matrix;

void print_mtx(const matrix &mtx) {
    const int width = 10;
    const int precision = 4;

    for (const auto& row : mtx) {
        for (const auto& val : row) {
            std::cout << std::fixed << std::setprecision(precision)
                      << std::setw(width) << val << " ";
        }
        std::cout << std::endl;
    }
}

matrix build_augmented_matrix(const matrix &a, const matrix &b) {
    matrix augmented_matrix = {};

    for (int i = 0; i < a.size(); i++) {
        row aug_row = {};
        for (int j = 0; j < a[0].size(); j++) {
            aug_row.push_back(a[i][j]);
        }
        aug_row.push_back(b[i][0]);
        augmented_matrix.push_back(aug_row);
    }

    return augmented_matrix;
}

void swap_rows(matrix &mtx, const int src_index, const int dest_index) {
    const row source_row = mtx[src_index];
    mtx[src_index] = mtx[dest_index];
    mtx[dest_index] = source_row;
}

void scalar_multiplication(matrix &mtx, const double scalar, const int row_index) {
    for (auto &val: mtx[row_index]) {
        if (val != 0) val *= scalar;
    }
}

void addition_with_multiples(matrix &mtx, const double multiplier, const int src_index, const int dest_index) {
    for (int i = 0; i < mtx[src_index].size(); i++) {
        mtx[dest_index][i] += (multiplier * mtx[src_index][i]);
    }
}

void gauss_elimination(matrix &mtx) {
    const int m = mtx.size(); // row
    const int n = mtx[0].size(); // column

    int r = 0;
    for (int c = 0; c < n; c++) {
        int pivot = -1;
        for (int i = r; i < m; i++) {
            if (mtx[i][c] != 0) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) continue;

        if (pivot != r) swap_rows(mtx, pivot, r);

        if (mtx[r][c] != 1) {
            scalar_multiplication(mtx, 1.0 / mtx[r][c], r);
        }

        for (int j = r + 1; j < m; j++) {
            if (mtx[j][c] != 0) {
                addition_with_multiples(mtx, -mtx[j][c], r, j);
            }
        }

        r++;
    }

    for (int c = n - 1; c >= 0; c--) {
        int pivot = -1;
        for (int i = m - 1; i >= 0; i--) {
            if (mtx[i][c] == 1) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) continue;

        for (int j = pivot - 1; j >= 0; j--) {
            if (mtx[j][c] != 0) {
                addition_with_multiples(mtx, -mtx[j][c], pivot, j);
            }
        }
    }
}

int main() {
    matrix mtx = {
        {0, -2, 3, 1},
        {3, 6, -3, -2},
        {6, 6, 3, 5}
    };
    gauss_elimination(mtx);
    print_mtx(mtx);
    return 0;
}