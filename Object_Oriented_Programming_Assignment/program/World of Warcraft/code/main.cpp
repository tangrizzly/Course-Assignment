//
//  main.cpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#include "headquarter.cpp"

// 不足：
// 内存管理：没有实现delete 程序在运行结束后统一释放所有new出来的变量
// 每次都需要修改city和enemyCity对同一英雄的指针，应该把他们指向同一个对英雄的指针，而不是直接指向英雄指针

int main() {
    int M, T, times;
    cin >> times;
    for (int j = 0; j < times; j++) {
        // M elements points in each headquarter
        // N cities
        // R - arrow attack points
        // K - lion reduce K loyalty points, when it does not kill the enemy
        // T - output all events till T minutes. 0 <= T <= 5000
        cin >> M >> N >> R >> K >> T;
        // initial elements points of each warrior: dragon 、ninja、iceman、lion、wolf
        for (int i = 0; i < 5; i++) {
            cin >> warriorHealth[i];
        }
        // attack points of each warrior: dragon 、ninja、iceman、lion、wolf
        for (int i = 0; i < 5; i++) {
            cin >> warriorAttack[i];
        }
        cout << "case " << times << endl;

        //initalize city
        int **life = new int*[N+2];
        for (int i = 0; i < N+2; i++) {
            life[i] = new int(0);
        }
        Warrior* redWarriors[N+2];
        Warrior* blueWarriors[N+2];
        for (int i = 0; i < N+2; i++) {
            redWarriors[i] = NULL;
            blueWarriors[i] = NULL;
        }
        City** redCities = new City*[N+2];
        City** blueCities = new City*[N+2];
        for (int i = 0; i < N+2; i++) {
            redCities[i] = new City(redWarriors[i], blueWarriors[i], life[i]);
            blueCities[i] = new City(blueWarriors[i], redWarriors[i], life[i]);
        }
        Clock* t = new Clock;
        RedHeadquarter redHeadquarter(M, t, redCities);
        BlueHeadquarter blueHeadquarter(M, t, blueCities);
        
        int end = 0;
        while (t->getTotalTime() < T && !end) {
            end += redHeadquarter.scheduled(&blueHeadquarter);
            end += blueHeadquarter.scheduled(&redHeadquarter);
            t->click_clock(1);
        }
    }
    return 0;
}
