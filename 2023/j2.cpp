//
// Created by cyber-toxo on 2/15/23.
//

#include <iostream>

using namespace std;
int main() {
    int a,numb;
    a = 0;
    cin >> numb;
    for (int i = 0; i < numb; ++i) {
        string tmp;
        cin >> tmp;
        if (tmp == "Poblano") a += 1500;
        if (tmp == "Mirasol") a += 6000;
        if (tmp == "Serrano") a += 15500;
        if (tmp == "Cayenne") a += 40000;
        if (tmp == "Thai") a += 75000;
        if (tmp == "Habanero") a += 125000;
    }
    cout << a;
    return 0;
}