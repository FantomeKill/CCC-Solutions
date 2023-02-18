//
// Created by cyber-toxo on 2/15/23.
//

#include <bits/stdc++.h>

using namespace std;
int he;
int we;
int cnt = 0;
int visited[100][100];

void check(vector<vector<char>> tab, string word, int wp, int pi, int pj, int idk) {
    visited[pi][pj] = 1;
    // // cout << "wp: " << wp << " pi: " << pi << " pj: " << pj << " idk: " << idk << endl;
    // // cout << "wp char :" << word[wp] << " tab char: " << tab[pi][pj] << endl;
    if (wp == word.length() - 1) {
        cnt++;
        // // cout << "cnt: " << cnt << endl;
        return;
    }

    if (idk == 1 || idk == 0) {
        if (pi + 1 < he && tab[pi + 1][pj] == word[wp + 1] && visited[pi + 1][pj] == 0) {
            check(tab, word, wp + 1, pi + 1, pj, 1);
        }
        if (pi - 1 >= 0 && tab[pi - 1][pj] == word[wp + 1] && visited[pi - 1][pj] == 0) {
            check(tab, word, wp + 1, pi - 1, pj, 1);
        }
        if (pj + 1 < we && tab[pi][pj + 1] == word[wp + 1] && visited[pi][pj + 1] == 0) {
            check(tab, word, wp + 1, pi, pj + 1, 1);
        }
        if (pj - 1 >= 0 && tab[pi][pj - 1] == word[wp + 1] && visited[pi][pj - 1] == 0) {
            check(tab, word, wp + 1, pi, pj - 1, 1);
        }
        if (pi + 1 < he && pj + 1 < we && tab[pi + 1][pj + 1] == word[wp + 1] && visited[pi + 1][pj + 1] == 0) {
            check(tab, word, wp + 1, pi + 1, pj + 1, 1);
        }
        if (pi - 1 >= 0 && pj - 1 >= 0 && tab[pi - 1][pj - 1] == word[wp + 1] && visited[pi - 1][pj - 1] == 0) {
            check(tab, word, wp + 1, pi - 1, pj - 1, 1);
        }
        if (pi + 1 < he && pj - 1 >= 0 && tab[pi + 1][pj - 1] == word[wp + 1] && visited[pi + 1][pj - 1] == 0) {
            check(tab, word, wp + 1, pi + 1, pj - 1, 1);
        }
        if (pi - 1 >= 0 && pj + 1 < we && tab[pi - 1][pj + 1] == word[wp + 1] && visited[pi - 1][pj + 1] == 0) {
            check(tab, word, wp + 1, pi - 1, pj + 1, 1);
        }
    }

    if (idk == 2 || idk == 0) {
        if (pi + 1 < he && pj + 2 < we && tab[pi + 1][pj + 2] == word[wp + 1] && visited[pi + 1][pj + 2] == 0) {
            check(tab, word, wp + 1, pi + 1, pj + 2, 2);
        }
        if (pi - 1 >= 0 && pj - 2 >= 0 && tab[pi - 1][pj - 2] == word[wp + 1] && visited[pi - 1][pj - 2] == 0) {
            check(tab, word, wp + 1, pi - 1, pj - 2, 2);
        }
        if (pi + 1 < he && pj - 2 >= 0 && tab[pi + 1][pj - 2] == word[wp + 1] && visited[pi + 1][pj - 2] == 0) {
            check(tab, word, wp + 1, pi + 1, pj - 2, 2);
        }
        if (pi - 1 >= 0 && pj + 2 < we && tab[pi - 1][pj + 2] == word[wp + 1] && visited[pi - 1][pj + 2] == 0) {
            check(tab, word, wp + 1, pi - 1, pj + 2, 2);
        }
        if (pi + 2 < he && pj + 1 < we && tab[pi + 2][pj + 1] == word[wp + 1] && visited[pi + 2][pj + 1] == 0) {
            check(tab, word, wp + 1, pi + 2, pj + 1, 2);
        }
        if (pi - 2 >= 0 && pj - 1 >= 0 && tab[pi - 2][pj - 1] == word[wp + 1] && visited[pi - 2][pj - 1] == 0) {
            check(tab, word, wp + 1, pi - 2, pj - 1, 2);
        }
        if (pi + 2 < he && pj - 1 >= 0 && tab[pi + 2][pj - 1] == word[wp + 1] && visited[pi + 2][pj - 1] == 0) {
            check(tab, word, wp + 1, pi + 2, pj - 1, 2);
        }
        if (pi - 2 >= 0 && pj + 1 < we && tab[pi - 2][pj + 1] == word[wp + 1] && visited[pi - 2][pj + 1] == 0) {
            check(tab, word, wp + 1, pi - 2, pj + 1, 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string word;
    cin >> word;
    cin >> he >> we;
    vector<vector<char>> tab;
    for (int i = 0; i < he; ++i) {
        vector<char> tmps;
        for (int j = 0; j < we; ++j) {
            char tmp;
            cin >> tmp;
            tmps.push_back(tmp);
        }
        tab.push_back(tmps);
    }

    for (int i = 0; i < he; ++i) {
        for (int j = 0; j < we; ++j) {
            if (tab[i][j] == word[0]) {
                check(tab, word, 0, i, j, 0);
            }
        }
    }
    cout << cnt;
    return 0;
}