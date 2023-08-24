//
// Created by trist on 2023-08-24.
//

#include <iostream>

int get10s(int n){
    return n/10;
}

int getUnits(int n){
    return n % 10;
}

bool isHourAritmetic(int h, int min){
    int h2 = getUnits(h);
    int min1 = get10s(min);
    int hmindiff = min1-h2;
    if (hmindiff>5) return false;
    int min2 = getUnits(min);
    int mindiff = min2-min1;
    if (mindiff>5) return false;
    int h1 = get10s(h);
    int hdiff = h2-h1;
    if (hdiff>5 && h1!=0) return false;
    return (mindiff==hmindiff && (h1==0 || hdiff==hmindiff));
}

int main(){
    int m;
    std::cin >> m;
    int rep = m/720;
    m = m%720;
    int h=12, min=0, s=0;
    while(m-->0){
        min++;
        if(min==60){
            min=0;
            h++;
        }
        if(h==13){
            h=1;
        }
        if (isHourAritmetic(h, min)) s++;
    }
    s+=rep*31;
    std::cout << s << std::endl;
    return 0;
}