//
//  AlgorithmLab2.c
//  Requirements:
//    Bag proble:
//      Given bag volume and the price and volume of n products (product cannot
//      be splited), computing the maximum value of the products the bag can hold.
//
//  Created by Tangrizzly on 16/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include "stdio.h"
#define max(a,b) ((a)>(b))?(a):(b)

int getMaximumValue(int n, int w, int weight[], int value[]) {
    int Vm[w+1];
    for (int i=0; i < w+1; i++) {
        Vm[i]=0;
    }
    for (int i = 0; i < n; i++) {
        for (int j=w; j>=weight[i]; j--) {
            Vm[j] = max(Vm[j], Vm[j-weight[i]]+value[i]);
        }
    }
    return Vm[w];
}

int main() {
    int n, w, M[100];
    int i, j;
    int weight[1001]={0}, value[1001]={0};
    printf("Please input n, w (0 <= n <= 1000 && 0 <= w <= 5000): \n");
    scanf("%d %d", &n, &w);
    for (i = 0; n!=-1; ++i) {
        if (n<0||n>1000||w<0||w>5000) {
            printf("Overflowing, please retry.");
            continue;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &value[i]);
            if (value[i]<0||value[i]>1000) {
                i--;
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &weight[i]);
            if (weight[i]<0||weight[i]>w) {
                i--;
            }
        }
        M[i] = getMaximumValue(n, w, weight, value);
        printf("Please input n, w (0 <= n <= 1000 && 0 <= w <= 5000): \n");
        scanf("%d %d", &n, &w);
    }
    printf("Maximum values:\n");
    for (j = 0; j < i; ++j)
    {
        printf("%d\n", M[j]);
    }
    return 0;
}
