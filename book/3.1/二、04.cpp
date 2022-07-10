

#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;

}LNode, *LinkList;

int dc(LinkList L, int n){
    int i;
    char s[n/2];
    LNode *p = L->next;
    for(i = 0;i<n/2;i++){
        s[i] = p->data;
        p=p->next;
    }
    i--;
    if(n%2 == 1){
        p = p->next;
    }
    while(p!=NULL&&s[i] == p->data){
        i--;
        p=p->next;
    }
    if(i==-1){
        return 1;
    }
    else 
    {
        return 0;
    }
}