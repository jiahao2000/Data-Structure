/**
 * @file SqQueue.cpp
 * @author jia hao
 * @brief 
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
#define ElemType int

typedef struct
{
    ElemType data[MaxSize];
    int front;
    int rear;//队尾下标指向最后一个元素的后一个位置
}SqQueue;

void InitSqQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){
    if(isEmpty(Q)){
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}

int main(){


    return 0;
}