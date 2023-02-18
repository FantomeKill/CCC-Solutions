//
// Created by trist on 2022-10-18.
//

#include <iostream>
#include <map>

int main() {
    int running = 1;
    std::map <char, int> variables;
    while (running) {
        char variable;
        char variable2;
        int value;
        int instruction;
        std::cin >> instruction;
        switch (instruction) {
            case 1:
                std::cin >> variable >> value;
                variables[variable] = value;
                break;
            case 2:
                std::cin >> variable;
                std::cout << variables[variable] << std::endl;
                break;
            case 3:
                std::cin >> variable >> variable2;
                variables[variable] += variables[variable2];
                break;
            case 4:
                std::cin >> variable >> variable2;
                variables[variable] *= variables[variable2];
                break;
            case 5:
                std::cin >> variable >> variable2;
                variables[variable] -= variables[variable2];
                break;
            case 6:
                std::cin >> variable >> variable2;
                variables[variable] /= variables[variable2];
                break;
            case 7:
                running = 0;
                break;
        }
    }
}