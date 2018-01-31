//
//  lab4_2.cpp
//  lab4_2
//
//  Created by Tangrizzly on 04/12/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
private:
    int x, y;
    int array[20][20];
public:
    Array2() = default;
    Array2(int m, int n):x(m),y(n) {}
    Array2 & operator = (Array2 const &a);
    int * operator[] (int i) {return array[i];}
    int & operator() (int i, int j) {return array[i][j];}
};

Array2 &Array2::operator = (Array2 const &a) {
    x = a.x;
    y = a.y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            array[i][j] = a.array[i][j];
        }
    }
    return *this;
}

int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
