//
// Created by trist on 2023-08-24.
//

#include <iostream>
#include <cmath>

int shift(int n, int k){
    int result = n;
    for(int i = 1; i <= k; i++){
        result += n * pow(10, i);
    }
    return result;
}

int main(){
    int n, k;
    std::cin >> n >> k;
    std::cout << shift(n, k);
    return 0;
}