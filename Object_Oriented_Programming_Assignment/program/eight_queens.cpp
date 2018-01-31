//
//  homework2_1.cpp
//  homework2_1
//
//  Created by Tangrizzly on 25/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
using namespace std;

int num = 0;
class queen {
private:
    int row;
    int column;
public:
    queen() {row = -1; column = -1;}
    void setqueen(int x, int y) {row = x; column = y;}
    int getcolumn() {return column;}
    int checkqueen(queen q[8]);
};

int queen::checkqueen(queen q[8]) {
    if (row == 0) return 1;
    for (int k = 0; k <= row-1; k++) {
        //纵向只能有一枚皇后
        if (q[k].column == column) {
            return 0;
        }
        //右上至左下只能有一枚皇后
        if (q[k].row + q[k].column == row + column) {
            return 0;
        }
        //从左上至右下只能有一枚皇后
        if (q[k].row - q[k].column == row - column) {
            return 0;
        }
    }
    return 1;
}

void output(queen q[8]) {
    num++;
    cout<<"answer "<<num<<":\n";
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++)
            if (q[i].getcolumn() == j) {
                cout<<"1 ";
            } else {
                cout<<"0 ";
            }
        cout<<endl;
    }
}

void solve(queen q[8], int i) {
    int j;
    for (j=0;j<8;j++)
    {
        //在其中一列放置皇后
        q[i].setqueen(i, j);
        //检查在该列放置皇后是否可行
        if (q[i].checkqueen(q)) {
            //若该列可放置皇后，且该列为最后一列，则找到一可行解，输出
            if(i == 7) output(q);
            //若该列可放置皇后，则向下一行，继续搜索、求解
            else solve(q, i+1);
        }
    }
}



int main(){
    queen q[8];
    solve(q, 0);
    return 0;
}
