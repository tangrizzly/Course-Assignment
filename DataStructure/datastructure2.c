#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAXSIZE 1024
typedef struct node{
    char opt;
    float fval;
    struct node* next;
}snode,*slink;//栈定义

void Lclearstack(slink *ptop){
    slink p;
    while(*ptop!=NULL){
        p=*ptop;
        *ptop=(*ptop)->next;
        free(p);
    }
}
int Lemptystack(slink top){//判断栈是否为空
    if(top==NULL) return 1;
    else return 0;
}
void Lpush(slink *ptop,char opt,float fval){
    slink p=(slink)malloc(sizeof(snode));
    p->opt=opt;
    p->fval=fval;
    p->next=*ptop;
    *ptop=p;
}
void Lgetstop(slink top,char* opt,float* fval){//取栈顶元素
    if(Lemptystack(top)) {*opt='#';*fval=-1;}
    else {
        *opt=top->opt;
        *fval=top->fval;
    }
}
void Lpop(slink *ptop,char* opt,float* fval){//退栈
    slink p;
    if(Lemptystack (*ptop)){*opt='#';*fval=-1;}
    else{
        *opt=(*ptop)->opt;
        *fval=(*ptop)->fval;
        p=*ptop;
        *ptop=(*ptop)->next;
        free(p);}
}

void Compute(char a[],float* result){
    int i=0;
    int j;
    float x,y,k;
    char temp = '\0';
    char p[100];
    slink S=NULL;
    Lclearstack(&S);
    while(a[i]!='#'){
        if(a[i]=='+') {Lpop(&S,&temp,&x);Lpop(&S,&temp,&y);Lpush(&S,temp,x+y);i++;}
        else if(a[i]=='-') {Lpop(&S,&temp,&x);Lpop(&S,&temp,&y);Lpush(&S,temp,y-x);i++;}
        else if(a[i]=='*') {Lpop(&S,&temp,&x);Lpop(&S,&temp,&y);Lpush(&S,temp,y*x);i++;}
        else if(a[i]=='/') {Lpop(&S,&temp,&x);Lpop(&S,&temp,&y);Lpush(&S,temp,y/x);i++;}
        else if('0'<=a[i]&&a[i]<='9'){
            j=0;
            while(a[i]!=' '&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='#'){
                p[j]=a[i];j++;i++;
            }
            if(a[i]==' ')i++;
            p[j]='\0';
            k=atof(p);//将字符串转换为单精度浮点型值
            //printf("k=%f\n", k);
            Lpush(&S,temp,k);
        }
        else i++;
    }
    Lgetstop(S,&temp,result);
}

void Convert(char a[],char b[]){
    int i,j;
    slink S = NULL;
    char y;
    float temp = 0.0;
    for(i=0,j=0;a[i]!='#';i++){
        if(('0'<a[i]&&a[i]<'9')||a[i]=='.') {b[j]=a[i];j++;}
        else if(a[i]=='(') Lpush(&S,a[i],temp);
        else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/') {
            b[j]=' ';
            j++;
            while(1){
                if(Lemptystack(S)) break;
                else{
                    Lgetstop(S,&y,&temp);
                    if(y=='(') break;
                    if((y=='+'||y=='-')&&(a[i]=='*'||a[i]=='/')) break;
                    Lpop(&S,&b[j],&temp);
                    j++;
                }
            }
            Lpush(&S,a[i],temp);
        }
        else{
            Lpop(&S,&a[i],&temp);
            while(a[i]!='('&&a[i]!='#'){
                b[j]=a[i];
                j++;
                Lpop(&S,&a[i],&temp);
            }
        }
    }
    while(!Lemptystack(S)){
        Lpop(&S,&b[j],&temp);
        j++;
    }
    b[j]='#';
}

int IfLegal(char a[]){
    int i,j;
    if(a[0]=='#') {
        printf("计算表达式出错！");
        return 0;}
    for(i=0;a[i]!='#';i++){
        switch (a[i]) {
            case ' ':{
                for(j=i;a[j]!='#';j++){
                    a[j]=a[j+1];
                }
                i--;
            }// 去掉所有空格
            case '.':break;
            case '+':break;
            case '-':break;
            case '*':break;
            case '/':break;
            case '(':break;
            case ')':break;
            case '0':break;
            case '1':break;
            case '2':break;
            case '3':break;
            case '4':break;
            case '5':break;
            case '6':break;
            case '7':break;
            case '8':break;
            case '9':break;
            default:{
                printf("The expression is ilegal, pleace retry.\n");
                return 0;
            }
        }
    }
    printf("legal\n");
    return 1;
}

int start()//判断是否开始
{
    int d;
    do{
        printf("是否计算表达式(1/0)?");
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

void input(char a[])
{
    int d;
    do{
        printf("\n选择输入方式(1键入/2读取txt)：");
        scanf("%d",&d);
    }while(d!=1&&d!=2);
    if(d==1){
        scanf("%s",a);
    }
    else{
        FILE *f=fopen("/Users/touhomaregen/Desktop/2.txt","r");
        if (f == NULL)
        {
            printf ("文件打开失败!\n");
            exit (-1); //标记出错位置,需要包含头文件stdlib.h
        }
        fscanf(f,"%s",a);
        printf("a=%s\n",a);
        fclose(f);
    }
}

int main(){
    char a[100]="0",b[100]="0";
    float c;
    while(start()) {
        input(a);
        //printf("%s\n", a);
        if(IfLegal(a)){
            Convert(a,b);
            printf("%s\n",b);
            Compute(b,&c);
            printf("%f\n ",c);
        }
    }
    return 0;
}
