//
//  headquarter.cpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#include "headquarter.hpp"

void Headquarter::warriorBorn(Warrior **c, Warrior **enemy) {
    switch (warriorBornOrder[number%5]) {
        case dragon:
            if (elements >= warriorHealth[dragon]) {
                cout << *htime << ' ' << getType() << ' ';
                *c = new Dragon(number, warriorHealth[dragon], warriorAttack[dragon], elements);
                *enemy = *c;
                number++;
                elements -= warriorHealth[dragon];
            }
            break;
        case ninjia:
            if (elements >= warriorHealth[ninjia]) {
                cout << *htime << ' ' << getType() << ' ';
                *c = new Ninjia(number, warriorHealth[ninjia], warriorAttack[ninjia]);
                *enemy = *c;
                number++;
                elements -= warriorHealth[ninjia];
            }
            break;
        case iceman:
            if (elements >= warriorHealth[iceman]) {
                cout << *htime << ' ' << getType() << ' ';
                *c = new Iceman(number, warriorHealth[iceman], warriorAttack[iceman]);
                *enemy = *c;
                number++;
                elements -= warriorHealth[iceman];
            }
            break;
        case lion:
            if (elements >= warriorHealth[lion]) {
                cout << *htime << ' ' << getType() << ' ';
                *c = new Lion(number, warriorHealth[lion], warriorAttack[lion], elements);
                *enemy = *c;
                number++;
                elements -= warriorHealth[lion];
            }
            break;
        case wolf:
            if (elements >= warriorHealth[wolf]) {
                cout << *htime << ' ' << getType() << ' ';
                *c = new Wolf(number, warriorHealth[wolf], warriorAttack[wolf]);
                *enemy = *c;
                number++;
                elements -= warriorHealth[wolf];
            }
            break;
    }
}

int Headquarter::scheduled(Headquarter* enemyHeadquater) {
    switch (htime->getMinutes()) {
        case 0:
            born(enemyHeadquater);
            break;
        case 5:
            //if lion'K <= 0 and lion is not in enemy's headquarter, lion runs
            for (int i = 0; i < N+2; i++) {
                if (cities[i]->warrior != NULL) {
                    cities[i]->warrior->run();
                    if (!cities[i]->warrior->getHealth()) {
                        cout << *htime << ' '<< getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << "ran away" << endl;
                        // delete cities[i]->warrior;
                        cities[i]->warrior = NULL;
                    }
                }
            }
            break;
        case 10: {
            Warrior* w = march(enemyHeadquater);
            for (int i = 0; i < N+2; i++) {
                if (cities[i]->warrior!=NULL) {
                    cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " marched to city " << i << " with " << cities[i]->warrior->getHealth() << " elements and force " << cities[i]->warrior->getAttack() << endl;
                }
            }
            if (w != NULL) {
                int success = arrive();
                cout << *htime << ' ' << getType() << ' ' << w->getType() << ' ' << w->getNumber() << " reached " << enemyHeadquater->getType() << " headquarter with " <<  w->getHealth() << " elements and force " <<  w->getAttack() << endl;
                if (success) {
                    cout << *htime << ' ' << enemyHeadquater->getType() << " headquarter was taken" << endl;
                    return 1;
                }
            }
            break;
        }
        case 20:
            for (int i = 0; i < N+2; i++) {
                cities[i]->setlife();
            }
            break;
        case 30:
            for (int i = 0; i < N+2; i++) {
                if (cities[i]->warrior!=NULL && cities[i]->enemyWarrior==NULL) {
                    getCityLife(cities[i]);
                    cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " earned 10 elements for his headquarter" << endl;
                }
            }
            break;
        case 35:
            shotArrow(enemyHeadquater);
            break;
        case 38:
            for (int i = 0; i < N+2; i++) {
                if (cities[i]->warrior != NULL && cities[i]->enemyWarrior != NULL) {
                    if (cities[i]->warrior->getHealth() > 0 && cities[i]->warrior->setOffBomb(cities[i]->enemyWarrior)) {
                        cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " used a bomb and killed " << enemyHeadquater->getType() << ' ' << cities[i]->enemyWarrior->getType() << ' ' <<  cities[i]->enemyWarrior->getNumber() << endl;
                        //cities[i].warrior->~Warrior();
                        cities[i]->warrior = NULL;
                        //cities[i].enemyWarrior->~Warrior();
                        cities[i]->enemyWarrior = NULL;
                    }
                }
            }
            break;
        case 40:
            for (int i = 0; i < N+2; i++) {
                int flag = cities[i]->getFlag() == getFlagType() || (cities[i]->getFlag() == none && i%2 == getFlagType());
                if (cities[i]->warrior!=NULL && cities[i]->enemyWarrior!=NULL && flag) {
                    int state = cities[i]->warrior->attackEnemy(cities[i]->enemyWarrior, htime, getType(), enemyHeadquater->getType(), i);
                    switch (state) {
                        //0. 两人都没死
                        //1. 自己（已经被箭射）死了，敌人没有
                        //2. 自己没死，敌人（被箭射）死了
                        //3. 两人都（被箭射）死了
                        case 1:
                            cities[i]->failed(getFlagType());
                            cities[i]->success(enemyHeadquater->getFlagType(), enemyHeadquater->getType(), htime, i);
                            cities[i]->warrior = NULL;
                            enemyHeadquater->getcities()[i]->enemyWarrior = NULL;
                            enemyHeadquater->award(cities[i]->enemyWarrior);
                            break;
                        case 2:
                            cities[i]->failed(enemyHeadquater->getFlagType());
                            cities[i]->success(getFlagType(), getType(), htime, i);
                            cities[i]->enemyWarrior = NULL;
                            enemyHeadquater->getcities()[i]->warrior = NULL;
                            award(cities[i]->warrior);
                            break;
                        default:    //case 0/3
                            cities[i]->failed(getFlagType());
                            cities[i]->failed(enemyHeadquater->getFlagType());
                            break;
                    }
                }
            }
            for (int i = 0; i < N+2; i++) {
                if (cities[i]->warrior != NULL && cities[i]->enemyWarrior == NULL) {
                    getCityLife(cities[i]);
                }
            }
            break;
        case 50:
            cout << *htime << ' ' << elements << " elements in " << getType() << " headquarter" << endl;
            break;
        case 55:
            for (int i = 0; i < N+2; i++) {
                if (cities[i]->warrior != NULL) {
                    cities[i]->warrior->reportArm(htime, getType());
                }
            }
            break;
        default:
            //do nothing
            break;
    }
    return 0;
}

class RedHeadquarter: public Headquarter {
public:
    RedHeadquarter(int _life, Clock* _htime, City** _cities):Headquarter(_life, _htime, _cities) {
        warriorBornOrder[1] = iceman;
        warriorBornOrder[2] = lion;
        warriorBornOrder[3] = wolf;
        warriorBornOrder[4] = ninjia;
        warriorBornOrder[0] = dragon;
    }
    string getType() {return "red";}
    Flag getFlagType() {return red;}
    void born(Headquarter* enemyHeadquater) {
        warriorBorn(&cities[0]->warrior, &enemyHeadquater->getcities()[0]->enemyWarrior);
    }
    Warrior* march(Headquarter* enemyHeadquater);
    void shotArrow(Headquarter* enemyHeadquater);
};
class BlueHeadquarter: public Headquarter {
public:
    BlueHeadquarter(int _life, Clock* _htime, City** _cities):Headquarter(_life, _htime, _cities) {
        warriorBornOrder[1] = lion;
        warriorBornOrder[2] = dragon;
        warriorBornOrder[3] = ninjia;
        warriorBornOrder[4] = iceman;
        warriorBornOrder[0] = wolf;
    }
    string getType() {return "blue";}
    Flag getFlagType() {return blue;}
    void born(Headquarter* enemyHeadquater) {
        warriorBorn(&cities[N+1]->warrior, &enemyHeadquater->getcities()[N+1]->enemyWarrior);
    }
    Warrior* march(Headquarter* enemyHeadquater);
    void shotArrow(Headquarter* enemyHeadquater);
};
Warrior* RedHeadquarter::march(Headquarter* enemyHeadquater) {
    for (int i = N+1; i > 0; i--) {
        cities[i]->warrior = cities[i-1]->warrior;
        enemyHeadquater->getcities()[i]->enemyWarrior = enemyHeadquater->getcities()[i-1]->enemyWarrior;
    }
    //return warrior reached enemy's headquarter
    cities[0]->warrior = NULL;
    enemyHeadquater->getcities()[0]->enemyWarrior = NULL;
    return cities[N+1]->warrior;
}
Warrior* BlueHeadquarter::march(Headquarter* enemyHeadquater) {
    for (int i = 0; i < N+1; i++) {
        cities[i]->warrior = cities[i+1]->warrior;
        enemyHeadquater->getcities()[i]->enemyWarrior = enemyHeadquater->getcities()[i+1]->enemyWarrior;
    }
    cities[N+1]->warrior = NULL;
    enemyHeadquater->getcities()[N+1]->enemyWarrior = NULL;
    return cities[0]->warrior;
}
void RedHeadquarter::shotArrow(Headquarter* enemyHeadquater) {
    for (int i = 0; i < N+2; i++) {
        if (cities[(i)%(N+2)]->warrior != NULL && cities[(i+1)%(N+2)]->enemyWarrior != NULL) {
            int state = cities[i]->warrior->fireArrow(cities[(i+1)%(N+2)]->enemyWarrior);
            if (state) {
                cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " shot" << endl;
                if (state == 2) {
                    cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " shot and killed " << enemyHeadquater->getType() << ' ' << cities[(i+1)%(N+2)]->enemyWarrior->getType() << ' ' <<  cities[(i+1)%(N+2)]->enemyWarrior->getNumber() << endl;
                }
            }
        }
    }
}
void BlueHeadquarter::shotArrow(Headquarter* enemyHeadquater) {
    for (int i = 0; i < N+2; i++) {
        if (cities[i%(N+2)]->warrior != NULL && cities[(i+N+1)%(N+2)]->enemyWarrior != NULL) {
            int state = cities[i]->warrior->fireArrow(cities[(i+N+1)%(N+2)]->enemyWarrior);
            if (state) {
                cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " shot" << endl;
                if (state == 2) {
                    cout << *htime << ' ' << getType() << ' ' << cities[i]->warrior->getType() << ' ' << cities[i]->warrior->getNumber() << " shot and killed " << enemyHeadquater->getType() << ' ' << cities[(i+N+1)%(N+2)]->enemyWarrior->getType() << ' ' <<  cities[(i+N+1)%(N+2)]->enemyWarrior->getNumber() << endl;
                }
            }
        }
    }
}
