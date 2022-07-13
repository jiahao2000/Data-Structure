//使用非递归的后序遍历，

#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
    bool r;
}BiTNode,*BiTree;

typedef struct Stack
{
    BiTree data[MaxSize];
    int top;
    /* data */
}Stack;

void func(BiTree B){
    Stack S;
    InitStack(S);
    BiTree  p = B;
    while(p||!IsEmpty(S)){
        if(p){
            Push(S,p);
            p=p->lchild;
        }
        else{
            p = GetTop(S);
             if(p->rchild == NULL || p->r == true)
                {
                    visit(p);
                    pop(S);
                }
            else{
                p->r = true;//将p的右孩子是否被访问过置为true
                p = p->rchild;
                push(S,p);
            }
        }
    }
}