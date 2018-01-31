//
//  AlgorithmLab1.c
//  Requirements:
//    X = Y^Z mod D. Y and Z belongs to [0, 2147483647] and D belongs to [1, 46340]
//    Input several groups of testing data "Y, Z, D"
//    Output "X"
//
//  Created by Tangrizzly on 16/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include "stdio.h"

int count(int Y, int Z, int D) {
    if (Z == 1) {
        return Y % D;
    } else if (Z%2 == 0) {
        return count(Y, Z/2, D) * count(Y, Z/2, D) % D; // (Y*Y)^(Z/2) mod D
    } else {
        return (count(Y, Z/2, D) * count(Y, Z/2, D) % D) *(Y % D) % D;// (Y*Y)^(Z/2)*Y mod D
    }
}

int main() {
    int Y, Z, D;
    int i,j;
    int X[100];
    printf("Please input Y, Z, D (Y and Z belongs to [0, 2147483647] and D belongs to [1, 46340]), end with '0 0 0': \n");
    scanf("%d %d %d", &Y, &Z, &D);
    for (i = 0; Y; ++i) {
        X[i] = count(Y, Z, D);
        scanf("%d %d %d", &Y, &Z, &D);
    }
    printf("X:\n");
    for (j = 0; j < i; ++j)
    {
        printf("%d\n", X[j]);
    }
    return 0;
}

