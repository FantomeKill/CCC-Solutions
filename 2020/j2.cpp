//
// Created by trist on 2022-12-23.
//

#include <stdio.h>

int main(int argc, char *argv[])
{
    int p;
    int n;
    int r;
    int nbp;
    scanf("%d",&p);
    scanf("%d",&n);
    scanf("%d",&r);
    int nb = n;
    for (int i = 1; i <= p; ++i) {
        nbp = n * r;
        nb = nb + nbp;
        if (nb > p){
            printf("%d", i);
            return 0;
        }
        n = nbp;
    }
    return 0;
}