//
// Created by trist on 2023-02-17.
//

#include <iostream>

int main() {
    int a;
    std::string b, c;
    std::cin >> a >> b >> c;
    int f = 0;
    for (int i = 0; i < a; i++) {
        if (b[i] == c[i] && b[i] == 'C') {
            f++;
        }
    }
    std::cout << f;
    return 0;
}