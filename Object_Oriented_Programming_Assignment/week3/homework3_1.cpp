//
//  homework3_1.cpp
//  lab3_1
//
//  Created by Tangrizzly on 30/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
using namespace std;

enum warriortype {dragon=0, ninja, iceman, lion, wolf};
enum headquartertype {red=0, blue};

class warrior {
private:
    warriortype wtype;
    int number;
    int health;
    int attack;
public:
    void assignwarrior(warriortype w, int h) {wtype = w; health = h; number = 0;}
    void born() {number++;}
    int getnumber() {return number;}
    string gettype();
    int gethealth() {return health;}
};

string warrior::gettype() {
    switch (wtype) {
        case dragon:
            return "dragon";
        case ninja:
            return "ninja";
        case iceman:
            return "iceman";
        case lion:
            return "lion";
        case wolf:
            return "wolf";
        default:
            break;
    }
    return "wrong";
}

class headquarter {
private:
    headquartertype htype;
    warrior warriors[5];
    int life;
    int number;
    int time;
public:
    headquarter(headquartertype t, int h[5], int _life);
    void makingWarrior();
    int check();
    string gethtype() {
        if (htype == headquartertype::red) {
            return "red";
        } else {
            return "blue";
        }
    }
};

headquarter::headquarter(headquartertype t, int h[5], int _life) {
    htype = t;
    life = _life;
    number = 0;
    time = 0;
    if (t == red) {
        warriors[0].assignwarrior(iceman, h[2]);
        warriors[1].assignwarrior(lion, h[3]);
        warriors[2].assignwarrior(wolf, h[4]);
        warriors[3].assignwarrior(ninja, h[1]);
        warriors[4].assignwarrior(dragon, h[0]);
    } else {
        warriors[0].assignwarrior(lion, h[3]);
        warriors[1].assignwarrior(dragon, h[0]);
        warriors[2].assignwarrior(ninja, h[1]);
        warriors[3].assignwarrior(iceman, h[2]);
        warriors[4].assignwarrior(wolf, h[4]);
    }
}

void headquarter::makingWarrior() {
    int i = number%5;
    warriors[i].born();
    if ((time%12)/10) {
        cout << "0" << time%12 << " ";
    } else {
        cout << "00" << time%12 << " ";
    }

    cout << gethtype() << " " << warriors[i].gettype() << " " << time+1
    << " born with strength " << warriors[i].gethealth() << ", "
    << warriors[i].getnumber() << " " << warriors[i].gettype() << " in  "
    << gethtype() << " headquarter" << endl;
    life -= warriors[i].gethealth();
    number++;
    time++;
}

int headquarter::check() {
    int j;
    for (j = 0; j < 5; j++) {
        int i = (number + j)%5;
        if (life >= warriors[i].gethealth())
            break;
    }
    if (j < 5) {
        number += j;
        return 1;
    }
    return 0;
}

int main() {
    int M, times;
    int health[5];
    cout << "Please input test numbers:";
    cin >> times;
    cout <<endl;
    for (int j = 0; j < times; j++) {
        cout << "Please input life point M (1<=M<=10000):";
        cin >> M;
        cout << "Please input warriors life point:";
        for (int i = 0; i < 5; i++) {
            cin >> health[i];
        }
        headquarter hred(headquartertype::red, health, M);
        headquarter hblue(headquartertype::blue, health, M);
        while (hred.check() || hblue.check()) {
            if (hred.check()) {
                hred.makingWarrior();
            }
            if (hblue.check()) {
                hblue.makingWarrior();
            }
        }
        cout << endl;
    }
    return 0;
}
