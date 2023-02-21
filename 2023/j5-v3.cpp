//
// Created by trist on 2023-02-20.
//

#include <bits/stdc++.h>

using namespace std;

char a[100][100];
string s;
int numCnt = 0;
int h,w;

void dfs(int d, int x, int y, int dx, int dy, bool t) {
    if (x < 0 || x >= h || y < 0 || y >= w) return;
    if (a[x][y] != s[d]) return;
    if (d == s.size() - 1) {
        numCnt++;
        return;
    }

    dfs(d + 1, x + dx, y + dy, dx, dy, t);
    if (t || d < 1) return;
    dfs(d + 1, x - dy, y + dx, -dy, dx, true);
    dfs(d + 1, x + dy, y - dx, dy, -dx, true);
}

int main(){
    //fast io
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == s[0]) {
                dfs(0, i, j, -1, -1, false);
                dfs(0, i, j, -1, 0, false);
                dfs(0, i, j, -1, 1, false);
                dfs(0, i, j, 0, -1, false);
                dfs(0, i, j, 0, 1, false);
                dfs(0, i, j, 1, -1, false);
                dfs(0, i, j, 1, 0, false);
                dfs(0, i, j, 1, 1, false);
            }
        }
    }

    cout << numCnt << endl;
}