//
// Created by trist on 2022-10-18.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> value;
    std::cin >> n;
    if (n <= 10 || n >=1) {
        for (int i = 1; i < n + 1; i++) {
            // verify if n-i is not in the vector without using std::find
            bool is_in_vector = false;
            for (auto &it : value) {
                if (it == n - i) {
                    is_in_vector = true;
                    break;
                }
            }
            if (!is_in_vector && n - i <= 5 && i <= 5) {
                if (n - i > 0 || n - i <= 5) {
                    value.push_back(i);
                }
            }
        }
    }
    std::cout << value.size() << std::endl;
    return 0;
}