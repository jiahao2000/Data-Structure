#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

#define elemtype int

struct stack{
    elemtype data[MaxSize];
    int top1;
    int top2;
};

stack s;

int push(int i ,elemtype x){
    if(i<0||i>1){
        printf("栈号输入错误");
        return 1;
    }
    if(s.top1 == s.top2-1){
        printf("栈已满");
        return 1;
    }
    
    switch(i){
        case 0:s.data[++s.top1] == x;return 0; break;
        case 1:s.data[--s.top2] == x;return 0;
    }
}

elemtype pop(int i){
    if(i<0||i>1){
        printf("栈号输入错误");
        return 1;
    }
    switch(i){
        case 0: 
            if(s.top1 == -1)
            {
                printf("栈一为空\n");
                return -1;
            }
            else
                return s.data[s.top1--];
            break;
        case 1:
            if(s.top2 == MaxSize)
            {
                printf("栈二为空\n");
            }
            else
                return s.data[s.top2++];
            break;
    }

}
