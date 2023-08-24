//
// Created by trist on 2023-08-24.
//

#include <iostream>

int main(){
    int x1,y1, x2, y2, b;
    std::cin >> x1 >> y1 >> x2 >> y2 >> b;
    int x = std::max(x1, x2) - std::min(x1, x2);
    int y = std::max(y1, y2) - std::min(y1, y2);
    if (x+y==b)
        std::cout << "Y" << std::endl;
    else if (x+y<b && (b-x+y)%2==0)
        std::cout << "Y" << std::endl;
    else
        std::cout << "N" << std::endl;
    return 0;
}