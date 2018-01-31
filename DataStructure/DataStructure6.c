/*统计若干个大型英文txt文件（如英文小说）中所有单词出现的次数，并输出出现次数最多的前10个单词及其出现次数。假设
 单词字符定义为大小写字母、数字和下划线，其他字符均看作单词分隔符。
 要求：
 （1）自行设计合适的数据结构及相关算法；
 （2）程序运行结束时将txt文件名以及统计结果写入磁盘；
 （3）每次程序启动时（除了首次运行）将上次的结果读入内存、显示；
 （4）能根据用户选择实现重新初始化、查找某单词出现次数、追加统计、退出等功能。
 */

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
typedef struct Bsnode
{
    char word[50];
    int num;
    struct Bsnode *Lchild,*Rchild;
}BSN,*BSP;

typedef struct node
{
    BSP T;
    struct node*next;
}snode,*slink;

struct topwords{
    char word[50];
    int num;
};

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
                p->num++;//重复单词，出现次数加一
                //printf("%c:%d; ",p->word[i],p->num);
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

BSP GetLBtree(BSP *T){//从多个文件中读取单词，并构建二叉排序树
    char ch[50],chr[50]="\0";
    BSP p;
    int j;
    char str[1024];
    printf("输入打开文件的地址：");
    scanf("%s",str);
    while(str[0]!='#'){
        FILE *f=fopen(str,"r");
        if (f == NULL)
        {
            printf ("文件打开失败!\n");
            printf("\n继续输入打开文件的地址：");
            getchar();
            scanf("%s",str);
            continue;
        }
        //printf("Converted sentence: \n");//将句子转化，去除标点，并将大写全部转化成小写字母
        //假设单词字符定义为大小写字母、数字和下划线，其他字符均看作单词分隔符。
        if(fscanf(f,"%s",ch)==EOF) {break;}
        while(1){
            for(j=0;j<20&&ch[j]!='\0';j++){
                if('A'<=ch[j]&&ch[j]<='Z')
                    ch[j]+=32;//单词大小写转换
                if(!(('a'<=ch[j]&&ch[j]<='z')||'a'=='_'||('0'<=ch[j]&&ch[j]<='9'))){
                    ch[j]='\0';j++;
                    //for(k=0;j<50;j++)
                    //     chr[k]=ch[j];
                    //break;
                }
            }
            if(ch[0]!='\0'){
                p=(BSP)malloc(sizeof(BSN));
                strcpy(p->word,ch);
                p->Lchild=p->Rchild=NULL;
                p->num=1;//设置初始出现次数为1
                //printf("%s ",p->word);
                BSTinsert(T,p);
            }
            if(chr[0]=='\0'){
                if(fscanf(f,"%s",ch)==EOF)break;
            }
            else strcpy(ch,chr);
        }
        fclose(f);
        printf("\n继续输入打开文件的地址：");
        getchar();
        scanf("%s",str);
    }
    return *T;
}

void visit(BSP T, struct topwords word[]){
    int i,j;
    for(i=0;i<10;i++){
        if(T->num>word[i].num){
            for(j=9;j>i;j--){
                word[j].num=word[j-1].num;
                strcpy(word[j].word,word[j-1].word);
            }
            word[i].num=T->num;
            strcpy(word[i].word,T->word);
            break;
        }
    }
}

void Inorder(BSP T, struct topwords word[]){
    BSP p; slink s=NULL;
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
            visit(p,word);
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

void load(struct topwords word[]){
    int i;
    FILE *f=fopen("/Users/touhomaregen/Desktop/6.txt","r");
    if (f == NULL) {
        printf ("首次运行，文件不存在!\n");
        for(i=0;i<10;i++){
            word[i].num=0;
            word[i].word[0]='\0';
        }//初始化最大出现次数的单词序列
    }
    else {
        for(i=0;i<10;i++){
            fscanf(f,"%s %d\n",word[i].word,&word[i].num);
        }
        fclose(f);
        printf("读取上次统计结果：\n");
        for(i=0;i<10;i++){
            printf("%s:%d\n",word[i].word,word[i].num);
        }
    }
}

int sel(){
    int i;
    printf("选择进行的操作：重新初始化(1)、查找某单词出现次数(2)、追加统计(3)、退出(4)\n");
    scanf("%d",&i);
    return i;
}//判断是否开始//

int lookup(BSP T,char str[]){
    BSP p; slink s=NULL;
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
            if(!(strcmp(p->word,str))) return p->num;
            Lpush(&s,p->Rchild);
        }
    }
    return 0;
}

int main(){
    struct topwords word[10];
    int i,j;
    load(word);
    BSP T=NULL;
    char str[50]="\0";
    do{
        i=sel();
        switch (i) {
            case 1:
                printf("重新初始化：\n");
                for(j=0;j<10;j++){
                    word[j].num=0;
                    word[j].word[0]='\0';
                }
                GetLBtree(&T);
                printf("\nfinishing tree constructing.\n");
                Inorder(T,word);
                printf("\nOutput:\n");
                for(j=0;j<10;j++){
                    printf("%s:%d\n",word[j].word,word[j].num);
                }
                FILE *f=fopen("/Users/touhomaregen/Desktop/6.txt","wt+");
                for(j=0;j<10;j++){
                    fprintf(f,"%s %d\n",word[j].word,word[j].num);
                }
                fclose(f);
                break;
            case 2:
                printf("查找某单词出现次数:\n");
                scanf("%s",str);printf("%s",str);
                printf("出现的次数：%d\n",lookup(T,str));
                break;
            case 3:
                printf("追加统计:\n");
                BSP p; slink s=NULL;
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
                        for(j=0;j<10;j++){
                            if(strcmp(T->word,word[j].word)){
                                T->num=+word[j].num;
                                strcpy(word[j].word,T->word);
                                break;
                            }
                        }
                        Lpush(&s,p->Rchild);
                    }
                }
                GetLBtree(&T);
                printf("\nfinishing tree constructing.\n");
                Inorder(T,word);
                printf("\nOutput:\n");
                for(j=0;j<10;j++){
                    printf("%s:%d\n",word[j].word,word[j].num);
                }
                FILE *fx=fopen("/Users/touhomaregen/Desktop/6.txt","at");
                for(j=0;j<10;j++){
                    fprintf(fx,"%s %d\n",word[j].word,word[j].num);
                }
                fclose(fx);
                break;
            default:
                break;
        }
    }while(i==1||i==2||i==3);
    ClearTree(&T);
    return 0;
}
//"/Users/touhomaregen/Desktop/6.1.txt"
//"/Users/touhomaregen/Desktop/6.2.txt"
//"/Users/touhomaregen/Desktop/6.3.txt"

