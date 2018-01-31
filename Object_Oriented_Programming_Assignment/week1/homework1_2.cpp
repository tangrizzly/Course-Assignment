//
//  main.cpp
//  A dice game: a player rolls two dice, if the total is seven he/she wins;
//  otherwise he/she loses
//
//  Created by Tangrizzly on 15/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include<iostream>
using namespace std;

class Die{
    int faceValue;
    int roll() { return rand()%6+1; }
public:
    int getFaceValue() { faceValue = roll(); return faceValue; }
};

class Dicegame{
    Die die1, die2;
public:
    void play();
};

void Dicegame::play(){
    int n1 = die1.getFaceValue();
    int n2 = die2.getFaceValue();
    cout << "the number in the first roll: " << n1 << endl;
    cout << "the number in the second roll: " << n2 << endl;
    if (n1+n2 ==7) {
        cout << "the player wins." << endl;
    } else {
        cout << "the player loses." << endl;
    }
}

int main() {
    srand((unsigned)time(0));
    Dicegame dicegame;
    dicegame.play();
    return 0;
}

