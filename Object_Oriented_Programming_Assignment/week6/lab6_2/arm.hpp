//
//  arm.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef arm_hpp
#define arm_hpp

#include <iostream>
using namespace std;

class Warrior;
enum armType {sword = 0,bomb,arrow};

class Arm {
protected:
    armType type;
    int attack_point;
public:
    Arm(armType _type):type(_type) {
        attack_point = 0;
    }
    void setAttackPoint(int p) {
        attack_point = p;
    }
    virtual int attack(Warrior* itself, Warrior* enemy) {return 0;}
    virtual bool exist() {return 1;}
    virtual string getType() = 0;
    int getTypeNumber() {return type;}
    const int getAttackPoint() {return attack_point;}
    virtual int print() {return 0;};
};

#endif /* arm_hpp */
