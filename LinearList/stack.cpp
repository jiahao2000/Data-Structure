#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    int x;
    S.top = -1;//代表栈为空
    while(scanf("%d",&x)!=EOF){
        S.data[++S.top] = x;//元素入栈
    }
}
bool StackEmpty(SqStack S){
    if(S.top == -1)
        return true;
    return false;
}
bool push(SqStack &S,int x){
    if(S.top == MaxSize-1)
        return false;
    S.data[++S.top] = x;
    return true;
}
int pop(SqStack &S){
    return  S.data[S.top--];
}
int main(){
    SqStack S;
    InitStack(S);
    bool flag = StackEmpty(S);
    if(flag == true){
        printf("栈是空的");
    }
    
}