/**
 * @file LinkQueue.cpp
 * @author jia hao
 * @brief 
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdlib.h>

#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode *next;    
} LNode;

typedef struct LinkQueue
{
    /* data */
    LNode *front;
    LNode *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LNode*)malloc(sizeof(LNode));
    Q.front->next = NULL; //带头节点的链表，因此Q.front指向的位置不存储数据，从Q.front->next开始存储数据
}

bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else 
        return false;
}

void EnQueue(LinkQueue &Q, ElemType x){
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    if(IsEmpty(Q))
        return false;
    LNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;

}