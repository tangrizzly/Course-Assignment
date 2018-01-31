//
//  lab4_3.cpp
//  lab4_3
//
//  Created by Tangrizzly on 18/12/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include "iostream"
#include "cstring"
#include "cmath"
using namespace std;
class CBigInt {
private:
    string cvalue; //保存所有位上的数字
    int value[100];
    void convert();
    long size;
    bool negative;
public:
    friend ostream& operator<< (ostream& out, const CBigInt& src);
    CBigInt(string strValues);
    CBigInt();
    
    CBigInt operator + ( const CBigInt& rhs ) ; //加法操作重载
    CBigInt operator - ( const CBigInt& rhs) ; //减法操作符重载
    CBigInt operator * ( const CBigInt& rhs) ; //乘法操作符重载
    CBigInt operator * ( const int rhs);
    CBigInt operator / ( CBigInt& rhs) ; //除法操作重载
    
    void setValue(string& strValues) ; //根据字符串设置数值
};
ostream& operator<< (ostream& out, const CBigInt& src) {
    int i;
    if (src.negative) {
        out << '-';
    }
    for (i = (int)src.size-1; i>=0; i--) {
        out << src.value[i];
    }
    return out;
}

CBigInt::CBigInt(string strValues) {
    size = strValues.size();
    cvalue = strValues;
    if(strValues != "") {
        convert();
    }
    negative = false;
}

CBigInt::CBigInt() {
    size = 0;
    cvalue = "";
    for (int i = 0; i < 100; i++) {
        value[i] = 0;
    }
    negative = false;
}

void CBigInt::convert() {
    int i, j;
    for (i = (int)cvalue.size()-1, j = 0; i>=0; i--,j++) {
        value[j] = cvalue[i]-'0';
    }
    for (; j<100; j++) {
        value[j] = 0;
    }
}

CBigInt CBigInt::operator + ( const CBigInt& rhs) {
    int i, c = 0, s;
    CBigInt oc;
    for (i = 0; i<size || i<rhs.size; i++) {
        s = value[i] + rhs.value[i] + c;
        oc.value[i] = s % 10;
        c = s/10;
    }
    if (c) {
        oc.value[i] = c;
        oc.size = i+1;
    } else {
        oc.size = i;
    }
    return oc;
}

CBigInt CBigInt::operator - ( const CBigInt& rhs) {
    int i, c = 0, s;
    CBigInt oc;
    for (i = 0; i<size || i<rhs.size; i++) {
        s = value[i] - rhs.value[i] - c;
        if (s < 0) {
            s += 10;
            c = 1;
        } else {
            c = 0;
        }
        oc.value[i] = s;
    }
    if (c) {
        for (i--; i>=0; i--) {
            oc.value[i] = 10 - oc.value[i] - 1;
        }
        oc.value[0]++;
        oc.negative = true;
    }
    for (i = 99; i>=0 && oc.value[i]==0; i--) {}
    oc.size = i+1;
    return oc;
}

CBigInt CBigInt::operator * ( const CBigInt& rhs) {
    CBigInt oc;
    int i, j, c = 0, m;
    for (i = 0; i < rhs.size; i++) {
        for (j = 0; j < size; j++) {
            m = value[j]*rhs.value[i] + c + oc.value[i+j];
            oc.value[i+j] = m%10;
            c = m/10;
        }
        if (c) {
            oc.value[j+i] = c;
            c = 0;
        }
    }
    for (i = 99; i>=0 && oc.value[i]==0; i--) {}
    oc.size = i+1;
    return oc;
}

CBigInt CBigInt::operator * ( const int rhs) {
    CBigInt oc;
    int i, c = 0, m;
    for (i = 0; i < size; i++) {
        m = value[i]*rhs + c + oc.value[i];
        oc.value[i] = m%10;
        c = m/10;
    }
    for (; c >= 10; i++) {
        oc.value[i] = c%10;
        c = c/10;
    }
    oc.value[i] = c;
    c = 0;
    for (i = 99; i>=0 && oc.value[i]==0; i--) {}
    oc.size = i+1;
    return oc;
}

CBigInt CBigInt::operator / ( CBigInt& rhs) {
    CBigInt oc, m, s, t;
    int i, j, d;
    if (!rhs.size) {
        cout << "wrong number." << endl;
        return oc;
    }
    d = int(size - rhs.size);
    s = *this;
    for (j = d; j>=0; j--) {
        while (1) {
            m = rhs*int(pow(10, j));
            t = s-m;
            if (!t.negative && t.size) {
                oc.value[j]++;
                s = t;
                continue;
            }
            break;
        }
    }
    for (i = 99; oc.value[i]==0 && i>=0; i--);
    if (i >= 0) {
        oc.size = i+1;
    }
    return oc;
}

int main() {
    string a, b;
    char o;
    cin >> a;
    cin >> o;
    cin >> b;
    CBigInt ac(a);
    CBigInt bc(b);
    CBigInt c;
    switch (o) {
        case '+':
            c = ac+bc;
            break;
        case '-':
            c = ac-bc;
            break;
        case '*':
            c = ac*bc;
            break;
        case '/':
            c = ac/bc;
            break;
        default:
            cout << "wrong operator." << endl;
    }
    cout << c << endl;
    return 0;
}


