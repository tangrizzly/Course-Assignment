//
//  lab4_4_account.hpp
//  lab4_4
//
//  Created by Tangrizzly on 07/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab4_4_account_hpp
#define lab4_4_account_hpp

#include "lab4_4_date.hpp"
#include <cmath>

class SavingsAccount {
private:
    string id;  //string解决账户以0开头、超过int范围表示、包含其他字符等问题
    double balance;
    double rate;
    Date lastDate;
    //存储上次计算利息以后直到最近一次余额变动时余额按日累加值
    double accumulation;
    static double total;
    //计算截止至指定日期的账户余额按日累计值
    const double accumulate(Date date);
    void record(double amount, Date date, string desc);   //账目列表，desc为各账目添加文字说明
    const void error(string msg) { cout << msg << endl; }    //当其他函数需要输出错误信息，将信息一字符串形式传入
public:
    SavingsAccount(string _id, Date date, float _rate):id(_id),lastDate(date),rate(_rate) {
        accumulation = 0;
    }
    const string getId() {return id;}
    const double getBalance() {return balance;}
    const double getRate() {return rate;}
    const void show();
    void deposit(double amount, Date date, string desc) {cout << "Add "; record(amount, date, desc);}
    void withdraw(double amount, Date date, string desc) {cout << "Withdraw "; record(-amount, date, desc);}
    void settle(Date date) {cout << "Settle "; float t = accumulate(date);
        record(t, date, "settling");accumulation = 0;}
    const double getTotal() {return total;}
};
double SavingsAccount::total = 0;
void SavingsAccount::record(double amount, Date date, string desc) {
    cout << amount << " on ";
    date.show();
    cout << "Before: " << balance << ". ";
    accumulation += balance * date.distance(lastDate);
    lastDate = date;
    balance += amount;
    total +=amount;
    cout << "Current: " << balance << ". ";
    cout << "Cause for " << desc << ". " << endl;
}
const void SavingsAccount::show() {
    cout << "Id is " << id << ". Balance is " << balance;
    cout << ". Last modified date is ";
    lastDate.show();
}
const double SavingsAccount::accumulate(Date date) {
    return floor((accumulation+balance*date.distance(lastDate))*rate/365*100+0.5)/100;
}

#endif /* lab4_4_account_hpp */
