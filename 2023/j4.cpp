//
// Created by cyber-toxo on 2/15/23.
//

#include <bits/stdc++.h>

using namespace std;

bool isPair(int n){
    if (n%2 == 0) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    int one[c];
    int tow[c];

    for (int i = 0; i < c; ++i) {
        cin >> one[i];
    }
    for (int i = 0; i < c; ++i) {
        cin >> tow[i];
    }

    int p = 0;

    for (int i = 0; i < c; ++i) {
        if (one[i] == 1){
            if (i == 0) {
                p++;
            } else if (one[i-1] == 0) {
                p++;
            }
            if (i == c-1) {
                p++;
            } else if (one[i+1] == 0) {
                p++;
            }
            if (!isPair(i)) {
                p++;
            } else if (tow[i] == 0) {
                p++;
            }
        }
        if (tow[i] == 1){
            if (i == 0) {
                p++;
            } else if (tow[i-1] == 0) {
                p++;
            }
            if (i == c-1) {
                p++;
            } else if (tow[i+1] == 0) {
                p++;
            }
            if (!isPair(i)) {
                p++;
            } else if (one[i] == 0) {
                p++;
            }
        }
    }

    cout << p << endl;

}