//
// Created by trist on 2022-12-23.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string t, s;
    cin >> t >> s;

    bool bol = false;
    for (int i = 0; i < s.length(); i++) {
        string car = s.substr(i) + s.substr(0, i);
        if (t.find(car) != string::npos) {
            bol = true;
            continue;
        }
    }
    if (bol) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}