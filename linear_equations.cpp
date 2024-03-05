#include <iostream>

using namespace std;

// Function to perform Gauss-Jordan elimination:
void gaussJordanElimination(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1
        double divisor = matrix[i][i];
        for (int j = 0; j < n + 1; j++) {
            matrix[i][j] /= divisor;
        }

        // Make the other elements in the column zero:
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n + 1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    // Read number of variables:
    int n;
    cin >> n;

    // Dynamically allocate memory for the matrix in the heap:
    double** equations = new double*[n];
    for (int i = 0; i < n; i++) {
        equations[i] = new double[n + 1];
    }

    // Read coefficients:
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j <= m; j++) {
            cin >> equations[i][j];
        }
    }

    // Perform Gauss-Jordan elimination:
    gaussJordanElimination(equations, n);

    // Check if the system is solvable:
    bool solvable = true;
    for (int i = 0; i < n; i++) {
        if (equations[i][i] == 0 && equations[i][n] != 0) {
            solvable = false;
            break;
        }
    }

    // Output the result:
    if (solvable) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            printf("%.2lf ",equations[i][n]);
        }
    } else {
        cout << "NO" << endl;
    }

    // Deallocate memory:
    for (int i = 0; i < n; i++) {
        delete[] equations[i];
    }
    delete[] equations;

    return 0;
}