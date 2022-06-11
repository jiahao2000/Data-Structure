/*
* File   : LinkList.cpp  *
* Author : jiahao        *
* Date   : 2022-6-11     *
*/

#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;

}LNode, *LinkList;
//头插法建立单链表

void PrintList(LinkList L){
	L = L->next;
	while(L!=NULL){
		printf("%d",L->data);
		L = L->next;
	}
}

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
	while (scanf("%d",&x)!=EOF) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
	}
	r->next = NULL;//尾节点指针置空
	return L;
}

//按序号查找节点值
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

//按值查找节点表
LNode* LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

//插入节点操作
void InsertNode(LinkList& L, int i) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	int x;
	LNode* p = GetElem(L, i - 1);
	scanf("%d", &x);
	s->data = x;
	s->next = p->next;
	p->next = s;
}

//求表长
int getLength(LinkList L) {
	int i = 0;
	LNode* s = L;
	while (s) {
		s = s->next;
		i++;
	}
	return i;
}

//双链表
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
} DNode, *DLinkList;



int main() {
	LinkList L;
	List_HeadInsert(L);
	PrintList(L);
	printf("%d", getLength(L));
	return 0;
}