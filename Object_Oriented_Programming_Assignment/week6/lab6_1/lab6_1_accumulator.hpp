//
//  lab6_1_accumulator.hpp
//  lab6_1
//
//  Created by Tangrizzly on 13/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//


#ifndef lab6_1_accumulator_hpp
#define lab6_1_accumulator_hpp

#include "lab6_1_date.hpp"
#include "cmath"

class Accumulator {
private:
    Date lastDate;
    double rate;
    double value;
    double accumulation;
    int days;
public:
    Accumulator(Date date, double _rate, int _days):lastDate(date), rate(_rate), days(_days) {
        accumulation = 0;
        value = 0;
    }
    const double accumulate(Date date);
    const double getRate() {return rate;}
    const double getValue() {return value;}
    void showDate() { lastDate.show(); }
    void change(Date date, double value);
    void reset(Date date, double value);
};
const double Accumulator::accumulate(Date date) {
    return floor((accumulation+value*(date-lastDate))*rate/days*100+0.5)/100;
}
void Accumulator::change(Date date, double _value) {
    accumulation += value * (date-lastDate);
    lastDate = date;
    value += _value;
}
void Accumulator::reset(Date date, double _value) {
    value = _value;
    lastDate = date;
}
#endif /* lab6_1_accumulator_hpp */
