#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

typedef int datatype;
typedef struct node
#define MAX 1024
{
    datatype data;
    struct node* next;
}linknode,*link;

int dtm_stablish()//判断是否开始建立链表
{
    int d;
    do{
        printf("是否建立链表(1/0)?");
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

link CreatList()
{
    int d,a;
    link H,p,r;
    do{
        printf("\n选择输入方式(1键入/2读取txt)：");
        scanf("%d",&d);
    }while(d!=1&&d!=2);
    H=(link)malloc(sizeof(linknode));
    r=H;
    if(d==1){
        scanf("%d",&a);
        while(a!=-1){
            p=(link)malloc(sizeof(linknode));
            p->data=a;
            r->next=p;
            r=p;
            scanf("%d",&a);
        }
    }
    else{
        FILE *f=fopen("/Users/touhomaregen/Desktop/1.txt","r");
        if (f == NULL)
        {
            printf ("文件打开失败!\n");
            exit (-1); //标记出错位置,需要包含头文件stdlib.h
        }
        fscanf(f,"%d",&a);
        while(a!=-1){
            p=(link)malloc(sizeof(linknode));
            p->data=a;
            r->next=p;
            r=p;
            fscanf(f,"%d",&a);
        }
        fclose(f);
    }
    r->next=NULL;
    return H;
}

link Max(link H){
    int i,k,m,sum=0;
    link q;
    link p[MAX];
    printf("\n输入k的值：");
    do{
        scanf("%d",&k);
        q=H->next;
        for(i=0;i<k&&q->next;i++){
            p[i]=q;
            sum+=q->data;
            q=q->next;}
        p[i]=q;
        sum+=q->data;
        if(i!=k||k>=MAX||k<=0) {printf("k错误,请重新输入：");sum=0;}
    }while(i!=k);
    while(q->next){
        m=0;
        for(i=0;i<k-1;i++){
            m+=p[i]->data;
            p[i]=p[i+1];
        }
        p[k-1]=q->next;
        q=q->next;
        m+=p[k-1]->data;
        if(m>sum)sum=m;
    }
    printf("\n%d\n",sum);
    return p[0];
}

int main()
{
    link H,r;
    while(dtm_stablish()) {
        H=CreatList();
        r=Max(H);
    }
    link temp;
    while(H != NULL){
        temp = H;
        H = H->next;
        free(temp);
    }
    return 0;
}
