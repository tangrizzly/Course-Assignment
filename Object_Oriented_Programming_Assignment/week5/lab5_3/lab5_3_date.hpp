//
//  lab5_3_date.hpp
//  lab5_3
//
//  Created by Tangrizzly on 12/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab5_3_date_hpp
#define lab5_3_date_hpp

#include <iostream>
using namespace std;
class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;                  //相对日期日期
    const int g(int month, int year);
public:
    Date(int y, int m, int d):year(y), month(m), day(d){
        totalDays = 365*(y-1)+(y-1)/4-(y-1)/100+(y-1)/400+g(m, y)+d;
    }
    const int getYear() { return year; }
    const int getMonth() {return month; }
    const int getDay() { return day; }
    const int getMaxDay(int month, int year);          //得到当前月的天数
    const bool isLeapYear(int year);        //是否为闰年
    const void show();              //将当前日期输出
    const int distance(Date date);  //判断当前日期与指定日期相差天数
};
const int Date::getMaxDay(int month, int year) {
    int days = 0;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 31;
            break;
        case 2:
            if (isLeapYear(year)) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        default:
            cout << "wrong date." << endl;
            break;
    }
    return days;
}
const bool Date::isLeapYear(int year) {
    if (!(year % 4)&& year%100) {
        return true;
    } else {
        return false;
    }
}
const void Date::show() {
    cout << year << '/' << month << '/' << day << endl;
}
const int Date::distance(Date date) {
    return totalDays-date.totalDays;
}
const int Date::g(int month, int year) {
    int i, d = 0;
    for (i = 1; i < month; i++) {
        d += getMaxDay(i, year);
    }
    return d;
}
#endif /* lab5_3_date_hpp */
