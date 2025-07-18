#include <iostream>
using namespace std;

int leftDiagonalSum(int matrix[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

int rightDiagonalSum(int matrix[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][n - i - 1];
    }
    return sum;
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

    cout << "Left Diagonal Sum: " << leftDiagonalSum(matrix, n) << endl;
    cout << "Right Diagonal Sum: " << rightDiagonalSum(matrix, n) << endl;

    return 0;
}
