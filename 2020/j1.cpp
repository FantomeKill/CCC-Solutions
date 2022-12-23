//
// Created by trist on 2022-12-05.
//

#include <stdio.h>

int main(int argc, char *argv[])
{
    int s;
    int m;
    int l;
    scanf("%d",&s);
    scanf("%d",&m);
    scanf("%d",&l);
    int f = ((1 * s) + (2 * m) + (3 * l));
    if (f >= 10){
        printf("happy");
    } else {
        printf("sad");
    }
    return 0;
}