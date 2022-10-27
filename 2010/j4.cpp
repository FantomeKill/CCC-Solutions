//
// Created by trist on 2022-10-18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
    int n, v;
    while (true) {
        vector<int> current; vector<int> diff;
        cin >> n;
        if (n == 0) {break;}
        if (n==1) {cin >> v; cout << 0 << endl;} else {
            doH(n){cin >> v; current.pb(v);}
            doH(n-1) {diff.pb(current[i+1] - current[i]);}
            for (int i = 1; i <= diff.size(); i++) {
                int current = 0; bool works = true;
                for (int j = 0; j < diff.size(); j++) {
                    if (diff[current] != diff[j]) {works = false; break;}
                    current++; current = current % i;
                }
                if (works) {cout << i << endl; break;}
            }
        }
    }
    return 0;
}

