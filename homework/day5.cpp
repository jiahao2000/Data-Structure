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

L = L->next;

while (L != NULL)

{

printf("%3d", L->data);//打印当前结点数据

L = L->next;//指向下一个结点

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
//插入节点操作
void InsertNode(LinkList& L, int i) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	int x = 99;
	LNode* p = GetElem(L, i - 1);
	//scanf("%d", &x);
	s->data = x;
	s->next = p->next;
	p->next = s;
}

//删除节点操作,删除第i个位置的操作
bool DeleteNode(LinkList &L,int i){
	LNode *p = GetElem(L,i-1);
	if( p == NULL || p->next == NULL)
		return false;
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	q = NULL; //将q赋值为NULL，避免其成为野指针
	return true;
}
int main(){
    LinkList L;
    List_TailInsert(L);
    printf("%d\n",GetElem(L,2)->data);
    InsertNode(L,2);
    PrintList(L);
    DeleteNode(L,4);
    PrintList(L);
    return 0;
}