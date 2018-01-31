//
//  main.cpp
//  lab1_3
//  m people in a circle start counting from one and the person counting to n step out until there are no one.
//  output the number of the person stepping out.
//
//  Created by Tangrizzly on 14/11/2017.
//  Copyright © 2017 Tangrizzly. All rights reserved.
//

#include <iostream>
using namespace std;

//define datatype and the structure of the linknode
typedef int datatype;
typedef struct node{
    datatype number;
    struct node *next;
}linknode,*link;

//creat a circular linked list
link CreatList(int m, int n){
    link H,p,r;
    int i = 1;
    H = new linknode;
    H->number = i;
    r = H;
    while (i < m) {
        i++;
        p = new linknode;
        p->number = i;
        r->next = p;
        r = p;
    }
    r->next = H;
    return r; //r is the last person
}

//ouput the number of the person counting n
void Counting(link r, int n){
    int i=1;
    link q = r, p = r->next;
    FILE *f = fopen("01.out", "aw");
    while (p != q) {
        if (i%n==0) {
            q->next = p->next;
            fprintf(f, "%d, ", p->number);
            delete(p);
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
        i++;
    }
    fprintf(f, "%d\n", p->number);
    fclose(f);
}

void PKbyNo(int m, int n){
    link r = CreatList(m, n);
    Counting(r, n);
}

int main() {
    int m, n;
    FILE *f=fopen("01.in","r");
    if (f == NULL) {
        cout << "Failed" << endl;
        exit (-1);
    }
    while (!feof(f)) {
      fscanf(f, "%d %d", &m, &n);
      PKbyNo(m, n);
    }
    fclose(f);
    return 0;
}
