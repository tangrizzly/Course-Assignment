//
//  lab6_1_account.hpp
//  lab6_1
//
//  Created by Tangrizzly on 13/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab6_1_account_hpp
#define lab6_1_account_hpp

#include "lab6_1_date.hpp"

class Account {
private:
    static double total;
protected:
    string id;
    double balance;
    Date lastDate;
    void record(double amount, Date date, string desc);
    const void error(string msg) { cout << msg << endl; }
public:
    Account(string _id, Date date):id(_id),lastDate(date) {
        balance = 0;
    }
    const string getId() {return id;}
    const double getBalance() {return balance;}
    const double getTotal() {return total;}
    virtual const void show() = 0;
    virtual void deposit(double amount, Date date, string desc) = 0;
    virtual void withdraw(double amount, Date date, string desc) = 0;
    virtual void settle(Date date) = 0;
    virtual void read() = 0;
};
double Account::total = 0;
void Account::record(double amount, Date date, string desc) {
    cout << amount << " on ";
    date.show();
    cout << "Before: " << balance << ". ";
    // accumulation += balance * date.distance(lastDate);
    lastDate = date;
    balance += amount;
    total +=amount;
    cout << "Current: " << balance << ". ";
    cout << "Cause for " << desc << ". " << endl;
}

#endif /* lab6_1_account_hpp */
