#include <iostream>
using namespace std;


void towerOfHanoi(int N, char S, char A, char D, int& movesCount) {
    
    if (N == 1) {
        cout << "Move disk 1 from " << S << " to " << D << "." << endl;
        movesCount++;  
        return;
    }

    towerOfHanoi(N - 1, S, D, A, movesCount);

    cout << "Move disk " << N << " from " << S << " to " << D << "." << endl;
    movesCount++; 


    towerOfHanoi(N - 1, A, S, D, movesCount);
}

int main() {
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;  

    int movesCount = 0;  

    towerOfHanoi(N, 'S', 'A', 'D', movesCount);

    cout << "Total number of moves: " << movesCount << endl;

    return 0;
}
