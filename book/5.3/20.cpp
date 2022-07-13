#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data[10];
    struct node *left, *right;
} BTree;

void BTreeToE(BTree *root){
    BTreeToExp(root, 1);
}

void BTreeToExp(BTree *root, int deep){
    if(root == NULL) return ;//空节点直接返回
    else if(root->left == NULL && root->right ==NULL)
        printf("%s",root->data);//如果为叶子节点，则输出操作数，不加括号
    else{
        if(deep > 1) printf("(");//如果不是根节点，且有子节点，则打印一个 （
        BTreeToExp(root->left,deep+1);//不需要判断左右孩子是否为空，因为函数首先会判断节点是否为空，为空则直接返回，不打印
        printf("%s",root->data);    //打印当前节点中的数据
        BTreeToExp(root->right,deep+1);
        if(deep > 1) printf(")");
    }
}