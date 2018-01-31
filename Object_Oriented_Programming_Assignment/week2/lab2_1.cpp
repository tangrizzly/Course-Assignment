//
//  main.cpp
//  lab2_1
//
//  Created by Tangrizzly on 20/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include<iostream>
#include<math.h>
using namespace std;

class CRectangle{
private:
    int x, y; //coordinates of the lower left corner
    int a, b; //the length on x, and the length on y
    int perimeter;
    int square;
    int distance;
public:
    friend void getDistance(CRectangle &);
    CRectangle(int x, int y, int a, int b);
    ~CRectangle(){cout << "Deleting a class CRectangle." << endl;}
    void changeCoordinates(int x, int y){this->x = x; this->y= y;}
    void changeLength(int a, int b){this->a = a; this->b = b;}
    void outputAttributes();
    void outputPmAndSq();
};

CRectangle::CRectangle(int x, int y, int a, int b){
    cout << "Creating a class CRectangle." << endl;
    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
}

void CRectangle::outputAttributes(){
    cout << "x=" << x << ", y=" << y << endl;
    cout << "a=" << a << ", b=" << b << endl;
}

void CRectangle::outputPmAndSq(){
    perimeter = 2*a + 2*b;
    square = a*b;
    cout << "Perimeter=" << perimeter << endl;
    cout << "Square=" << square << endl;
}

void getDistance(CRectangle & rect){
    rect.distance = sqrt((double)((rect.x+rect.a/2)^2+(rect.y+rect.b/2)^2));
    cout << "Distance=" << rect.distance << endl;
}

int main() {
    CRectangle *rect = new CRectangle(100, 50, 1200, 700);
    rect->changeCoordinates(100, 50);
    rect->changeLength(1200, 700);
    rect->outputAttributes();
    rect->outputPmAndSq();
    getDistance(*rect);
    delete rect;
    return 0;
}
