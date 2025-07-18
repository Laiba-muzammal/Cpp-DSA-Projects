#include <iostream>
using namespace std;

void rotateMatrix90(int matrix[][100], int n) {
    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix size (N x N): ";
    cin >> n;

    int matrix[100][100];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:\n";
    printMatrix(matrix, n);

    rotateMatrix90(matrix, n);

    cout << "After 90° rotation:\n";
    printMatrix(matrix, n);

    return 0;
}
