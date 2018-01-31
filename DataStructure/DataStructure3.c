#include "stdlib.h"
#include "stdio.h"
#include <string.h>

typedef struct node//定义队列节点
{
    char data;
    struct node *next;
}Qnode,*Qlink;
typedef struct{
    Qnode *front,*rear;
}linkqueue;

void Lcreatqueue(linkqueue *q)//创建带头节点的队列
{
    q->front=q->rear=(Qlink)malloc(sizeof(Qnode));
    q->front->next=NULL;
}

int Lemptyqueue(linkqueue *q){
    return(q->front==q->rear);
}

void Lenqueue(linkqueue *q, char e){
    Qlink p=(Qlink)malloc(sizeof(Qnode));
    p->data=e;
    q->rear->next=p;
    q->rear=p;
    p->next=NULL;
}

int Ldequeue(linkqueue *q,char *pe){
    Qlink p;
    if(Lemptyqueue(q)) return(-1);
    p=q->front;
    q->front=p->next;
    free(p);
    *pe=q->front->data;
    return 0;
}

int start()//判断是否开始
{
    int d;
    do{
        printf("是否开始入队(1/0)?");
        scanf("%d",&d);
        if (!d) {
            printf("\n结束程序");
            return 0;
        }
        else if(d) return 1;
        else printf("\n错误\n");
    }while(d!=0&&d!=1);
    return 0;
}


int main(){
    linkqueue Q;
    Lcreatqueue(&Q);
    char c;
    while(start()){
        printf("\n开始输入字符：\n");
        do{
            c=getchar();
        }while(c=='\n');
        Lenqueue(&Q,c);
        while(c!='@'){
            if(c=='0'){
                Ldequeue(&Q,&c);
                printf("出队：%c\n",c);
            }
            do{
                c=getchar();
            }while(c=='\n');
            Lenqueue(&Q,c);
        }
        printf("所有元素出队：");
        while(Ldequeue(&Q,&c)==0){
            printf("%c ",c);
        }
    }
    return 0;
}
