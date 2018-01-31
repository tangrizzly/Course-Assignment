//
//  main.cpp
//  lab3_2
//
//  Created by Tangrizzly on 27/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
using namespace std;

enum CPU_Rank {P1=1, P2, P3, P4, P5, P6, P7};
enum RAM_Kind {DDR4, DDR3, DDR2};
enum IO_Kind {SATA, USB};
enum INSTALL_Kind {external, built_in};
class cpu {
private:
    enum CPU_Rank rank;
    int frequency; //Mhz
    float voltage;
public:
    cpu(enum CPU_Rank r, int f, float v):rank(r),frequency(f),voltage(v)
    {cout << "Constructing CPU." << endl;}
    cpu(const cpu& c):rank(c.rank),frequency(c.frequency),voltage(c.voltage)
    {cout << "Copying CPU." << endl;}
    ~cpu() {cout << "Deconstructing CPU." << endl;}
    void run() {cout << "Cpu running." << endl;}
    void stop() {cout << "Cpu stopping." << endl;}
    enum CPU_Rank getrank() {return rank;}
    int getfrequency() {return frequency;}
    float getvoltage() {return voltage;}
    void setrank(CPU_Rank rank) {this->rank = rank;}
    void setfrequency(int frequency) {this->frequency = frequency;}
    void setvoltage(float voltage) {this->voltage = voltage;}
};

class ram {
private:
    int volume;
    enum RAM_Kind kind;
    int frequency;
public:
    ram(int v, enum RAM_Kind k, int f):volume(v),kind(k),frequency(f)
    {cout << "Constructing RAM." << endl;}
    ram(const ram& r):volume(r.volume),kind(r.kind),frequency(r.frequency)
    {cout << "Copying RAM." << endl;}
    ~ram() {cout << "Deconstructing RAM." << endl;}
    enum RAM_Kind getkind() {return kind;}
    int getfrequency() {return frequency;}
    int getvolume() {return volume;}
    void setkind(enum RAM_Kind k) {kind = k;}
    void setfrequency(int f) {frequency = f;}
    void setvolume(int v) {volume = v;}
};

class cd_rom {
private:
    enum IO_Kind iokind;
    enum INSTALL_Kind installkind;
    int volume;
public:
    cd_rom(enum INSTALL_Kind insk, enum IO_Kind iok, int v):installkind(insk),iokind(iok),volume(v)
    {cout << "Constructing CD_ROM." << endl;}
    cd_rom(const cd_rom& c):installkind(c.installkind),iokind(c.iokind),volume(c.volume)
    {cout << "Copying CD_ROM." << endl;}
    ~cd_rom() {cout << "Deconstructing CD_ROM." << endl;}
    enum IO_Kind getiokind() {return iokind;}
    enum INSTALL_Kind getinskind() {return installkind;}
    int getvolume() {return volume;}
    void setiokind(enum IO_Kind k) {iokind = k;}
    void setinskind(enum INSTALL_Kind k) {installkind = k;}
    void setvolume(int v) {volume = v;}
};

class computer {
private:
    cpu CPU;
    ram RAM;
    cd_rom CD_ROM;
public:
    computer(enum CPU_Rank r, int f1, float v1,
             int v2, enum RAM_Kind k, int f2,
             enum INSTALL_Kind insk, enum IO_Kind iok, int v3
             ):CPU(r, f1, v1),RAM(v2, k, f2),CD_ROM(insk, iok, v3)
    {cout << "Constructing Computer." << endl;}
    ~computer() {cout << "Deconstructing Computer." << endl;}
    void run() {cout << "Computer running." << endl; CPU.run();}
    void stop() {CPU.stop(); cout << "Computer stopping" << endl;}
};

int main() {
    //cpu Cpu(P4, 5, 18.5);
    //ram Ram(8, DDR4, 5);
    //cd_rom Cd_rom(external, USB, 4);
    //computer Computer(Cpu, Ram, Cd_rom);
    computer Computer(P4, 5, 18.5, 8, DDR4, 5, external, USB, 4);
    Computer.run();
    Computer.stop();
    return 0;
}
