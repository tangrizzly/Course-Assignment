//
//  carm.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 19/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef carm_hpp
#define carm_hpp

#include "warrior.hpp"
#include <cmath>

class Sword:public Arm {
public:
    Sword(int warrior_attack_point): Arm(sword) {
        setAttackPoint((int)(warrior_attack_point*0.2));
    }
    int attack(Warrior *self, Warrior *enemy) {
        enemy->gethurt(attack_point);
        attack_point = (int)(attack_point * 0.8);
        return 1;
    }
    bool exist() { if(attack_point > 0) return 1; else return 0;}
    string getType() {return "sword";}
    int print() {
        cout << "sword(" << attack_point << ')';
        return 1;
    }
};
class Arrow:public Arm {
private:
    int R;
    int times;
public:
    Arrow(int r): Arm(arrow), R(r) {
        times = 3;
    }
    int attack(Warrior *self, Warrior *nextEnemy) {//enemy is in the next city
        nextEnemy->gethurt(R);
        // arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。
        times--;
        if (nextEnemy->getHealth() <= 0) {
            //enemy get killed.
            return 2;
        } else {
            return 1;
        }
        return 0;
    }
    bool exist() { if(times <= 0) return 0; else return 1;}
    string getType() {return "arrow";}
    int print() {
        cout << "arrow(" << times << ") ";
        return 1;
    }
};
class Bomb:public Arm {
public:
    Bomb():Arm(bomb) {}
    string getType() {return "bomb";}
    int attack(Warrior *itself, Warrior *enemy) {
        bool setOff = (itself->getHealth() <= enemy->getTotalAttack());
        if (setOff) {
            itself->sethealth(0);
            enemy->sethealth(0);
        }
        return setOff;
    }
    int print() {
        cout << "bomb ";
        return 1;
    }
};

#endif
