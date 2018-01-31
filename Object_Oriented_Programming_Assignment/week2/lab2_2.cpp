//
//  lab2_2.cpp
//  lab2_2
//
//  Created by Tangrizzly on 21/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include<iostream>
using namespace std;

class Cargo{
public:
    Cargo(int number, char* name, int weight, int price);
    Cargo(const Cargo &C);
    ~Cargo();
    static int SumOfBoxes;
    static int SumOfWeight;
    static void add(int weight);
    static void sell(int weight);
private:
    int number;
    char* name;
    int weight;
    int price;
};
int Cargo::SumOfWeight = 0;
int Cargo::SumOfBoxes = 0;

void Cargo::add(int weight){
    SumOfBoxes++;
    SumOfWeight += weight;
    cout << SumOfBoxes << " boxes of Cargo weigh " << SumOfWeight << "." << endl;
}

void Cargo::sell(int weight){
    SumOfBoxes--;
    SumOfWeight -= weight;
    cout << SumOfBoxes << " boxes of Cargo weigh " << SumOfWeight << "." << endl;
}

Cargo::Cargo(int number, char* name, int weight, int price) {
    cout << "buying a box of cargo." << endl;
    this->number = number;
    this->name=new char[strlen(name)+1];
    if(this->name)
        strcpy(this->name,name);
    this->weight = weight;
    this->price = price;
    add(weight);
}

Cargo::Cargo(const Cargo &C) {
    cout << "buying a same box of cargo." << endl;
    number = C.number;
    //name = C.name;
    name=new char[strlen(C.name)+1];
    if(name)
        strcpy(name,C.name);
    weight = C.weight;
    price = C.price;
    add(weight);
}

Cargo::~Cargo() {
    cout << "selling a box of cargo." <<endl;
    if (name!=NULL) {
        delete[] name;
    }
    sell(weight);
}

int main() {
    Cargo cargo1(1, "cargo1", 2, 3);
    Cargo cargo2(cargo1);
    return 0;
}
