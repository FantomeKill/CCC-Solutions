#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;

int n, m, option;
vector<int> graph[MAXN];
bool visited[MAXN];
int times[MAXN];
int minpages = MAXN;

int main() {
    cin >> n;
    vector<int> endings;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> option;
            graph[i].push_back(option);
        }
        if (m == 0) {
            endings.push_back(i);
        }
    }

    deque<int> q;
    q.push_back(1);
    visited[1] = true;
    times[1] = 0;
    int c = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (int adj : graph[cur]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push_back(adj);
                times[adj] = times[cur] + 1;
                c++;
            }
        }
        if (find(endings.begin(), endings.end(), cur) != endings.end()) {
            minpages = min(minpages, times[cur] + 1);
        }
    }

    if (c == n) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    cout << minpages << "\n";

    return 0;
}
