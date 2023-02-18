//
// Created by cyber-toxo on 2/15/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,one,tow,tree,four,five;
    one = tow = tree = four = five = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        if (tmp[0]=='Y') one++;
        if (tmp[1]=='Y') tow++;
        if (tmp[2]=='Y') tree++;
        if (tmp[3]=='Y') four++;
        if (tmp[4]=='Y') five++;
    }
    int max = one;
    if (tow > max) max = tow;
    if (tree > max) max = tree;
    if (four > max) max = four;
    if (five > max) max = five;
    int cnt = 0;
    if (one == max) {
        cout << 1;
        cnt++;
    }
    if (tow == max) {
        if (cnt > 0) cout << ",";
        cout << 2;
        cnt++;
    }
    if (tree == max) {
        if (cnt > 0) cout << ",";
        cout << 3;
        cnt++;
    }
    if (four == max) {
        if (cnt > 0) cout << ",";
        cout << 4;
        cnt++;
    }
    if (five == max) {
        if (cnt > 0) cout << ",";
        cout << 5;
        cnt++;
    }
    return 0;
}