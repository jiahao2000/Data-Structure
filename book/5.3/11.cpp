#include <stdlib.h>
#include <stdio.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void Delete(BiTree B)
{
    if (B)
    {
        Delete(B->lchild);
        Delete(B->rchild);
        free(B);
    }
}

void search(BiTree B, ElemType x)
{
    BiTree Q[];
    BiTree p;
    if (B)
    {
        if (B->data == x)
        {
            Delete(B);
            exit(0);
        }
        InitQueue(Q);
        EnQueue(Q, B);
        while (!IsEmpty(Q))
        {
            DeQueue(Q, p);
            if (p->lchild)
            { //当左子树不为空时
                if (p->lchild->data == x)
                {
                    Delete(p->lchild);
                    p->lchild == NULL;
                }
                else
                    EnQueue(Q, p->lchild);
            }
            if (p->rchild)
            {//当右子树不为空时
                if (p->rchild->data == x)
                {
                    Delete(p->rchild);
                    p->rchild = NULL;
                }
                else
                    EnQueue(Q, p->rchild);
            }
        }
    }
}