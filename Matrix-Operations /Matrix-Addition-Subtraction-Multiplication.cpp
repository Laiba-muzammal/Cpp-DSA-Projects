#include <iostream>
using namespace std;

void matrixOperation(int op) {
    int r1, c1, r2, c2;
    cout << "Enter dimensions for matrix 1 (rows cols): ";
    cin >> r1 >> c1;
    cout << "Enter dimensions for matrix 2 (rows cols): ";
    cin >> r2 >> c2;

    if((op==1||op==2) && (r1!=r2 || c1!=c2)) {
        cout << "Operation not possible!\n";
        return;
    }
    if(op==3 && c1!=r2) {
        cout << "Multiplication not possible!\n";
        return;
    }

    int a[100][100], b[100][100], res[100][100] = {0};
    
    cout << "Enter matrix 1:\n";
    for(int i=0; i<r1; i++)
        for(int j=0; j<c1; j++)
            cin >> a[i][j];
    
    cout << "Enter matrix 2:\n";
    for(int i=0; i<r2; i++)
        for(int j=0; j<c2; j++)
            cin >> b[i][j];

    switch(op) {
        case 1: // Addition
            for(int i=0; i<r1; i++)
                for(int j=0; j<c1; j++)
                    res[i][j] = a[i][j] + b[i][j];
            break;
        case 2: // Subtraction
            for(int i=0; i<r1; i++)
                for(int j=0; j<c1; j++)
                    res[i][j] = a[i][j] - b[i][j];
            break;
        case 3: // Multiplication
            for(int i=0; i<r1; i++)
                for(int j=0; j<c2; j++)
                    for(int k=0; k<c1; k++)
                        res[i][j] += a[i][k] * b[k][j];
            break;
    }

    cout << "Result:\n";
    for(int i=0; i<(op==3?r1:r1); i++) {
        for(int j=0; j<(op==3?c2:c1); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int choice;
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\nChoice: ";
    cin >> choice;
    matrixOperation(choice);
    return 0;
}
