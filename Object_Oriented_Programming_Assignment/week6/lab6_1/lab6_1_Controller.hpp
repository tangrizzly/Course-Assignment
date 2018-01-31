//
//  lab6_1_Controller.hpp
//  lab6_1
//
//  Created by Tangrizzly on 13/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#ifndef lab6_1_Controller_h
#define lab6_1_Controller_h

#include "lab6_1_date.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "lab6_1_account.hpp"
class Controller {
private:
    string id;
    Account* account;
public:
    Controller(string _id,Account* _account):id(_id) {
        account = _account;
    }
    void write_op(string type, Date date, double amount, string desc);
    void get_control();
    void op(string type, int year, int month, int day, double amount, string desc);
};

void Controller::write_op(string type, Date date, double amount, string desc) {
    fstream f(id, ios::app);
    if (f.is_open()) {
        f << type << ' ' \
        << date.getYear()  << ' ' << date.getMonth() << ' ' << date.getDay() << ' ' \
        << amount << ' ' << desc << endl;
        f.close();
    }
}
void Controller::get_control() {
    fstream f(id, ios::in);
    string readline;
    if (f) {
        while (!f.eof()) {
            string type, desc;
            int year, month, day;
            double amount;
            f >> type >> year >> month >> day >> amount;
            getline(f,desc);
            op(type, year, month, day, amount, desc);
        }
    } else {
        cout << "No previous record." << endl;
    }
}
void Controller::op(string type, int year, int month, int day, double amount, string desc) {
    Date date(year, month, day);
    if (type == "settle") {
        account->settle(date);
    } else if (type == "withdraw") {
        account->withdraw(amount, date, desc);
    } else if (type == "deposit") {
        account->deposit(amount, date, desc);
    } else {
        cout << "Wrong operation." <<endl;
    }
}

#endif /* lab6_1_Controller_h */
