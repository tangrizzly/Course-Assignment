//
//  homework1_1.cpp
//  homework1_1
//
//  Created by Tangrizzly on 20/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int m[8][8] = {0};//表示棋盘，初始为0，表示未放置皇后
int num = 0;//解数目

//对于棋盘前row-1行已放置好皇后
//检查在第row行、第column列放置一枚皇后是否可行
int check(int row,int column)
{
    if(row==1) return 1;
    int i,j;
    //纵向只能有一枚皇后
    for(i=0;i<=row-2;i++)
    {
        if(m[i][column-1]==1) return 0;
    }
    //左上至右下只能有一枚皇后
    i = row-2;
    j = i-(row-column);
    while(i>=0&&j>=0)
    {
        if(m[i][j]==1) return 0;
        i--;
        j--;
    }
    //右上至左下只能有一枚皇后
    i = row-2;
    j = row+column-i-2;
    while(i>=0&&j<=7)
    {
        if(m[i][j]==1) return 0;
        i--;
        j++;
    }
    return 1;
}

//当已放置8枚皇后，为可行解时，输出棋盘
void output()
{
    int i,j;
    num++;
    printf("answer %d:\n",num);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++) printf("%d ",m[i][j]);
        printf("\n");
    }
}

//采用递归函数实现八皇后回溯算法
//该函数求解当棋盘前row-1行已放置好皇后，在第row行放置皇后
void solve(int row)
{
    int j;
    //考虑在第row行的各列放置皇后
    for (j=0;j<8;j++)
    {
        //在其中一列放置皇后
        m[row-1][j] = 1;
        //检查在该列放置皇后是否可行
        if (check(row,j+1)==1)
        {
            //若该列可放置皇后，且该列为最后一列，则找到一可行解，输出
            if(row==8) output();
            //若该列可放置皇后，则向下一行，继续搜索、求解
            else solve(row+1);
        }
        //取出该列的皇后，进行回溯，在其他列放置皇后
        m[row-1][j] = 0;
    }
}

//主函数
int main()
{
    //求解八皇后问题
    solve(1);
    return 0;
}
