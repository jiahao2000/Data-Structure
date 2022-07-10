/*
* File   : DLinkList.cpp *
* Author : jiahao        *
* Date   : 2022-6-14     *
*/

#include<stdio.h>
#include<stdlib.h>

//双链表节点的定义
typedef struct DNode {
	int data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintDList(DLinkList DL){
	DL = DL->next;
	while(DL!=NULL){
		printf("%3d",DL->data);
		DL = DL->next;
	}
	printf("\n");
}
//头插法建立新的双链表
DLinkList Dlist_head_insert(DLinkList &DL){
	DNode *s = (DNode*)malloc(sizeof(DNode));
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));
	DL->next =NULL;
	DL->prior = NULL;
	scanf("%d",&x);
	s->data = x;
	s->next = DL->next;
	s->prior = DL;
	DL->next = s;
	scanf("%d",&x);
	while(x != 9999){
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		s->prior = DL;
		DL->next->prior = s;
		DL->next = s;
		scanf("%d",&x);
	}

	return DL;
}
//尾插法建立双链表
DLinkList Dlist_tail_insert(DLinkList &DL){
	DL = (DLinkList)malloc(sizeof(DNode));
	int x;
	DNode *s, *r;
	r = DL;
	scanf("%d",&x);
	while(x!=0){
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;//尾节点的next指针赋值为NULL
	return DL;
}

int main(){
	DLinkList DL;
	Dlist_head_insert(DL);
	PrintDList(DL);


	return 0;
}