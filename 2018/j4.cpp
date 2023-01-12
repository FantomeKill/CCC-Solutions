#include <iostream>
using namespace std;

void rotateMatrix(int** matrix, int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = temp;
        }
    }
}

bool isGood(int** matrix, int n) {
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (matrix[i][j] > matrix[i][j+1] || matrix[i][j] > matrix[i+1][j]) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    while(!isGood(matrix, n)){
        rotateMatrix(matrix,n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}