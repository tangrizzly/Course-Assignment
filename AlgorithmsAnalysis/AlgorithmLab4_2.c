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
#include "math.h"

int route(int n, int m, int a[100][100]) {
    int i, j, k;
    int r[n+m-1][n][m];//record rewards
    int t[n+m-2][n][m];//record tracks
    for (i=0; i<n+m; i++) {
        for (j=0; j<n; j++) {
            for (k=0; k<m; k++) {
                r[i][j][k]=0;
                t[i][j][k]=0;
            }
        }
    }
    r[n+m-2][0][0] = a[0][0];
    for (i=n+m-3; i>=0; i--) {
        for (j=(0>=n-2-i?0:n-2-i); j<=n+m-2-i&&j<n; j++) {
            for (k=(0>=n-2-i?0:n-2-i); k<=n+m-2-i&&k<n; k++) {
                // both go right
                if (j>=n-1-i && k>=n-1-i &&
                    r[i][j][k] <= r[i+1][j][k]+a[j][n+m-2-i-j]+(j==k?0:a[k][n+m-2-i-k])) {
                    r[i][j][k] = r[i+1][j][k]+a[j][n+m-2-i-j]+(j==k?0:a[k][n+m-2-i-k]);
                    t[i][j][k] = 1;// record 'both go right' as 1
                }
                // one go right, one go down
                if (j>=n-1-i && k+1<n &&
                    r[i][j][k+1] <= r[i+1][j][k]+a[j][n+m-2-i-j]+(j==k+1?0:a[k+1][n+m-3-i-k])) {
                    r[i][j][k+1] = r[i+1][j][k]+a[j][n+m-2-i-j]+(j==k+1?0:a[k+1][n+m-3-i-k]);
                    t[i][j][k+1] = 2;// record 'one go right, one go down' as 2
                }
                // one go down, one go right
                if (k>=n-1-i && j+1<n &&
                    r[i][j+1][k] <= r[i+1][j][k]+a[j+1][n+m-3-i-j]+(j+1==k?0:a[k][n+m-2-i-k])) {
                    r[i][j+1][k] = r[i+1][j][k]+a[j+1][n+m-3-i-j]+(j+1==k?0:a[k][n+m-2-i-k]);
                    t[i][j+1][k] = 3;// record 'one go down, one go right' as 3
                }
                // both go down
                if (j+1<=n && k+1<n &&
                    r[i][j+1][k+1] <= r[i+1][j][k]+a[j+1][n+m-3-i-j]+(j+1==k+1?0:a[k+1][n+m-3-i-k])) {
                    r[i][j+1][k+1] = r[i+1][j][k]+a[j+1][n+m-3-i-j]+(j+1==k+1?0:a[k+1][n+m-3-i-k]);
                    t[i][j+1][k+1] = 4;// record 'both go down' as 4
                }
                // r[i][j][k] = max(r[i][j][k], r[i+1][j][k]+a[j][n+m-2-i-j]+(j==k?0:a[k][n+m-2-i-k]))
                // r[i][j][k+1] = max(r[i][j][k+1], r[i+1][j][k]+a[j][n+m-2-i-j]+(j==k+1?0:a[k+1][n+m-3-i-k]))
                // r[i][j+1][k] = max(r[i][j+1][k], r[i+1][j][k]+a[j+1][n+m-3-i-j]+(j+1==k?0:a[k][n+m-2-i-k]))
                // r[i][j+1][k+1] = max(r[i][j+1][k+1], r[i+1][j][k]+a[j+1][n+m-3-i-j]+(j+1==k+1?0:a[k+1][n+m-3-i-k]))
            }
        }
    }
    // 倒推路径
    //    for (int i=0; i<n+m-2; i++) {
    //        for (int j=0; j<n; j++) {
    //            for (int k=0; k<m; k++) {
    //                printf("%d\t", t[i][j][k]);
    //            }
    //            printf("\n");
    //        }
    //        printf("\n\n");
    //    }
    //    for (int i=0; i<n+m-2; i++) {
    //        for (int j=0; j<n; j++) {
    //            for (int k=0; k<m; k++) {
    //                printf("%d\t", r[i][j][k]);
    //            }
    //            printf("\n");
    //        }
    //        printf("\n\n");
    //    }
    int r1[n+m-1], r2[n+m-1];
    j = n-1;
    k = n-1;
    for (i = 0; i < n+m-2; i++) {
        r1[i] = j;
        r2[i] = k;
        switch (t[i][j][k]) {
            case 1:
                break;
            case 2: {
                k--;
                break;
            }
            case 3:
                j--;
                break;
            case 4: {
                j--;
                k--;
                break;
            }
            default: {
                printf("wrong.");
                break;
            }
        }
    }
    printf("(0, 0)->");
    for (i = n+m-3; i >= 0; i--) {
        printf("(%d, %d)->", r1[i], n+m-2-i-r1[i]);
    }
    for (i = 1; i < n+m-2; i++) {
        printf("(%d, %d)->", r2[i], n+m-2-i-r2[i]);
    }
    printf("(0, 0).\n");
    
    return r[0][n-1][m-1];
}

int main() {
    int n, m;
    int a[100][100]={0};
    printf("please input testing data(0<n<100, 0<m<100):\n");
    scanf("%d %d", &n, &m);
    if (n>=100||m>=100||n<=0||m<=0) {
        printf("Wrong number. Please retry.\n");
        return 1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int reward = route(n, m, a);
    printf("whole reward is: %d\n", reward);
    return 0;
}

