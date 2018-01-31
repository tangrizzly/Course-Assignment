//
//  warrior.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef warrior_hpp
#define warrior_hpp

#include "arm.hpp"
#include "clock.hpp"

static int R = 0, K = 0, N = 0;
static int warriorHealth[5]{0};    //dragon 、ninja、iceman、lion、wolf
static int warriorAttack[5]{0};    //dragon 、ninja、iceman、lion、wolf
enum WarriorType {dragon = 0, ninjia, iceman, lion, wolf};

class Warrior {
protected:
    int number;
    int health;
    int attack;
    Arm *arm[3];
    int tempHealth;
public:
    Warrior(int _number, int _health, int _attack):number(_number), health(_health), attack(_attack) {
        arm[0] = NULL;
        arm[1] = NULL;
        arm[2] = NULL;
    }
    const int getHealth() {return health;}
    const int getTotalAttack() {
        if (arm[0]!=NULL) {
            return attack + arm[0]->getAttackPoint();
        } else {
            return attack;
        }
    }
    const int getAttack() {
        return attack;
    }
    const int getNumber() {return number;}
    void sethealth(int _health) {health = _health;}
    Arm* getSword() {return arm[0];}
    Arm* getBomb() {return arm[1];}
    Arm* getArrow() {return arm[2];}
    bool alive() {return health>=0?1:0;}
    void gethurt(int _attack) {health -= _attack;}
    void gethealed(int heal) {health += heal;}
    void inspired(int _attack) {attack += _attack;}
    virtual string getType() = 0;
    void getarmed(int type);
    virtual int attackEnemy(Warrior *enemy, Clock * htime, string type, string enemyType, int cityNumber);
    virtual void fightback(Warrior *enemy) {
        if (arm[0] != NULL) {
            arm[0]->attack(this, enemy);
        }
        enemy->gethurt(attack);
    }
    virtual int fireArrow(Warrior *enemy) {
        if (arm[2] != NULL) {
            return arm[2]->attack(this, enemy);
        } else {
            return 0;
        }
    }
    virtual bool setOffBomb(Warrior *enemy) {
        if (arm[1] != NULL) {
            return arm[1]->attack(this, enemy);
        } else {
            return 0;
        }
    }
    virtual void run() {}
    void attacking(Warrior *enemy);
    virtual void reportArm(Clock* htime, string type) {
        int i = 0;
        cout << *htime << ' ' << type << ' ' << getType() << ' ' << number << " has ";
        i += printArm(arm[2]);
        i += printArm(arm[1]);
        i += printArm(arm[0]);
        if (!i) {
            cout << "no weapon";
        }
        cout << endl;
    }
    bool printArm(Arm* a) {
        if(a != NULL){
            if (a->exist()) {
                a->print();
                return 1;
            } else {
                a = NULL;
            }
        }
        return 0;
    }
};


#endif /* warrior_hpp */
