//
// Created by trist on 2023-08-24.
//

#include <iostream>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++) {
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int verif = a[0]+a[n];


    return 0;
}