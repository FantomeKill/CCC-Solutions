//
// Created by trist on 2023-02-17.
//

#include <iostream>

using namespace std;

int main() {
    int distances[4];
    cin >> distances[0] >> distances[1] >> distances[2] >> distances[3];

    int total_distances[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                total_distances[i][j] = 0;
            } else if (i < j) {
                int sum = 0;
                for (int k = i; k < j; k++) {
                    sum += distances[k];
                }
                total_distances[i][j] = sum;
                total_distances[j][i] = sum;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << total_distances[i][j];
            if (j < 4) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}