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

int main() {
    return 0;
}