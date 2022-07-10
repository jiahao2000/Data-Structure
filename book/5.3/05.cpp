#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//使用层序遍历

int TreeHeight(BiTree T){
    if(!T){
        return 0;
    }
    int front = -1, rear = -1;
    int last = 0,level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while(front<rear){
        p = Q[++front];
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        if(front == rear)
        {
            level++;
            last = rear; //更新last的位置
        }
    }

    return level;

}