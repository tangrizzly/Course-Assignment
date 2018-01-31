//
//  main.cpp
//  lab1_4
//  four people count numbers. each of them says a words and three of them are true. find who says the number one.
//  A:not me. B: is C. C: is B. D: he is lying.
//  Created by Tangrizzly on 15/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//  a=0,b=0,c=1

#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0, c = 0;
    int i=1;
    for (a=0; a<2&&i; a++) {
        for (b=0; b<2&&i; b++) {
            for (c=0; c<2&&i; c++) {
                if((!a)+(c)+(b)+(!b)==3 && a+b+c<=1)
                    i=0;
            }
        }
    }
    if (a==2)
        printf("A\n");
    else if (b==2)
        printf("B\n");
    else if (c==2)
        printf("C\n");
    else printf("D\n");
    return 0;
}
