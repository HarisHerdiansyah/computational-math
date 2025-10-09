#include <bits/stdc++.h>

typedef std::vector<double> row;
typedef std::vector<row> matrix;

void print_mtx(const matrix &mtx) {
    const int width = 6;
    const int precision = 2;

    for (const auto& row : mtx) {
        for (const auto& val : row) {
            std::cout << std::fixed << std::setprecision(precision)
                      << std::setw(width) << val << " ";
        }
        std::cout << std::endl;
    }
}

matrix augmented_matrix(const matrix &coef, const row &b) {
	matrix augmented = {};
	for (int i = 0; i < coef.size(); i++) {
		row r = {};
		for (int j = 0; j < coef[i].size(); j++) {
			r.push_back(coef[i][j]);
		}
		r.push_back(b[i]);
		augmented.push_back(r);
	}
	return augmented;
}

void gauss_elimination(matrix &am) {
	int r = 0; int m = am.size(); int n = am[0].size();

	// iterasi kolom
	for (int c = 0; c < n - 1; c++) {
		// pivot checking
		int pivot = -1;
		for (int i = r; i < m; i++) {
			if (am[i][c] != 0) {
				pivot = i;
				break;
			}
		}

		// jika pivot tidak ada, pindah ke kolom selanjutnya
		if (pivot == -1) continue;

		// jika pivot ada dan nilai pivot tidak sama dengan baris awal, maka tukar baris
		// r -> source row; pivot -> target row
		if (pivot != r) {
			row temp = am[pivot];
			am[pivot] = am[r];
			am[r] = temp;
		}

		// jika pivot bukan 1, maka lakukan perkalian baris
		double factor = am[r][c];
		if (am[r][c] != 1) {
			for (int k = 0; k < am[r].size(); k++) {
				am[r][k] /= factor;
				if (am[r][k] == -0.0) am[r][k] = std::fabs(am[r][k]);
			}
		}

		// lakukan operasi eliminasi menjadi 0 untuk setiap nilai di bawah pivot
		for (int j = r + 1; j < m; j++) {
			if (am[j][c] != 0) {
				double multiplier = -am[j][c];
				for (int l = 0; l < am[r].size(); l++) {
					am[j][l] += (multiplier * am[r][l]);
				}
			}
		}

		r++;
	}

	// lanjutkan proses di bawah untuk mencapai RREF
	for (int c = n - 2; c >= 0; c--) {
		// pivot checking
		int pivot = -1;
		for (int i = m - 1; i >= 0; i--) {
			if (am[i][c] == 1) {
				pivot = i;
				break;
			}
		}

		// jika cell bukan pivot, mundur 1 kolom
		if (pivot == -1) continue;

		// jika kolom adalah pivot, lakukan eliminasi
		for (int j = pivot - 1; j >= 0; j--) {
			if (am[j][c] != 0) {
				double multiplier = -am[j][c];
				for (int l = 0; l < am[pivot].size(); l++) {
					am[j][l] += (multiplier * am[pivot][l]);
				}
			}
		}
	}
}

std::vector<double> backward_substitution(const matrix &am) {
	const int coef_size = am[0].size() - 1;
	std::vector<double> solution(coef_size);
	for (int i = coef_size - 1; i >= 0; i--) {
		double sum = 0.0;
		for (int j = i + 1; j < coef_size; j++) {
			sum += (am[i][j] * solution[j]);
		}

		solution[i] = (am[i][coef_size] - sum) / am[i][i];
	}
	return solution;
}

int main() {
	matrix coef = {
		{1, 1, 2},
		{2, 4, -3},
		{3, 6, -5}
	};
	row b = {9, 1, 0};


	matrix am = augmented_matrix(coef, b);
	gauss_elimination(am);
	print_mtx(am);

	std::vector<double> sol = backward_substitution(am);
	for (const auto &d: sol) std::cout << d << " ";
	return 0;
}