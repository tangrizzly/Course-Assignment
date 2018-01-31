//
//  lab6_1_savingaccount.hpp
//  lab6_1
//
//  Created by Tangrizzly on 13/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//


#ifndef lab6_1_savingaccount_hpp
#define lab6_1_savingaccount_hpp

#include "lab6_1_date.hpp"
#include "lab6_1_accumulator.hpp"
#include "lab6_1_account.hpp"
#include "lab6_1_Controller.hpp"

class SavingsAccount: public Account{
private:
    Accumulator acc;
    Controller* con;
public:
    SavingsAccount(string _id, Date date, double _rate):Account(_id, date), acc(date, _rate, 365) {
        con = new Controller(_id, this);
    }
    void read() { con->get_control(); }
    void deposit(double amount, Date date, string desc);
    void withdraw(double amount, Date date, string desc);
    void settle(Date date);
    const void show();
};
void SavingsAccount::deposit(double amount, Date date, string desc) {
    acc.change(date, amount);
    cout << "Add ";
    record(amount, date, desc);
    con->write_op("deposit", date, amount, desc);
}
void SavingsAccount::withdraw(double amount, Date date, string desc) {
    acc.change(date, -amount);
    cout << "Withdraw ";
    record(-amount, date, desc);
    con->write_op("withdraw", date, amount, desc);
}
void SavingsAccount::settle(Date date) {
    if (!date.getMonth()) {
        return;
    }
    cout << "Settle ";
    float t = acc.accumulate(date); 
    record(t, date, "settling");
    acc.reset(date, 0);
    con->write_op("settle", date, 0, "");
}
const void SavingsAccount::show() {
    cout << "Id is " << id << ". Balance is " << balance;
    cout << ". Last modified date is ";
    lastDate.show();
}
#endif /* lab6_1_account_hpp */
