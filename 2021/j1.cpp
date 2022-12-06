//
// Created by trist on 2022-12-05.
//

#include <iostream>

int main()
{
    int B;
    std::cin >> B; // read the temperature at which water begins to boil

    // compute atmospheric pressure
    int P = 5 * B - 400;
    std::cout << P << std::endl; // output atmospheric pressure

    // determine if you are below sea level, at sea level, or above sea level
    if (P > 100)
    {
        std::cout << -1 << std::endl;
    }
    else if (P == 100)
    {
        std::cout << 0 << std::endl;
    }
    else
    {
        std::cout << 1 << std::endl;
    }

    return 0;
}
