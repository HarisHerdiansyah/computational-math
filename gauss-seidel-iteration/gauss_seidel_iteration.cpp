#include <iostream>

/*
Example of system of linear equations:
10x + 2y + z = 9
2x + 20y -2z = -44
-2x + 3y + 10z = 22
*/

double x_f(const double y, const double z) {
    return (9 - 2*y - z) / 10;
}

double y_f(const double x, const double z) {
    return (-44 - 2*x + 2*z) / 20;
}

double z_f(const double x, const double y) {
    return (22 + 2*x - 3*y) / 10;
}

void gauss_seidel_iteration(const int iteration, double x, double y, double z) {
    for (int i = 1; i <= iteration; i++) {
        std::cout << "\niteration" << i << std::endl;
        x = x_f(y ,z); std::cout << "x: " << x << std::endl;
        y = y_f(x, z); std::cout << "y: " << y << std::endl;
        z = z_f(x, y); std::cout << "z: " << z << std::endl;
    }
}

int main() {
    return 0;
}