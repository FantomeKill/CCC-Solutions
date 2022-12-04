#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> names = { "Alices", "Bob", "Charlie", "David" };

    // Check if the vector contains the names "Alice" and "David"
    if (find(names.begin(), names.end(), "Alice") != names.end() &&
        find(names.begin(), names.end(), "David") != names.end()) {
        cout << "The vector contains both names" << endl;
    } else {
        cout << "The vector does not contain both names" << endl;
    }

    return 0;
}