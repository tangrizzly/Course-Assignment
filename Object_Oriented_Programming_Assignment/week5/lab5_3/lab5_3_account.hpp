//
//  lab5_3_account.hpp
//  lab5_3
//
//  Created by Tangrizzly on 12/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab5_3_account_hpp
#define lab5_3_account_hpp

#include "lab5_3_date.hpp"

class Account {
private:
    string id;
    double balance;
    static double total;
    Date lastDate;
protected:
    void record(double amount, Date date, string desc);
    const void error(string msg) { cout << msg << endl; }
public:
    Account(string _id, Date date):id(_id),lastDate(date) {
        balance = 0;
    }
    const string getId() {return id;}
    const double getBalance() {return balance;}
    const double getTotal() {return total;}
    const void show();
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
const void Account::show() {
    cout << "Id is " << id << ". Balance is " << balance;
    cout << ". Last modified date is ";
    lastDate.show();
}

#endif /* lab5_3_account_hpp */
