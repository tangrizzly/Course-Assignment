//
//  city.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 19/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef city_hpp
#define city_hpp

#include "cwarrior.hpp"

enum Flag {blue, red, none};

class City {
private:
    int* life;
    Flag flag;
    int red_combo;
    int blue_combo;
public:
    Warrior* warrior;
    Warrior* enemyWarrior;
    City(Warrior* w, Warrior* enemy_w, int* _life):warrior(w), enemyWarrior(enemy_w), life(_life) {
        flag = none;
        red_combo = 0;
        blue_combo = 0;
    }
    int warriorNumber() {
        if (warrior!=NULL && enemyWarrior!=NULL) {
            return 2;
        } else if (warrior==NULL && enemyWarrior==NULL) {
            return 0;
        } else {
            return 1;
        }
    }
    int getlife() {return *life;}
    void setlife() {*life += 5;}
    void resetLife() {*life = 0;}
    Flag getFlag() {return flag;}
    void failed(Flag type) {
        if (type == red) {
            red_combo = 0;
        } else {
            blue_combo = 0;
        }
    }
    void success(Flag type, string stype, Clock* htime, int city) {
        if (type == red) {
            red_combo++;
            if (red_combo >= 2) {
                flag = red;
                cout << *htime << ' ' << stype << " flag raised in city " << city << endl;
            }
        } else {
            blue_combo++;
            if ((blue_combo >= 2)) {
                flag = blue;
            }
        }
    }
};

#endif /* city_hpp */
