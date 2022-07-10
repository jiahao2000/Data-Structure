#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef int ElemType; //顺序表中元素的类型
typedef struct SeqList
{
    ElemType data[MaxSize];
    int len;                 //顺序表的当前长度
} SeqList;

void print(SeqList L)
{
    for(int i = 0;i<L.len;i++){
        printf("  %d",L.data[i]);
    }
    printf("\n");
}
bool ListInsert(SeqList &L, int i, ElemType e)//i代表要插入的位置，从1开始
{
    if(i<1 || i>L.len+1){
        return false;
    }
    if(L.len >= MaxSize){
        return false;
    }
    for(int j = L.len; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.len++;
    return true;
}

//删除指定位置i上的元素，i从1开始，并将其存入e中，删除成功返回true,失败返回false
bool ListDelete(SeqList &L, int i)
{
    if(i<1 || i>L.len){
        printf("false");
        return false;
    } 
    if(L.len == 0){
        printf("false");
        return false;
    }
    for(int j = i; j<L.len; j++){
        L.data[j-1] = L.data[j];
    }
    L.len--;
    print(L);
    return true;
}

//查找元素 查找成功后返回位置 失败返回0；
int LocateElem(SeqList L, ElemType e)
{
    int i;
    for(i=0;i<L.len;i++){
        if(L.data[i] == e){
            return i+1;
        }
    }
    return 0;
}

int main()
{
    SeqList L;
    bool ret; //查看返回值

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;  
    int insert;
    int del;
    scanf("%d",&insert);
    ListInsert(L, 2, insert);
    print(L);
    scanf("%d",&del);
    ListDelete(L,del);
    

    return 0;
}