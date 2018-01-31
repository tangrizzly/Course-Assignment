//
//  homework2_2.cpp
//  homework2_2
//
//  Created by Tangrizzly on 25/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string m_strName;
public:
    Student() {cout<<"constructing Student class."<<endl;}
    Student(string _name) {cout<<"constructing Student class."<<endl;
        m_strName = _name;}
    Student(const Student& stu) {m_strName = stu.m_strName;}
    ~Student() {cout<<"deconstructing Student class."<<endl;}
    void setName(string _name) {m_strName = _name;}
    string getName() {return m_strName;}
};

int main(void) {
    Student *stu1 = new Student;
    stu1->setName("Alice");
    Student *stu2 = new Student("Bob");
    cout<<"person1's name is "<<stu1->getName()<<endl;
    cout<<"person2's name is "<<stu2->getName()<<endl;
    delete stu1;
    delete stu2;
    return 0;
}
