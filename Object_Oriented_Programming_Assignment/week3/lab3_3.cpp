//
//  main.cpp
//  lab3_3
//
//  Created by Tangrizzly on 27/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
using namespace std;

class Yuebao {
private:
    static double profitRate;
    double balance;
public:
    static void setProfitRate(double rate) {profitRate = rate;}
    Yuebao(double b):balance(b) {}
    void addProfit() {balance += balance*profitRate;}
    void deposit(int amount) {balance += amount;}
    void withdraw(int amount) {balance -= amount;}
    double getBalance() {return balance;}
};

double Yuebao::profitRate=0;

int main()
{
    int n;
    while(cin >> n)
    {
        double profitRate;
        cin >> profitRate;
        Yuebao::setProfitRate(profitRate);//设定余额宝的利率
        Yuebao y(0); //新建余额宝账户，余额初始化为0
        int operation;//接受输入判断是存还是取
        double amount;//接受输入存取金额
        for (int i = 0; i < n; ++i)
        {
            y.addProfit();//加入前一天余额产生的利息
            cin >> operation >> amount;
            if (operation == 0)
                y.deposit(amount);//存入金额
            else
                y.withdraw(amount);//取出金额
        }
        cout << y.getBalance() << endl;//输出最终账户余额
    }
    return 0;
}
