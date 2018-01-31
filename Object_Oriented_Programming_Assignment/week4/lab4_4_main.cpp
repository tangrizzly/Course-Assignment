//
//  lab4_main.cpp
//  lab4_4
//
//  Created by Tangrizzly on 07/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#include "lab4_4_account.hpp"

int main() {
    Date date1(2018,1,1);
    SavingsAccount account("08261831", date1, 0.015);
    account.show();
    Date date2(2018,1,5);
    account.deposit(5000, date2, "salary");
    Date date3(2018,2,14);
    account.deposit(5500, date3, "lottery");
    Date date4(2018,3,31);
    account.settle(date4);
    Date date5(2018,4,10);
    account.withdraw(2000, date5, "house rent");
    Date date6(2018,5,15);
    account.settle(date6);
    return 0;
}
