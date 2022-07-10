#include<stdio.h>
#include<stdlib.h>

#define MaxSize 1000

typedef struct stack{
    double data[MaxSize];
    int top;
}stack;

double funcP(int n, double x){
    if(n == 0)
    return 1;
    if(n == 1)
    return 2*x;
    stack S;
    double result = 0;
    S.top = -1;
    S.data[++S.top] = 1;
    S.data[++S.top] = 2*x;
    for(int i = 2;i<=n;i++){    
        result = 2*x*S.data[S.top] - 2*(i-1)*S.data[S.top-1];
        S.data[++S.top] = result;
    }

    return result;
}

int main(){

    double x = 2;
    for(int i = 0;i<10; i++)
    {
        printf("%12.6f\n",funcP(i,x));
    }




    return 0;
}