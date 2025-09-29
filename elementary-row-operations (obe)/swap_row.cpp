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

void swap_rows(matrix &mtx, const int src_index, const int dest_index) {
    const row source_row = mtx[src_index];
    mtx[src_index] = mtx[dest_index];
    mtx[dest_index] = source_row;
}

void operations(matrix &mtx) {
    for (int i = 0; i < mtx.size(); i++) {
        for (int j = i + 1; j < mtx.size(); j++) {
            if (mtx[i][i] == 0 && mtx[j][i] != 0) {
                swap_rows(mtx, i, j);
            }
        }
    }
}

int main() {
    matrix mtx_a = {
        {0, -2, 3, 1},
        {3, 6, -3, -2},
        {6, 6, 3, 5},
    };

    matrix mtx_b = {
        {1, -2, 3, 1},
        {3, 6, -3, -2},
        {6, 6, 3, 5},
    };

    operations(mtx_a);
    operations(mtx_b);

    print_mtx(mtx_a);
    std::cout << std::endl;
    print_mtx(mtx_b);
    return 0;
}