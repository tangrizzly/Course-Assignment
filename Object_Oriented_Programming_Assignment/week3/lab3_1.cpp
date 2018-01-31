//
//  main.cpp
//  lab3_1
//
//  Created by Tangrizzly on 27/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
using namespace std;
class Integer {
private:
    int _num;
public:
    //构造函数
    Integer(int num) {
        _num = num;
    }
    //计算当前Integer 和 b之间的最大公约数
    int gcd(Integer b) {
        if (!b._num) {
            return _num;
        }
        Integer r(_num%b._num);
        return b.gcd(r);
    }
};
int main(){
    int a, b;
    cin >> a >> b;
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
    return 0;
}
