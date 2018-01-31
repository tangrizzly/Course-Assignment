//
//  AlgorithmLab3.c
//  Requirements:
//    m people pick n toys with no repeatitions and each of toys shares the value
//    with v1, v2,..., vn (m<=n<=1000, 0<=vi<=1000). When a person picks a toy,
//    he/she does not want others to get more then he/she does. Thus we need to
//    split toys to n groups with the smallest price difference.
//  input: n, m
//  output: price difference
//
//  Created by Tangrizzly on 16/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//buble sort
int split(int n, int m, int v[]) {
    int g[m], i, j, k, d=0, flag;
    for (i=0; i<m; i++){
        g[i] = 0;
    }
    for (j=n-1; j>=0; j--) {
        for (i=0; i<j; i++) {
            if (v[i] > v[i+1]) {
                swap(&v[i], &v[i+1]);
            }
        }
        for (k=0, flag=0; k<m; k++) {
            if (g[flag]>g[k]) {
                flag = k;
            }
        }
        g[flag] += v[j];
    }
    for (i=0; i<m-1; i++){
        d += abs(g[i+1]-g[i]);
    }
    return d;
}

int main() {
    int n, m;
    int v[1000];
    printf("please input testing data (m<=n<=1000, 0<=vi<=1000):\n");
    scanf("%d %d", &n, &m);
    if (n>1000||m>n) {
        printf("Wrong number. Please retry.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    printf("the smallest price difference is:%d\n", split(n, m, v));
    return 0;
}
