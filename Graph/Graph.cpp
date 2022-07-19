#include<stdlib.h>
#include<stdio.h>

//邻接矩阵法
#define MaxVertexNum 100
typedef char VertexType; //顶点的数据类型
typedef int EdgeType; //带权图边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];//存储顶点的表
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum,arcnum; //图当前的顶点数和弧数
}MGraph;

//邻接表法存储
typedef struct ArcNode{
    int adjvex; //该弧所指向的顶点的位置
    struct ArcNode *next; //指向下一条弧的指针
    //InfoType info; //网的边权值
} ArcNode;

typedef struct VNode{
    VertexType data; //顶点信息
    ArcNode *first; //指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices; //邻接表
    int vexnum, arcnum; //图的顶点数和弧数
} ALGraph; //ALGraph是以邻接表存储的图的类型

//图的基本操作
bool Adjacent(G,x,y); //判断图G中是否存在边<x,y>或(x,y)
ArcNode Neighbors(G,x); //列出图G中与x结点邻接的边
void InsertVertex(G,x);//在图G中插入顶点x
void DeleteVertex(G,x); //在图G中删除顶点x
void AddEdge(G,x,y); //若(x,y)或<x,y>不存在，则向图G中添加该边
void RemoveEdge(G,x,y); //若(x,y)或<x,y>存在，则删除该边
int FirstNetghbor(G,x); //寻找x的第一个临界点，若有则返回顶点号，没有或者x不存在则返回-1
int NextNeighbor(G,x,y); // 返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1
int Get_edge_value(G,x,y); //获取图G中边(x,y)或<x,y>对应的权值
int Set_edge_value(G,x,y,v); //设置图G中边(x,y)或<x,y>对应的权值为v


//广度优先搜索算法
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM]; //访问标记数组
void BFSTraverse(Graph G){
    for(int i = 0;i<G.vexnum;++i){
        visited[i] = false; //将访问标记数组初始化为false
    }
    InitQueue(Q);
    for(int i = 0; i<G.vexnum; ++i){
        if(!visited[i]){
            BFS(G,i);
        }
    }
}
void BFS(Graph G, int v){
    visit(v); //访问初始节点v
    visited[v] = true; // 设置节点为已访问
    EnQueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);//类似于树的层序遍历
        for(int w = FirstNetghbor(G,v);w>=0; w = NextNeighbor(G,v,w)){//检测v的所有邻接点
            if(!visited[w]){
                visit(w);
                visited[w] = true;
                EnQueue(Q,w);
            }
        }
    }
}

//BFS算法求解单源最短路径问题
void BFS_MIN_Distance(Graph G, int u){
    for(i = 0; i<G.vexnum;++i){
        d[i] = INT_MAX;
    }
    visited[v] = true;
    d[u] = 0;
    while(!isEmpty(Q)){
        DeQueue(Q,u);
        for(w = FirstNetghbor(G,u);w>=0;w++){
            if(!visited(w)){
                visited[w] = true;
                d[w] = d[u] + 1; //路径长度+1
                EnQueue(w);
            }
        }
    }
}

//深度优先搜索
void DFSTraverse(Graph G){
    for(int v = 0; v<G.vexnum;v++){
        visited[v] = false;
    }
    for(int v; v<G.vexnum; v++){
        if(!visited[v]){
            DFS(G,v);
        }
    }
}

void DFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    for(w = FirstNetghbor(G,w); w>=0; w = NextNeighbor(G,v,w)){
        if(!visited[w]){
            DFS(G,w);//递归进行深度优先搜索
        }
    }
}


int main(){

}