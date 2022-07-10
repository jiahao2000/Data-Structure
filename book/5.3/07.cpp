/*
考虑层序遍历
将节点依此放入队列中，遇到空节点时，检查其后是否有非空节点，若有，则说明不是完全二叉树
*/

#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


bool IsComplete(BiTree T){
    BiTree p;
    p = T;
    EnQueue(p);
    if(!T)
        return true;//空二叉树是完全二叉树
    while(!IsEmpty(Q)){
        p = DeQueue(Q);
        if(p){
            EnQueue(p->lchild);
            EnQueue(p->rchild); //此时会即使左右子树为空也会入队
        }
        else{                        //如果p为空，则停止入队，直接检查后面是否还有非空的元素
            while(!IsEmpty(Q)){
                p = DeQueue(Q);
                if(p)
                    return false;    //如果有非空元素在队列中，说明二叉树不是完全二叉树
            }
        }
    }
    return true;       
}