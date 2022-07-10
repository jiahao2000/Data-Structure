#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
#define ElemType int
typedef struct Queue
{
    ElemType data[MaxSize];
    int front;
    int rear;
    int tag;
} Queue;

void InitQueue(Queue &Q){
    Q.front = -1;
    Q.rear = -1;
    Q.tag = 0;
}
