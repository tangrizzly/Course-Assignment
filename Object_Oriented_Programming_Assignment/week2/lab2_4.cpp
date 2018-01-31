//
//  main.cpp
//  lab2_4
//
//  Created by Tangrizzly on 24/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//


#include <iostream>
#include <unistd.h>
using namespace std;

class user{                           //定义用户类
private:
    char name[80];
    int priviledge;
public:
    char* getname() {return name;}
    int checkP() {return priviledge;}
    void  assign(char  *name, int priviledge)
    {  strcpy(user::name,name);
        user::priviledge=priviledge;
    }
    void  print()
    {  printf("%10s%6d\n",name, priviledge);  }
};

class printer {
    friend void thePrinter(user T);
private:
    printer();
    int state;
public:
    printer(int s):state(s) {}
    int checkstate() {return state;}
    void usingprinter() {state = 1;cout<<"start printing."<<endl;}
    void finishprinting() {state = 0;cout<<"Stop printing."<<endl;}
};


template<class T>
struct quenode {                 //定义队列中的各结点类型
    T nodedata;
    quenode *next;
};
template <class T>
class  queue {
protected:
    int  quesize;                 //定义队列长度
    quenode<T>  *head;            //定义队列列头
    quenode<T>  *tail;            //定义队列列尾
    bool allocateerror;
    queue   &copy (queue  &q);    //队列拷贝函数
public:
    queue();                     //构造函数
    queue(queue &q){ head=NULL;tail=NULL; copy(q);}//建q 队列
    ~queue()  { clearque(); }
    bool  getallocateerror()  { return  allocateerror;  }
    void push(T &);                //将结点插入队尾
    bool pop(T &);                 //队头取结点
    bool isempty() { return  (quesize==0)? true: false;}
    //判断队列是否为空
    void clearque();               //清空队列
    queue &operator= (queue &q) {  copy(q);  return  *this;  }
    //重载赋值运算符
};
template<class T>
queue<T>::queue()                       //定义构造函数
{  quesize=0;
    allocateerror=false;
    head=NULL;
    tail=NULL;
}
template<class T>
queue<T> &queue<T>::copy(queue<T> &que)
//将队列que复制给当前队列对象
{ quenode<T>  *p,  *q,  *r;
    if (head)  clearque();
    quesize=que.quesize;                  //传递队列长度
    allocateerror=false;
    head=NULL;
    tail=NULL;
    if (!que.head)  return *this;         //若队列为空，则返回
    head=new quenode<T>;                  //为队列头结点分配存储空间
    if (!head)                            //若分配失败，则返回
    {  allocateerror=true;
        return  *this;
    }
    head->nodedata=que.head->nodedata;
    //将que队列头结点值赋给当前队列头结点
    head->next=NULL;
    tail=head;                     //将队列尾也指向此结点
    r=NULL;
    p=head;                        //p 指针也指向此结点
    q=que.head->next;              //q 指针指向que队列的第二个结点
    while (q)
    { r=new  quenode<T>;           //为结点r 分配存储空间
        if(! r )
        {  allocateerror=true;
            return  *this;
        }
        r->nodedata=q->nodedata;
        r->next=NULL;
        p->next=r ;              //将结点 r 链接到当前队列的链上
        tail=r ;                 //队尾指针指向 r，因为r为最后一个结点
        p=p->next;               //指针后移
        q=q->next;
    }
    return  *this;
}

template<class  T>
void  queue<T>::push(T  &x)             //向队尾插入结点
{ quenode<T>   *p;
    p=new  quenode<T>;                    //为 p 结点分配存储空间
    if( !p )                              //若分配失败，则返回
    {  allocateerror=true;
        return;
    }
    p->nodedata=x;
    if (tail)                             //若队列非空
    {
        tail->next=p;
        tail=tail->next;
        tail->next=NULL;
    }
    else                                   //若队列为空
    { p->next=NULL;
        head=p;                            //p结点为队列的头，又为尾
        tail=p;
    }
    quesize++;                            //长度加1
}

template<class T>
bool queue<T>::pop(T  &x)               //从队头取一结点
{ quenode<T>   *p;
    if (head)                            //若队列非空
    { x=head->nodedata;                  //将队头的数据内容赋给x
        p=head;
        head=head->next;                   //修改队头指针
        if (head==NULL)              //若队列已删空，则tail也改为 NULL
            tail=NULL;
        delete p;                     //删除原头结点
        quesize--;                    //长度减1
        return   true;
    }
    return false;
}

template<class T>
void  queue<T>::clearque()             //将队列清空
{ T    p;
    allocateerror=false;
    while (pop(p)) ;                 //循环提取队列中各结点,实现清除
    head=tail=NULL;
};

void  viewque(queue<user>  &que)//显示实例化后的队列que中的各结点
{
    int i=1;
    user p;
    queue<user>  quecopy(que);//定义queue<staff>类的临时对象quecopy
    while(quecopy.pop(p))               //循环提取队列中各结点
    {
        printf("%2d:", i++);
        p.print();
    }
}

queue<user>  Q1,Q2,Q3;

void thePrinter(user T) {
    static printer Printer(0);
    cout << T.getname();
    Printer.usingprinter();     //使用打印机
    usleep(1000000);            //正在使用，延迟10秒
    Printer.finishprinting();   //停止使用打印机
}

void apply(user T) {
    //将请求对象按优先级插入等待队列
    cout << T.getname() << " applys to use the printer." << endl;
    if (T.checkP() == 1) {        //教师插入一级优先级队列
        Q1.push(T);
    } else if (T.checkP() == 2) {    //学生插入二级优先级队列
        Q2.push(T);
    } else {
        Q3.push(T);          //电脑插入三级优先级队列
    }
}

void checkline() {  //检查打印机是否有人等待
    user T;
    while (!Q1.isempty()) {         //当一级优先级队列不为空时
        Q1.pop(T);                  //队头出栈
        thePrinter(T);              //使用打印机
    }
    while (!Q2.isempty()) {         //当一级优先级队列为空且二级不为空时
        Q2.pop(T);                  //队头出栈
        thePrinter(T);              //使用打印机
    }
    while (!Q3.isempty()) {         //当一二级优先级队列为空且三级不为空时
        Q3.pop(T);                  //队头出栈
        thePrinter(T);              //使用打印机
    }
}

int main()
{
    user u1,u2,u3;
    u1.assign("Teacher1",1);
    u2.assign("Student1",2);
    u3.assign("Computer1",3);
    apply(u2);       //Student1申请使用打印机，将其插入等待队列
    apply(u1);       //Teacher1申请使用打印机，将其插入等待队列
    //没有其他人申请打印机
    checkline();
    apply(u3);
    checkline();
    return 0;
}
