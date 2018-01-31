//
//  lab5_1.cpp
//  lab5_1
//
//  Created by Tangrizzly on 08/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class CShape {
public:
    virtual double circumference() = 0;
    virtual double Area() = 0;
    virtual void PrintfInfo() = 0;
};
class CRectangle:public CShape {
public:
    int w, h;
    virtual double Circumference();
    virtual double Area();
    virtual void PrintfInfo();
};
class CRoundRectangle:public CRectangle {
public:
    int r;
    virtual double Circumference();
    virtual double Area();
    virtual void PrintfInfo();
};
double CRectangle::Area() {
    return w * h;
}
double CRectangle::Circumference() {
    return 2 * (w + h);
}
void CRectangle::PrintfInfo() {
    cout << "Rectangle Area: " << Area() << ", Circumference: " << Circumference() << endl;
}
double CRoundRectangle::Area() {
    return w * h + (w + h) * r * 2 + 3.1415926 * r * r;
}
double CRoundRectangle::Circumference() {
    return 2 * (w + h) + 2 * 3.1415926 * r;
}
void CRoundRectangle::PrintfInfo() {
    cout << "CRoundRectangle Area: " << Area() << ", Circumference: " << Circumference() << endl;
}
设计测试函数test，观察函数对不同的类对象矩形（a＝500，b＝300）与圆角矩形（a＝500，b＝300，r＝50）
int main() {
    CRectangle cr;
    CRoundRectangle crr;
    CShape *test;
    test = &cr;
    test->PrintfInfo();
    test = &crr;
    test->PrintfInfo();
    return 0;
}
