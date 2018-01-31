//
//  AlgorithmLab4.c
//  Dynamic Programming
//
//  Requirements:
//    N*M matrix. Alice is on (1, 1) and the end point is (N, M). Every point
//    has a reward when Alice first get there. First, Alice can only go down
//    or right to get to the end point. And then, she can go up or left to get
//    back to (1, 1). When finish this process, how much reward can she get?
//  input: N, M, N*M matrix
//  output: (1, 1)->...->(N, M)->...->(1, 1)
//
//  Created by Tangrizzly on 16/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
// 

#include "stdio.h"

int downroute(int n, int m, int a[100][100]) {
    int i, j;
    int r[100][100]={0}; //记录最大奖励值
    int k[100][100]={0}; //记录路径
    int c[m+n-2][2];
    for (i=2; i<=n+m; i++) {
        for (j=(i<=n+1?1:i-n); i-j>=1&&j<=n; j++) {
            if (r[j-1][i-j]>r[j][i-j-1]) { //左边大于上边
                r[j][i-j] = r[j-1][i-j] + a[j][i-j];
                k[j][i-j] = 1;
            } else { //上边大于左边
                r[j][i-j] = r[j][i-j-1] + a[j][i-j];
                k[j][i-j] = 0;
            }
        }
    }
    int down = r[n][m];
    for (i=n, j=m; i>1||j>1;) { //倒推路径
        a[i][j]=0;
        c[i+j-3][0] = i;
        c[i+j-3][1] = j;
        if (k[i][j]) { //向左
            i -= 1;
        } else { //向上
            j -= 1;
        }
    }
    printf("start->(1, 1)->");
    for (i=0; i<m+n-2; i++) {
        printf("(%d, %d)->", c[i][0], c[i][1]);
    }
    return down;
}

int uproute(int n, int m, int a[100][100]) {
    int i, j;
    int r[100][100]={0}; //记录最大奖励值
    int k[100][100]={0}; //记录路径
    int c[m+n-2][2];
    for (i=n+m; i>=2; i--) {
        for (j=(i<=n+1?1:i-n); i-j>=1&&j<=n; j++) {
            if (r[j+1][i-j]>r[j][i-j+1]) { //下边大于右边
                r[j][i-j] = r[j+1][i-j] + a[j][i-j];
                k[j][i-j] = 1;
            } else { //右边大于下边
                r[j][i-j] = r[j][i-j+1] + a[j][i-j];
                k[j][i-j] = 0;
            }
        }
    }
    int up = r[1][1];
    for (i=1, j=1; i<=n&&j<=m;) { //倒推路径
        a[i][j]=0;
        c[i+j-2][0] = i;
        c[i+j-2][1] = j;
        if (k[i][j]) { //向下
            i += 1;
        } else { //向右
            j += 1;
        }
    }
    for (i=m+n-3; i>=0; i--) {
        printf("(%d, %d)->", c[i][0], c[i][1]);
    }
    printf("end\n");
    return up;
}

int main() {
    int n, m;
    int a[100][100]={0};
    printf("please input testing data(0<m<100, 0<n<100):\n");
    scanf("%d %d", &n, &m);
    if (n>=100||m>=100||n<=0||m<=0) {
        printf("Wrong number. Please retry.\n");
        return 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int down = downroute(n, m, a);
    int up = uproute(n, m, a);
    printf("whole reward is: %d\n", down+up);
    return 0;
}
