//
//  cwarrior.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef cwarrior_hpp
#define cwarrior_hpp

#include "carm.hpp"

void Warrior::attacking(Warrior *enemy) {
    if (arm[0] != NULL) {
        arm[0]->attack(this, enemy);
        if (!arm[0]->exist()) {
            arm[0] = NULL;
        }
    }
    enemy->gethurt(attack);
}

int Warrior::attackEnemy(Warrior *enemy, Clock *htime, string type, string enemyType, int cityNumber) {
    // there are four circumstances at both the beginning and the end:
    // 0. two warriors are both alive
    // 1. warrior is killed (by arrow) and enemy is alive
    // 2. warrior is alive and enemy is killed (by arrow)
    // 3. two warriors are both killed (by arrow)
    tempHealth = health;    //  recording the health before attack
    if (health > 0 && enemy->health > 0) {
        //combat happened
        cout << *htime << ' ' << type << ' ' << getType() << ' ' << number << " attacked " << enemyType << ' ' << enemy->getType() << ' ' << enemy->number << " in city " << cityNumber << " with " << health << " elements and force " << getTotalAttack() << endl;
        attacking(enemy);
        if (enemy->health > 0) {
            enemy->fightback(this);
            cout << *htime << ' ' << enemyType << ' ' << enemy->getType() << ' ' << enemy->number << " fought back against " << type << ' ' << getType() << ' ' << number << " in city " << cityNumber << endl;
        } else {
            cout << *htime << ' ' << enemyType << ' ' << enemy->getType() << ' ' << enemy->getNumber() << " was killed in city " << cityNumber << endl;
        }
        if (health <= 0) {
            cout << *htime << ' ' << type << ' ' << getType() << ' ' << getNumber() << " was killed in city " << cityNumber << endl;
        }
    }
    if (health > 0 && enemy->health > 0) {
        return 0;
    } else if (health <= 0 && enemy->health > 0) {
        return 1;
    } else if (health > 0 && enemy->health <= 0) {
        return 2;
    } else {
        return 3;
    }
}

void Warrior::getarmed(int type) {
    switch (type) {
        case sword:
            arm[0] = new Sword(attack);
            if (!arm[0]->exist()) {
                arm[0] = NULL;
            }
            break;
        case bomb:
            arm[1] = new Bomb();
            break;
        case arrow:
            arm[2] = new Arrow(R);
            break;
        default:
            break;
    }
}
class Dragon:public Warrior {
private:
    float morale;
public:
    Dragon(int _number, int _health, int _attack, int headquarter_health): Warrior(_number, _health, _attack), morale(headquarter_health/_health){
        getarmed(_number%3);
        cout << getType() << ' ' << number << " born" << endl;
        cout << "Its morale is " << morale << endl;
    }
    string getType() {return "dragon";}
    int attackEnemy(Warrior *enemy, Clock *htime, string type, string enemyType, int cityNumber) {
        int circumstance = Warrior::attackEnemy(enemy, htime, type, enemyType, cityNumber);
        int state;
        switch (circumstance) {
            case 0:
                morale -= 0.2;
                state = 0;
                break;
            case 1:
                return 1;
            case 2:
                state = 2;
                morale += 0.2;
                break;
            default:
                return 3;
        }
        if (morale > 0.8) {
            cout << *htime << ' ' << type << ' ' << getType() << ' ' << number << " yelled in city " << cityNumber << endl;
        }
        return state;
    }
};
class Ninjia:public Warrior {
public:
    Ninjia(int _number, int _health, int _attack): Warrior(_number, _health, _attack){
        getarmed(_number%3);
        getarmed((number+1)%3);
        cout << getType() << ' ' << number << " born" << endl;
    }
    string getType() {return "ninjia";}
    // ninjia never fight back
    void fightback(Warrior *enemy) { }  // do nothing
};
class Iceman:public Warrior {
private:
    int steps;
public:
    Iceman(int _number, int _health, int _attack):Warrior(_number, _health, _attack) {
        getarmed(_number%3);
        cout << getType() << ' ' << number << " born" << endl;
        steps = 0;
    }
    string getType() {return "iceman";}
    int attackEnemy(Warrior *enemy, Clock *htime, string type, string enemyType, int cityNumber) {
        int state = Warrior::attackEnemy(enemy, htime, type, enemyType, cityNumber);
        refactor();
        return state;
    }
    void refactor() {
        if (!steps%2 && steps > 0) {
            if (health >= 9) {
                gethurt(9);
                inspired(20);
            } else {
                sethealth(1);
            }
        }
        steps++;
    }
};
class Lion:public Warrior {
private:
    int loyalty;
    int _K;
public:
    Lion(int _number, int _health, int _attack, int headquarter_health):Warrior(_number, _health, _attack), loyalty(headquarter_health), _K(K) {
        getarmed(3);   //lion has no arm, arm = NULL
        cout << getType() << ' ' << number << " born" << endl;
        cout << "Its loyalty is " << loyalty << endl;
    }
    string getType() {return "lion";}
    int attackEnemy(Warrior *enemy, Clock *htime, string type, string enemyType, int cityNumber) {
        int state = Warrior::attackEnemy(enemy, htime, type, enemyType, cityNumber);
        switch (state) {
            case 0:
                loyalty -= _K;
                break;
            case 1:
                enemy->gethealed(tempHealth);
                break;
            default:
                break;
        }
        return state;
    }
    void run() {
        if (K <= 0) {
            sethealth(0);
        }
    }
};
class Wolf:public Warrior {
private:
public:
    Wolf(int _number, int _health, int _attack):Warrior(_number, _health, _attack) {
        cout << getType() << ' ' << number << " born" << endl;
    }
    string getType() {return "wolf";}
    int attackEnemy(Warrior *enemy, Clock *htime, string type, string enemyType, int cityNumber) {
        int state = Warrior::attackEnemy(enemy, htime, type, enemyType, cityNumber);
        if (state == 2) {
            if (arm[0] == NULL) {
                arm[0] = enemy->getSword();
            }
            if (arm[1] == NULL) {
                arm[1] = enemy->getBomb();
            }
            if (arm[2] == NULL) {
                arm[2] = enemy->getArrow();
            }
        }
        return state;
    }
};

#endif
