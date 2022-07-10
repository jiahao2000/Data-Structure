#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree PreInCreat(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2){
    //l1,h1为先序的第一个和最后一个节点 l2,h2为中序的第一个和最后一个节点
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = A[l1];
    int i;
    for( i = l2 ; B[i]!=root->data; i++);
    int llen = i - l2; //左子树的长度
    int rlen = h2 - i; //右子树的长度
    if(llen){
        root->lchild = PreInCreat(A,B,l1+1,l1+llen,l2,l2+llen-1);
    }
    else{
        root->lchild = NULL;
    }
    if(rlen){
        root->rchild = PreInCreat(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
    }
    else{
        root->rchild = NULL;
    }
    return root;
}