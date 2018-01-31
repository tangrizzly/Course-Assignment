//
//  main.cpp
//  lab2_1
//
//  Created by Tangrizzly on 24/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <string>
#include <stdio.h>

template<class T>
struct snode {
    T nodedata;
    snode *next;
};

template <class T>
class stack {
protected:
    int ssize;                  //定义栈长
    snode<T> *top;              //定义栈顶指针
    bool allocateerror;
    stack &copy (stack &s);     //栈拷贝函数
public:
    stack();
    stack(stack &s) {top=NULL; copy(s);}
    ~stack() {clears();}
    bool getallocateerror() {return allocateerror;}
    void push(T &);             //节点入栈
    bool pop(T &);              //节点出栈
    bool isempty() {return (ssize==0?true:false);}
    void clears();
    stack &operator = (stack &s) {copy(s); return *this;}
    //重载赋值运算符
};

template<class T>
stack<T>::stack(){
    ssize = 0;
    allocateerror = false;
    top = NULL;
}

template<class T>
stack<T> &stack<T>::copy(stack<T> &s) {
    //将栈s复制给当前栈对象
    snode<T> *p, *q, *r;
    if (top) clears();
    ssize = s.ssize;
    allocateerror = false;
    top = NULL;
    if (!s.top) return *this;   //若栈为空，则返回
    top = new snode<T>;         //为栈顶节点分配存储空间
    if (!top) {                 //若分配失败则返回
        allocateerror = true;
        return *this;
    }
    top->nodedata = s.top->nodedata;
    top->next = NULL;
    r = NULL;
    p = top;
    q = s.top->next;
    while (q) {
        r = new snode<T>;
        if (!r) {
            allocateerror = true;
            return *this;
        }
        r->nodedata = q->nodedata;
        r->next = NULL;
        p->next = r;
        p = p->next;
        q = q->next;
    }
    return *this;
}

template<class T>
void stack<T>::push(T &x) {
    snode<T> *p;
    p = new snode<T>;
    if (!p) {
        allocateerror = true;
        return;
    }
    p->nodedata = x;
    if (top) p->next = top;     //栈非空, 节点链接到栈顶指针之前
    else p->next = NULL;
    top = p;                    //修改栈顶指针
    ssize++;
}

template<class T>
bool stack<T>::pop(T  &x)               //从栈顶取一结点
{ snode<T>   *p;
    if (top)                            //若栈非空
    { x = top->nodedata;                  //将栈顶的数据内容赋给x
        p = top;
        top = top->next;                   //修改栈顶指针
        delete p;                     //删除原头结点
        ssize--;                    //长度减1
        return   true;
    }
    return false;
}

template<class T>
void stack<T>::clears()             //将栈清空
{
    T p;
    allocateerror=false;
    while (pop(p));                 //循环提取栈中各结点,实现清除
    top=NULL;
};

class staff{                           //定义职工类
public:
    char  name[80];
    int  age;
    float  salary;
    char  sex[8];
    void  assign(char  *name, int  age,  float  salary,  char  *sex) {
        strcpy(staff::name,name);
        staff::age=age;
        staff::salary=salary;
        strcpy(staff::sex,sex);
    }
    void print() {printf("%10s%6d%10.2f%8s\n",name,age,salary,sex);}
};

void  views(stack<staff> &s) {      //显示实例化后的栈s中的各结点
    int i=1;
    staff p;
    stack<staff> scopy(s);          //定义stack<staff>类的临时对象scopy
    //把形参que传给它
    //clrscr();                //DOS的函数windows不能执行
    while(scopy.pop(p))               //循环提取队列中各结点
    {    // gotoxy(1, i+5);    //DOS的函数windows不能执行
        printf("%2d:", i++);
        p.print();
    }
}

int  main() {
    stack<staff>  s;                    //定义队列类对象s
    staff  p;                           //定义职工类对象p
    p.assign("陈伟林",47,1500,"男");     //给p对象赋值
    s.push(p);                          //将p对象入栈s
    p.assign("王凌",34,850.5,"男");
    s.push(p);
    p.assign("张大霖",27,1200,"男");
    s.push(p);
    p.assign("方丽碧",51,2000,"女");
    s.push(p);
    views(s);                           //显示栈中的各结点
    return 0;
}
