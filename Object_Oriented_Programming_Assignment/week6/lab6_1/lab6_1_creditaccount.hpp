//
//  lab6_1_creditaccount.hpp
//  lab6_1
//
//  Created by Tangrizzly on 13/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//


#ifndef lab6_1_creditaccount_hpp
#define lab6_1_creditaccount_hpp

#include "lab6_1_date.hpp"

class CreditAccount:public Account{
private:
    Accumulator acc;
    double credit;
    double fee;
    const double getDebt();
    Controller* con;
public:
    CreditAccount(string _id, Date date, double _rate, double _credit,
                  double _fee):Account(_id, date),acc(date, _rate, 30), credit(_credit), fee(_fee) {
        con = new Controller(_id, this);
        
    }
    void read() { con->get_control(); }
    const double getCredit() {return credit;}
    const double getFee() {return fee;}
    const double getAvailableCredit() {return credit - getBalance();}
    void deposit(double amount, Date date, string desc);
    void withdraw(double amount, Date date, string desc);
    void settle(Date date);
    const void show();
};
void CreditAccount::deposit(double amount, Date date, string desc) {
    //欠款减少，如果存款额大于透支额，则将计算利息的部分金额置为零，但是以往累计的不变
    cout << "Repay "; record(-amount, date, desc);
    double value = getBalance() - amount;
    if (value < 0) {
        acc.reset(date, 0);
    } else {
        acc.change(date, amount);
    }
    con->write_op("deposit", date, amount, desc);
}
void CreditAccount::withdraw(double amount, Date date, string desc) {
    //欠款金额增加，如果超出透支额度，则操作失败
    int value = getBalance() + amount;
    if (value > credit) {
        error("Over Comsuming. Operation failed.");
        return;
    }
    cout << "Comsume ";
    record(amount, date, desc);
    acc.change(date, amount);
    con->write_op("withdraw", date, amount, desc);
}
void CreditAccount::settle(Date date) {
    cout << "Settle ";
    float t = acc.accumulate(date);
    record(t, date, "settling");
    if (date.getMonth() == 1 && date.getDay() == 1) {
        withdraw(fee, date, "annual fee");
    }
    if (date.getDay() == 1) {
        acc.reset(date, 0);
    }
    con->write_op("settle", date, 0, "");
}
const void CreditAccount::show() {
    cout << "Id is " << id << ". Debt is " << balance;
    cout << ". Last modified date is ";
    lastDate.show();
}
#endif /* lab6_1_account_hpp */
