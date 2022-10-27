//
// Created by trist on 2022-10-17.
//

#include <iostream>

//function to check if a number is odd or even
int isEven(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int a, b, c, d, s, by = 0,ni = 0, byt = 0,nit = 0,t=1;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> s;

    while (byt < s){
        if (!isEven(t)){
            if (byt + c <= s) {
                byt += c;
                by += c;
            } else {
                by += s - byt;
                byt = s;
            }
            t++;
        } else{
            if (byt + d <= s) {
                byt += d;
                by -= d;
            } else {
                by -= s - byt;
                byt = s;
            }
            t++;
        }
//        std::cout << by << std::endl;
    }
    t=1;
    while (nit < s){
        if (!isEven(t)){
            if (nit + a <= s) {
                nit += a;
                ni += a;
            } else {
                ni += s - nit;
                nit = s;
            }
            t++;
        } else{
            if (nit + b <= s) {
                nit += b;
                ni -= b;
            } else {
                ni -= s - nit;
                nit = s;
            }
            t++;
        }
//        std::cout << ni << std::endl;
    }

    if (by > ni){
        std::cout << "Byron";
    } else if (by < ni){
        std::cout << "Nikky";
    } else{
        std::cout << "Tied";
    }
//    std::cout << by << std::endl << ni << std::endl;
    return 0;
}