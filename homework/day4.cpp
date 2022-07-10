#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;

}LNode, *LinkList;

void PrintList(LinkList L)

{

L=L->next;

while(L!=NULL)

{

printf("%d",L->data);//打印当前结点数据

L=L->next;//指向下一个结点

if(L!=NULL)

{

printf(" ");

}

}

printf("\n");

}
//头插法建立单链表
LinkList List_HeadInsert(LinkList &L) {
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); //建立头节点
	L->next = NULL; //初始化链表为空
	scanf("%d", &x); //输入插入的元素
	while (x != 9999) {			//输入9999表示结束
		s = (LNode*)malloc(sizeof(LNode)); //创建新节点
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

//尾插法创建单链表
LinkList List_TailInsert(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
    scanf("%d",&x);
	while (x!=9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
        scanf("%d",&x);
	}
	r->next = NULL;//尾节点指针置空
	return L;
}

//按序号查找节点值，头节点为第0个节点的值
LNode* GetElem(LinkList L, int i) {
	int j = 1;
	LNode* p = L->next; //将第一个节点指针赋给p
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p && j < i) {
		p = p->next; 
		j++;
	}
	return p;
}



int main(){
    LinkList L1,L2;
    List_HeadInsert(L1);
    PrintList(L1);
    return 0;
}