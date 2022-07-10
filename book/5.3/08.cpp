#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//非递归算法
int function(BiTree T){
    InitQueue(Q);
    int sum = 0;
    BiTree p = T;
    if(!T)
        return 0;
    EnQueue(Q,p);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
        if(p->lchild!=NULL&&p->rchild!=NULL)
            sum++;
    }
    
}

//递归算法
int function2(BiTree T){
    if(T == NULL) //当节点为空时，返回零
        return 0;
    if(T->lchild !=NULL&&T->rchild!=NULL)
        return function2(T->lchild) + function2(T->rchild)+1; //当该节点为双分支节点时返回左右子树的双分支节点数并加一
    else
        return function2(T->lchild) + function2(T->rchild);//当该节点为单分支节点或叶子节点时，返回左右子树的双分支节点数
}