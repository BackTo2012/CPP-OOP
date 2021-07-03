#include <stdio.h>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
class HardWare
{
public:
    char name[30];
    virtual void Work() = 0;
};
class PC {
public:
    vector<HardWare *> computer;
    void AddToPC(HardWare *Lingjian)
    {
        computer.push_back(Lingjian);
    };
    void Work() {
        int size = computer.size();
        for (int i = 0; i < size; ++i)
        {   computer[i]->Work();
        }
        cout << "PC Work" << endl;
    }
};
class CPU: public HardWare {
public:
    int hz;
    CPU(const char*cpuname, int hz) {
        strcpy(name, cpuname);
        this->hz = hz;
    }
    void Work() {
        cout << name << " CPU Work with " << hz << " GHz " << endl;
    }
};

// class MainBoard: public HardWare {
// public:
//     void AddToPC() {

//     };
// };
// class HardDisk: public HardWare {
// public:
//     void AddToPC() {

//     };
// };

//StudybarCommentBegin
int main()
{
    PC *p = new PC(); //创建机箱
    HardWare *p1 = new CPU("Intel", 4.5); //CPU品牌Intel，主频4.5GHz
    HardWare *p2 = new CPU("AMD", 3.8); //CPU品牌AMD，主频3.8GHz
    // HardWare *p3 = new MainBoard("ASUS", "ATX"); //主板品牌ASUS，板型ATX
    // HardWare *p4 = new HardDisk("Seagate", 500); //硬盘品牌Seagate，容量500G
    // HardWare *p5 = new HardDisk("Sumsang", 1000); //硬盘品牌Sumsang，容量1000G

    //把5个硬件依次装入机箱
    p->AddToPC(p1);
    p->AddToPC(p2);
    // p->AddToPC(p3);
    // p->AddToPC(p4);
    // p->AddToPC(p5);

    p->Work();  //输出各个部件的状态

}

//StudybarCommentEnd