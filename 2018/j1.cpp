#include <iostream>

using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a >= 8 && d >= 8 && b == c) {
        cout << "ignore" << endl;
    } else {
        cout << "answer" << endl;
    }
    return 0;
}