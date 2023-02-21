//
// Created by trist on 2023-02-18.
//

#include <bits/stdc++.h>

using namespace std;

char tab[102][102];
string word;
int numCnt = 0;
int h,w;

void check(int r, int c, int index, int line, int cr, int cc){
    cout << r << " " << c << " " << index << " " << word[index] << " " << tab[r][c] << " " << line << " " << tab[r+cr][c+cc] << " " << cr << " " << cc << endl;
    if (index == word.length()-1) {
        numCnt++;
        cout << "numCnt: " << numCnt << endl;
    }

    // if line == 1, then we can only move in the same row or column
    // if line == 2, then we can only move in the same diagonal
    // if line == 0, then we can move in any direction

    if (line == 1) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue; // skip the current cell
                int nr = r + dr;
                int nc = c + dc;
                if (tab[nr][nc] == word[index+1]) {
                    if (dr == 0 || dc == 0) {
                        if (dr != cr && dc != cc) {
                            cout << "-";
                            check(nr, nc, index + 1, 1, dr, dc);
                        }
                    }
                }
            }
        }
    } else if (line == 2) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue; // skip the current cell
                int nr = r + dr;
                int nc = c + dc;
                if (tab[nr][nc] == word[index+1]) {
                    if (dr != 0 && dc != 0) {
                        if ( dr != cr && dc != cc) {
                            cout << "-";
                            check(nr, nc, index + 1, 2, dr, dc);
                        }
                    }
                }
            }
        }
    }

    int nr = r+ cr, nc = c + cc;
    if (nr >= 1 && nr <= h && nc >= 1 && nc <= w && tab[nr][nc] == word[index+1]) {
        if (cr == 0 || cc == 0) {
            check(nr,nc,index+1,1, cr, cc);
        } else {
            check(nr,nc,index+1,2, cr, cc);
        }
    }
}

int main(){
    //fast io
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> word >> h >> w;
    for(int i = 1; i < h+1; i++){
        for(int j = 1; j < w+1; j++){
            cin >> tab[i][j];
        }
    }

//    //print the table
//    for(int i = 1; i < h+1; i++){
//        for(int j = 1; j < w+1; j++){
//            cout << tab[i][j] << " ";
//        }
//        cout << endl;
//    }

    for(int i = 1; i < h+1; i++){
        for(int j = 1; j < w+1; j++){
            if(tab[i][j] == word[0]){
                check(i,j,0,0, -1, -1);
                cout << "----------------" << endl;
                check(i,j,0,0, -1, 0);
                cout << "----------------" << endl;
                check(i,j,0,0, -1, 1);
                cout << "----------------" << endl;
                check(i,j,0,0, 0, 1);
                cout << "----------------" << endl;
                check(i,j,0,0, 1, 1);
                cout << "----------------" << endl;
                check(i,j,0,0, 1, 0);
                cout << "----------------" << endl;
                check(i,j,0,0, 1, -1);
                cout << "----------------" << endl;
                check(i,j,0,0, 0, -1);
                cout << "---------end-------" << endl;
//                check(i,j,0,0);
            }
        }
    }

    cout << numCnt << endl;
}