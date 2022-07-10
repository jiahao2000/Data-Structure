/**
 * @file BinaryTree.cpp
 * @author jiahao
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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


void visit(BiTNode *T){
    printf("%d",T->data);
}

//先序遍历（preorder)
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历(InOrder)
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

//后序遍历 (PostOrder)
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

bool push(Stack &S,BiTree x){
    if(S.top == MaxSize-1)
        return false;
    S.data[++S.top] = x;
    return true;
}
BiTree pop(Stack &S){
    if(S.top != -1)
        return  S.data[S.top--];
}

void InitStack(Stack &S){
    BiTree x;
    S.top = -1;//代表栈为空
    while(scanf("%d",&x)!=EOF){
        S.data[++S.top] = x;//元素入栈
    }
}

bool IsEmpty(Stack s){
    if(s.top == -1){
        return true;
    }
    else 
        return false;
}

//中序遍历的非递归算法
void InOrder2(BiTree T){
    Stack S;
    InitStack(S);
    BiTree p = T;
    while(p||!IsEmpty(S)){
        if(p){
            push(S,p);
            p = p->lchild;
        }
        else{
            p = pop(S);
            visit(p);
            p = p->rchild;
        }
        
    }
}

//先序遍历的非递归算法
void PreOrder2(BiTree T){
    Stack S;
    InitStack(S);
    BiTree p = T;
    while(p||!IsEmpty(S)){
        if(p){
            visit(p);
            push(S,p);
            p = p->lchild;
        }
        else{
            p = pop(S);
            p = p->rchild;
        }
        
    }
}


//后序遍历的非递归算法
void PostOrder2(BiTree T){
    Stack S;
    InitStack(S);
    BiTree p = T;
    push(S,p);
    while(p||!IsEmpty(S)){
        if(p){
            push(S,p);
            p = p->lchild;
        }
        else{
            p = GetTop(S);//获得栈顶元素但不出栈
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

//层次遍历
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}
