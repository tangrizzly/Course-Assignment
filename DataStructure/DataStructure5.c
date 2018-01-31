/*建立有向图的十字链表存储结构，利用拓扑排序方法判断该图是否为有向无环图。
 要求：有向图的顶点信息和弧信息可以从键盘或txt文件输入，输入格式自拟。*/

#include "stdlib.h"
#include "stdio.h"

#define MAXN 1024
typedef char vtype;
typedef struct Anode//弧节点
{
    int tail,head;
    struct Anode *hlink,*tlink;
}arcnode;
typedef struct Vnode//顶点
{
    vtype data;
    arcnode *fin,*fout;
}vexnode;
vexnode G[MAXN];

typedef struct node
{
    int i;
    struct node*next;
}snode,*slink;


void Lclearstack(slink *ptop){
    slink p;
    while(*ptop!=NULL){
        p=*ptop;
        *ptop=(*ptop)->next;
        free(p);
    }
}
int Lemptystack(slink top){
    if(top==NULL) return 1;
    else return 0;
}

void Lpush(slink *ptop,int i){
    slink p=(slink)malloc(sizeof(snode));
    p->i=i;
    p->next=*ptop;
    *ptop=p;
}

void Lpop(slink *ptop,int *i){
    slink p;
    if(Lemptystack(*ptop)){*i=-1;}
    else{
        *i=(*ptop)->i;
        p=*ptop;
        *ptop=(*ptop)->next;
        free(p);
    }
}

void Lgetspop(slink top,int *i){
    if(Lemptystack(top)){*i=-1;}
    else *i=top->i;
}


int locatevex(vexnode G[],int n,char c){
    int i;
    for(i=0;i<n;i++){
        if(G[i].data==c) return i;
    }
    return -1;
}

//建立有向图十字链表
int createorlist(vexnode G[])
{
    int d,i=0,n=0,j;
    arcnode *p;
    vtype ch,u='\0',v = '\0';
    do{
        printf("选择输入方式(1键入/2读取txt)：");
        scanf("%d",&d);
    }while(d!=1&&d!=2);
    getchar();
    if(d==1){
        printf("输入节点信息：\n");
        scanf("%c",&ch);
        while(ch!='#'){
            n++;
            G[i].data=ch;
            G[i].fin=G[i].fout=NULL;
            i++;
            scanf("%c",&ch);
        }
        printf("\n输入弧信息：");
        getchar();
        scanf("%c%c",&u,&v);
        while(u!='#'&&v!='#'){
            if(locatevex(G,n,u)!=-1) i=locatevex(G,n,u);
            else{
                printf("error");
                return -1;
            }
            if(locatevex(G,n,v)!=-1) j=locatevex(G,n,v);
            else{
                printf("error");
                return -1;
            }
            p=(arcnode*)malloc(sizeof(arcnode));
            p->tail=i;p->head=j;
            p->tlink=G[i].fout;
            G[i].fout=p;
            p->hlink=G[j].fin;
            G[j].fin=p;
            scanf("%c%c",&u,&v);
        }
    }
    else{
        FILE *f=fopen("/Users/touhomaregen/Desktop/5.txt","r");
        if (f == NULL)
        {
            printf ("文件打开失败!\n");
            exit (-1); //标记出错位置,需要包含头文件stdlib.h
        }
        fscanf(f,"%c",&ch);
        while(ch!='#'){
            n++;
            G[i].data=ch;
            G[i].fin=G[i].fout=NULL;
            i++;
            fscanf(f,"%c",&ch);
        }
        getchar();
        fscanf(f,"%c%c",&u,&v);
        while(u!='#'){
            if(locatevex(G,n,u)!=-1) i=locatevex(G,n,u);
            else{
                printf("error");
                return -1;
            }
            if(locatevex(G,n,v)!=-1) j=locatevex(G,n,v);
            else{
                printf("error");
                return -1;
            }
            p=(arcnode*)malloc(sizeof(arcnode));
            p->tail=i;p->head=j;
            p->tlink=G[i].fout;
            G[i].fout=p;
            p->hlink=G[j].fin;
            G[j].fin=p;
            fscanf(f,"%c%c",&u,&v);
        }
        fclose(f);
    }
    return n;
}

//建立顶点入度表id，顶点数为n
void Creatid(vexnode G[],int n,int id[]){
    int count,i; arcnode *p;
    printf("各节点入度为：");
    for(i=0;i<n;i++){
        id[i]=0;count=0;
        p=G[i].fin;
        while(p){count++;p=p->hlink;}
        id[i]=count; printf("%c:%d;",G[i].data,id[i]);
    }
}
//对网G拓扑排序
void Topsort(vexnode G[],int n){
    int i,j=0,k,count,id[n];
    arcnode *p;slink s=NULL;
    Creatid(G,n,id);
    Lclearstack(&s);
    for(i=0;i<n;i++)
        if(id[i]==0) Lpush(&s,i);
    count=0;
    printf("\nOutput:");
    while(!Lemptystack(s)){
        Lpop(&s,&j);
        printf("%d %c;",j,G[j].data);
        count++;p=G[j].fout;
        while(p){
            k=p->head;
            id[k]--;
            if(id[k]==0)Lpush(&s,k);
            p=p->tlink;
        }
    }
    if(count==n) printf("\nThis graph has no cycles.\n");
    else printf("\nThis graph has cycles.\n");
}

int start()//判断是否开始
{
    int d;
    do{
        printf("是否开始输入(1/0)?");
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
    while(start()) {
        int n;
        vexnode G[MAXN];
        n=createorlist(G);
        Topsort(G,n);
    }
    return 0;
}
