//
//  lab5_3_main.cpp
//  lab5_3
//
//  Created by Tangrizzly on 12/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//

#include "lab5_3_savingaccount.hpp"
#include "lab5_3_creditaccount.hpp"

int main() {
    cout << "Testing for saving account." << endl;
    Date date1(2018,1,1);
    SavingsAccount savingaccount("08261831", date1, 0.015);
    savingaccount.show();
    Date date2(2018,1,5);
    savingaccount.deposit(5000, date2, "salary");
    Date date3(2018,2,14);
    savingaccount.deposit(5500, date3, "lottery");
    Date date4(2018,3,31);
    savingaccount.settle(date4);
    Date date5(2018,4,10);
    savingaccount.withdraw(2000, date5, "house rent");
    Date date6(2018,5,15);
    savingaccount.settle(date6);
    cout << endl << "Testing for credit account." <<endl;
    CreditAccount creditaccount("48329561", date1, 0.035, 3000, 150);
    creditaccount.show();
    Date date7(2018,1,15);
    creditaccount.consume(250, date7, "shoes");
    Date date8(2018,2,1);
    creditaccount.settle(date8);
    Date date9(2018,2,3);
    creditaccount.repay(255, date8, "repay Janurary's bill");
    Date date10(2018,2,7);
    creditaccount.consume(5000, date9, "jewlry");
    creditaccount.consume(360, date9, "food");
    Date date11(2018,3,1);
    creditaccount.settle(date11);
    Date date12(2018,3,4);
    creditaccount.repay(371, date12, "repay February's bill");
    Date date13(2019,1,1);
    creditaccount.settle(date13);
    return 0;
}
