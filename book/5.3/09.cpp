#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//递归方法
//首先交换b的左孩子的左右子树、再交换b的右孩子的左右子树、最后交换b的左右子树

void swap(BiTree T){
    if(T){
        swap(T->lchild);
        swap(T->rchild);
        BiTree p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }
}