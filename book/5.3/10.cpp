#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;



int i = 1;

ElemType Preorder(BiTree B, int k){
    
    int result;

    if(B ==NULL){
       return '#';
    }

    if(i == k)
        return B->data;
    i++;
    
    result = Preorder(B->lchild, k);
    if(result != '#')
        return result;
    result = Preorder(B->rchild, k);
        return result;
}