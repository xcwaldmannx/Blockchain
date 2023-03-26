#pragma once

#include <iostream>
#include <vector>

class SystemSolver {
public:
    static std::vector<double> solveSystem(std::vector<std::vector<double>> A, std::vector<double> b) {
        int n = A.size();

        // Calculate the determinant of the matrix
        double det = 1.0;
        for (int i = 0; i < n; i++) {
            det *= A[i][i];
            for (int j = i + 1; j < n; j++) {
                double factor = A[j][i] / A[i][i];
                for (int k = i; k < n; k++) {
                    A[j][k] -= factor * A[i][k];
                }
                b[j] -= factor * b[i];
            }
        }

        // Check if the matrix is singular
        if (det == 0.0) {
            std::cout << "Error: the matrix is singular, i.e., it has no unique solution.\n";
            return std::vector<double>();
        }

        // Back-substitute to solve for x
        std::vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0.0;
            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        return x;
    }
private:
    const double eps = 1e-9; // tolerance for comparing floating-point numbers
};
