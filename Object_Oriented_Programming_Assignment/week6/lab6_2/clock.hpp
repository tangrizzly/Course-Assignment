//
//  clock.hpp
//  lab6_2_2
//
//  Created by Tangrizzly on 14/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef clock_h
#define clock_h

class Clock {
private:
    int hours;
    int minutes;
public:
    Clock() {
        hours = 0;
        minutes = 0;
    }
    void click_clock(int min);
    const int getHours() {return hours;}
    const int getMinutes() {return minutes;}
    const int getTotalTime() {return hours*60 + minutes;}
    friend ostream& operator<< (ostream& out, Clock &clock);
};

void Clock::click_clock(int min) {
    int total_min = minutes + min;
    minutes = total_min % 60;
    hours += total_min / 60;
}

ostream& operator<< (ostream &out, Clock &clock) {
    if (clock.hours/100) {
        out << clock.hours/100;
    } else {
        out << 0;
    }
    if (clock.hours/10%10) {
        out << clock.hours/10%10;
    } else {
        out << 0;
    }
    out << clock.hours%10;
    out << ':';
    if (clock.minutes/10) {
        out << clock.minutes/10;
    } else {
        out << 0;
    }
    out << clock.minutes%10;
    return out;
}

#endif /* clock_h */
