/*树表的查找：输入一个英文句子，按照字典顺序构造一棵二叉排序树；对此二叉排序树进行中序遍历，并将遍历序列输出到屏幕上。
 要求：
 （1）英文句子可从键盘输入，也可从txt文件输入；
 （2）遍历算法采用非递归遍历算法；
 （3）程序结束时需释放树空间。*/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
typedef struct Bsnode
{
    char word[20];
    struct Bsnode *Lchild,*Rchild;
}BSN,*BSP;

typedef struct node
{
    BSP T;
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

void Lpush(slink *ptop,BSP T){
    slink p=(slink)malloc(sizeof(snode));
    p->T=T;
    p->next=*ptop;
    *ptop=p;
}

void Lpop(slink *ptop,BSP *T){
    slink p;
    if(Lemptystack(*ptop)){T=NULL;}
    else{
        *T=(*ptop)->T;
        p=*ptop;
        *ptop=(*ptop)->next;
        free(p);
    }
}

void Lgetspop(slink top,BSP *Tree){
    if(Lemptystack(top)){*Tree=NULL;}
    else *Tree=top->T;
}

void BSTinsert(BSP *T,BSP S){//T为根，S为待插入节点的指针
    if(*T==NULL)*T=S;
    else{
        BSP p=*T,q=NULL;
        int i = 0;
        while(p){
            q=p;i=0;
            while(S->word[i]==p->word[i]&&S->word[i]!='\0'){
                i++;
            }
            if(S->word[i]=='\0'&&p->word[i]=='\0'){
                printf("(repeated word, not counting.) ");
                S=NULL;
                break;
            }
            else if(S->word[i]=='\0'||S->word[i]<p->word[i]) p=p->Lchild;
            else p=p->Rchild;
        }
        if(S!=NULL){
            if(S->word[i]=='\0'||S->word[i]<q->word[i]) q->Lchild=S;
            else q->Rchild=S;
        }
        else free(S);
    }
}

BSP GetLBtree(BSP *T){
    char ch[20];
    BSP p;
    int d,j,k;
    int stop=0;
    do{
        printf("\n选择输入方式(1键入/2读取txt)：");
        scanf("%d",&d);
    }while(d!=1&&d!=2);
    if(d==1){
        while(stop==0){
            scanf("%s",ch);
            for(j=0;j<20&&ch[j]!='\0';j++){
                if('A'<=ch[j]&&ch[j]<='Z')
                    ch[j]+=32;//单词大小写转换
                if(ch[j]=='.'){
                    ch[j]='\0';
                    stop=1;
                    break;
                }
                if(!('a'<=ch[j]&&ch[j]<='z'))
                    for(k=j;ch[k]!='\0';k++)
                        ch[k]=ch[k+1];
            }
            p=(BSP)malloc(sizeof(BSN));
            strcpy(p->word,ch);p->Lchild=p->Rchild=NULL;
            printf("%s ",p->word);
            BSTinsert(T,p);
        }
    }
    else{
        FILE *f=fopen("/Users/touhomaregen/Desktop/4.txt","r");
        if (f == NULL)
        {
            printf ("文件打开失败!\n");
            exit (-1); //标记出错位置,需要包含头文件stdlib.h
        }
        printf("Converted sentence: \n");
        while(stop==0){
            fscanf(f,"%s",ch);
            for(j=0;j<20&&ch[j]!='\0';j++){
                if('A'<=ch[j]&&ch[j]<='Z')
                    ch[j]+=32;//单词大小写转换
                if(ch[j]=='.'){
                    ch[j]='\0';
                    stop=1;
                    break;
                }
                if(!('a'<=ch[j]&&ch[j]<='z'))
                    for(k=j;ch[k]!='\0';k++)
                        ch[k]=ch[k+1];
            }
            p=(BSP)malloc(sizeof(BSN));
            strcpy(p->word,ch);p->Lchild=p->Rchild=NULL;
            printf("%s ",p->word);
            BSTinsert(T,p);
        }
        fclose(f);
    }
   	return *T;
}



void Inorder(BSP T){
    BSP p; slink s;
    Lclearstack(&s);
    Lpush(&s,T);
    while(!Lemptystack(s)){
        Lgetspop(s,&p);
        while(p){
            Lpush(&s,p->Lchild);
            Lgetspop(s,&p);
        }
        Lpop(&s,&p);
        if(!Lemptystack(s)){
            Lpop(&s,&p);
            printf("%s ",p->word);
            Lpush(&s,p->Rchild);
        }
    }
}

void ClearTree(BSP *T){
    BSP p,q; slink s=NULL;
    Lclearstack(&s);
    Lpush(&s,*T);
    while(!Lemptystack(s)){
        Lgetspop(s,&p);
        while(p){
            Lpush(&s,p->Lchild);
            Lgetspop(s,&p);
        }
        Lpop(&s,&p);
        if(!Lemptystack(s)){
            Lpop(&s,&p);
            q=p;
            p=p->Rchild;
            free(q);
            Lpush(&s,p);
        }
    }
}

int start()//判断是否开始
{
    int d;
    do{
        printf("是否开始输入文本(1/0)?");
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
    BSP T=NULL;
    while(start()) {
        GetLBtree(&T);
        printf("\nfinishing tree constructing.\nOutput:\n");
        Inorder(T);
        printf("\n");
    }
    ClearTree(&T);
    return 0;
}
//Justice is never given; it is exacted and the struggle must be continuous for freedom is never a fact, but a continuing evolving process to higher and higher levels of human, social, economic, political and religious relationship.
