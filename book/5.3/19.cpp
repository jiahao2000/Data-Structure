#include<iostream>

using namespace std;


typedef struct BiTNode{
    int weight;
    struct BiTNode *left,*right;
} BiTNode, *BiTree ;

//1、基于先序遍历的算法
int WPL(BiTree root){
    return wpl_PreOrder(root,0);
}

int wpl_PreOrder(BiTree root,int deep){
    static int sum = 0;//使用静态变量，使得sum不会被重复初始化，始终保持原来的值，且不会由于函数运行结束而被释放
    if(root->left == NULL && root->right == NULL)
    {
        sum+=root->weight * deep;//注意根节点的深度为0
        return sum;
    }
    if(root->left)
        wpl_PreOrder(root->left,deep+1);
    if(root->right)
        wpl_PreOrder(root->right,deep+1);
    return sum;
}

//使用层序遍历

#define MaxSize 200

int wpl_LevelOrder(BiTree root){
    BiTree Q[MaxSize]; //声明一个用于层序遍历的队列
    int end1, end2; //end1为头指针 end2为尾指针
    end1 = end2 = 0; //头指针指向队列第一个元素，尾指针指向队列最后一个元素
    int wpl = 0, deep = 0;
    BiTree lastNode; //用于记录当前层的最后一个节点
    BiTree NewLastNode; //用于记录下一层的最后一个节点
    lastNode = root;
    NewLastNode = NULL; //初始化下一层的最后一个节点为空
    Q[end2++] = root; //根节点入队
    while(end1 != end2){ //当队列不为空时进行循环
        BiTree t =Q[end1++];//队头元素出队
        if(t->left == NULL && t->right == NULL){//如果当前节点为叶子节点
            wpl += deep * t->weight;
        }
        if(t->left != NULL){
            Q[end2++] = t->left;
        }
        if(t->right != NULL){
            Q[end2++] = t->right;
        }
        if( t == lastNode){
            lastNode = Q[end2-1];
            deep++;
        }
    }
    return wpl;
}