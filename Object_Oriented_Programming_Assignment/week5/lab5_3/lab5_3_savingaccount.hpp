//
//  lab5_3_savingaccount.hpp
//  lab5_3
//
//  Created by Tangrizzly on 12/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab5_3_savingaccount_hpp
#define lab5_3_savingaccount_hpp

#include "lab5_3_date.hpp"
#include "lab5_3_accumulator.hpp"
#include "lab5_3_account.hpp"

class SavingsAccount: public Account{
private:
    Accumulator acc;
public:
    SavingsAccount(string _id, Date date, double _rate):Account(_id, date), acc(date, _rate, 365) {}
    void deposit(double amount, Date date, string desc);
    void withdraw(double amount, Date date, string desc);
    void settle(Date date);
};
void SavingsAccount::deposit(double amount, Date date, string desc) {
    acc.change(date, amount);
    cout << "Add ";
    record(amount, date, desc);
}
void SavingsAccount::withdraw(double amount, Date date, string desc) {
    acc.change(date, -amount);
    cout << "Withdraw ";
    record(-amount, date, desc);
}
void SavingsAccount::settle(Date date) {
    cout << "Settle ";
    float t = acc.accumulate(date); 
    record(t, date, "settling");
    acc.reset(date, 0);
}
#endif /* lab5_3_account_hpp */
