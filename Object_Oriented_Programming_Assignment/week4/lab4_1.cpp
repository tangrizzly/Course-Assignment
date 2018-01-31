//
//  lab4_1.cpp
//  lab4_1
//
//  Created by Tangrizzly on 04/12/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex &operator = (char *s);   //类型转换构造函数
};

Complex &Complex::operator = (char *s) {
    r = 0;
    i = 0;
    int j = 0;
    for (; *(s+j)!='+'; j++) {
        r = r*10 + *(s+j) - '0';
    }
    j++;
    for (; *(s+j)!='i'; j++) {
        i = i*10 + *(s+j) - '0';
    }
    return *this;
}

int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
