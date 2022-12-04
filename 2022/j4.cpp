
//
// Created by trist on 2022-12-03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

int main(){
    //fast io
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y,g, v = 0;
    std::cin >> x;
    set<pair<string, string>> s;
    set<pair<string, string>> d;
    while (x--){
        string n1,n2;
        cin >> n1 >> n2;
        s.emplace(make_pair(n1,n2));
    }
    std::cin >> y;
    while (y--){
        string n1,n2;
        cin >> n1 >> n2;
        d.emplace(make_pair(n1,n2));
    }


    std::cin >> g;

    set<pair<string,string>> gs;

    while (g--){
        vector<string> group(3);
        for (int i = 0; i < 3; ++i) {
            cin >> group[i];
        }

        for (auto& name : s) {
//            cout << group[0] << " " << group[1] << " " << group[2] << endl;
            if (std::find(group.begin(), group.end(), name.first) != group.end()){
                if (std::find(group.begin(), group.end(), name.second) != group.end()){
                    //
                } else {
                    gs.emplace(name);
                }
            }
            if (std::find(group.begin(), group.end(), name.second) != group.end()){
                if (std::find(group.begin(), group.end(), name.first) != group.end()){
                    //
                } else {
                    gs.emplace(name);
                }
            }
        }

        for (auto& name : d) {
//            cout << group[0] << " " << group[1] << " " << group[2] << endl;
            if (std::find(group.begin(), group.end(), name.first) != group.end()){
                if (std::find(group.begin(), group.end(), name.second) != group.end()){
                    gs.emplace(name);
                } else {
                }
            }
        }
    }
    for (const auto &item: gs) {
        v++;
    }
    cout << v<< endl;
    return 0;
}