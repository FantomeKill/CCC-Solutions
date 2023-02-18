//
// Created by cyber-toxo on 2/15/23.
//

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) {
        std::cout << a*50-b*10+500 << std::endl;
    } else {
        std::cout << a * 50 - b * 10 << std::endl;
    }

    return 0;
}