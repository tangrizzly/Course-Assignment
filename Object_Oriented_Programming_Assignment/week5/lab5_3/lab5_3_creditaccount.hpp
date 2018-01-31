//
//  lab5_3_creditaccount.hpp
//  lab5_3
//
//  Created by Tangrizzly on 12/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab5_3_creditaccount_hpp
#define lab5_3_creditaccount_hpp

#include "lab5_3_date.hpp"

class CreditAccount:public Account{
private:
    Accumulator acc;
    double credit;
    double fee;
    const double getDebt();
public:
    CreditAccount(string _id, Date date, double _rate, double _credit,
        double _fee):Account(_id, date),acc(date, _rate, 30), credit(_credit), fee(_fee) {}
    const double getCredit() {return credit;}
    const double getFee() {return fee;}
    const double getAvailableCredit() {return credit - getBalance();}
    void repay(double amount, Date date, string desc);
    void consume(double amount, Date date, string desc);
    void settle(Date date);
};
void CreditAccount::repay(double amount, Date date, string desc) {
    //欠款减少，如果存款额大于透支额，则将计算利息的部分金额置为零，但是以往累计的不变
    cout << "Repay "; record(-amount, date, desc);
    double value = getBalance() - amount;
    if (value < 0) {
        acc.reset(date, 0);
    } else {
        acc.change(date, amount);
    }
}
void CreditAccount::consume(double amount, Date date, string desc) {
    //欠款金额增加，如果超出透支额度，则操作失败
    int value = getBalance() + amount;
    if (value > credit) {
        error("Over Comsuming. Operation failed.");
        return;
    }
    cout << "Comsume ";
    record(amount, date, desc);
    acc.change(date, amount);
}
void CreditAccount::settle(Date date) {
    cout << "Settle ";
    float t = acc.accumulate(date);
    record(t, date, "settling");
    if (date.getMonth() == 1 && date.getDay() == 1) {
        consume(fee, date, "deduct annual fee");
    }
    if (date.getDay() == 1) {
        acc.reset(date, 0);
    }
}
#endif /* lab5_3_account_hpp */
