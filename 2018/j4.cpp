#include <iostream>
#include <vector>

using namespace std;

int n;

void rotV(int ma[n]*){
    int **m;
    if (ma[0][0] > ma[0][n] && ma[0][0] < ma[n][0]){
        // rotate 2d array
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                m[i][j] = ma[j][i];
            }
        }
        rotV(m);
    } else {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << ma[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    cin >> n;
    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    rotV(matrix[n][n]);
    return 0;
}