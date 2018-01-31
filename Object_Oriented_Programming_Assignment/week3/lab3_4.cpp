//
//  main.cpp
//  lab3_4
//
//  Created by Tangrizzly on 29/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class SavingsAccount {
private:
    int id;
    double balance;
    double rate;
    int lastDate;
    //存储上次计算利息以后直到最近一次余额变动时余额按日累加值
    double accumulation;
    //计算截止至指定日期的账户余额按日累计值
    double accumulate(int date) {return floor((accumulation+balance*(date-lastDate))*rate/365*100+0.5)/100;}
    void record(double amount, int date);
public:
    SavingsAccount(int _id, int date, float _rate):id(_id),lastDate(date),rate(_rate) {
        accumulation = 0;
    }
    int getId() {return id;}
    double getBalance() {return balance;}
    double getRate() {return rate;}
    void show();
    void deposit(double amount, int date) {cout << "Add "; record(amount, date);}
    void withdraw(double amount, int date) {cout << "Withdraw "; record(-amount, date);}
    void settle(int date) {cout << "Settle "; float t = accumulate(date);
        record(t, date); accumulation = 0;}
};
void SavingsAccount::record(double amount, int date) {
    cout << amount << " on the " << date << "th day." << endl;
    cout << "Before: " << balance << ". ";
    accumulation += balance * (date-lastDate);
    lastDate = date;
    balance += amount;
    cout << "Current: " << balance << "." << endl;
}
void SavingsAccount::show() {
    cout << "Id is " << id << ". Balance is " << balance;
    cout << ". Last modified date is "<< lastDate << "." << endl;
}

int main() {
    SavingsAccount account(1, 1, 0.015);
    account.show();
    account.deposit(5000, 5);
    account.deposit(5500, 45);
    account.settle(90);
    account.withdraw(2000, 100);
    account.settle(105);
    return 0;
}


