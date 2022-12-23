//
// Created by trist on 2022-12-23.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> x;
    vector<int> y;
    string coord;
    getline(cin, coord); // consume the newline character

    for (int i = 0; i < num; i++) {
        getline(cin, coord);
        stringstream ss(coord);
        string token;
        vector<int> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(stoi(token));
        }
        x.push_back(tokens[0]);
        y.push_back(tokens[1]);
    }

    int hx = x[0];
    int hy = y[0];
    int lx = x[0];
    int ly = y[0];
    for (int i = 1; i < x.size(); i++) {
        if (hx < x[i]) {
            hx = x[i];
        }
    }
    for (int i = 1; i < y.size(); i++) {
        if (hy < y[i]) {
            hy = y[i];
        }
    }
    for (int i = 1; i < x.size(); i++) {
        if (lx > x[i]) {
            lx = x[i];
        }
    }
    for (int i = 1; i < y.size(); i++) {
        if (ly > y[i]) {
            ly = y[i];
        }
    }

    hx++;
    hy++;
    lx--;
    ly--;
    cout << lx << "," << ly << endl;
    cout << hx << "," << hy << endl;

    return 0;
}