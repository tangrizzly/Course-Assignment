//
//  headquarter.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef headquarter_hpp
#define headquarter_hpp

#include "city.hpp"

class Headquarter {
    //用一个N维的数组记录每个城市中的英雄，当值为空时表示没有英雄
protected:
    int warriorBornOrder[5];
    int elements;
    int number;
    Clock* htime;
    City** cities;
    int arrived;
    void warriorBorn(Warrior **c, Warrior **enemy);
    virtual void born(Headquarter* enemyHeadquater) = 0;
    virtual Warrior* march(Headquarter* enemyHeadquater) = 0;
    virtual void shotArrow(Headquarter* enemyHeadquater) = 0;
public:
    Headquarter(int _life, Clock* _htime, City** _cities):elements(_life), htime(_htime), cities(_cities){
        arrived = 0;
        number = 1;
    }
    int scheduled(Headquarter* enemyHeadquater);
    virtual string getType() = 0;
    virtual Flag getFlagType() = 0;
    City** getcities() {return cities;}
    void getCityLife(City* city) {
        if (city->getlife() > 0) {
            elements += city->getlife();
            city->resetLife();
        }
    }
    void reportLife();
    void award(Warrior* warrior) {
        if (elements > 8) {
            warrior->gethealed(8);
            elements -= 8;
        }
    }
    bool arrive() {
        arrived++;
        if (arrived >= 2) {
            return 1;
        } else {
            return 0;
        }
    }
};
#endif /* headquarter_hpp */
