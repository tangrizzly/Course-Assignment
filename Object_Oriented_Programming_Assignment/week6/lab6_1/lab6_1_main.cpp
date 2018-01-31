//
//  lab6_1_main.cpp
//  lab6_1
//
//  Created by Tangrizzly on 13/01/2018.
//  Copyright © 2018 Tangrizzly. All rights reserved.
//


#include "lab6_1_savingsaccount.hpp"
#include "lab6_1_creditaccount.hpp"

int main() {
    Account *a[2];
    Date date1(2018,1,1);
    a[0] = new SavingsAccount("08261831", date1, 0.015);
    a[1] = new CreditAccount("48329561", date1, 0.035, 3000, 150);
    for (int i = 0; i < 2; i++) {
        a[i]->show();
    }
    a[0]->read();
    a[1]->read();
    
    //首次运行时，没有之前的记录，运行以下命令
    //在第二次运行时，将一下命令注释掉，根据输出面板发现程序自动运行了上次一样的命令
    cout << endl << "Testing for saving account." << endl;
    Date date2(2018,1,5);
    a[0]->deposit(5000, date2, "salary");
    Date date3(2018,2,14);
    a[0]->deposit(5500, date3, "lottery");
    Date date4(2018,4,10);
    a[0]->withdraw(2000, date4, "house rent");
    Date date5(2019,1,1);
    a[0]->settle(date5);
    cout << endl << "Testing for credit account." <<endl;
    Date date7(2018,1,15);
    a[1]->withdraw(250, date7, "shoes");
    Date date8(2018,2,1);
    a[1]->settle(date8);
    Date date9(2018,2,3);
    a[1]->deposit(255, date8, "repay Janurary's bill");
    Date date10(2018,2,7);
    a[1]->withdraw(5000, date9, "jewlry");
    a[1]->withdraw(360, date9, "food");
    Date date11(2018,3,1);
    a[1]->settle(date11);
    Date date12(2018,3,4);
    a[1]->deposit(371, date12, "repay February's bill");
    Date date13(2019,1,1);
    a[1]->settle(date13);
    return 0;
}
