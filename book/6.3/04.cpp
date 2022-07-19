//只要求判断是否存在，因此只需要从i顶点开始遍历，如果能找到j，说明存在

#define MAXSIZE 100

int visited[MAXSIZE] = {0};

#define MaxVertexNum 100
typedef char VertexType; //顶点的数据类型
typedef int EdgeType; //带权图边上权值的数据类型
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

void DFS(ALGraph G,int i,int j, bool &can_reach){
    if(i == j){
        can_reach = true;
        return ;
    }
    for(int w = FirstNeighbor(G,i); w>=0;w = NextNeighbor(G,i,w)){
        if(!visited[w]){
            DFS(G,w,j,can_reach);//进行深度优先递归 
        }
    }
    
}

void BFS(ALGraph G,int i , int j, bool &can_reach){
    
    InitQueue(Q);
    EnQueue(Q,i);
    visited[i] = true; //由于i入队时没有在循环内，因此需要单独的将其访问位置为true
    while(!IsEmpty(Q)){
        DeQueue(Q,v);
        for(int w = FirstNeighbor(G,v);w>=0;w = NextNeighbor(G,v,w)){
            if( w == j){
                    can_reach = true;
                    return ;
            }

            if(!visited[w]){
                visited[w] = true;
                EnQueue(Q,w);          //除i以外，其他节点入队时都要将visited值设为true    
            }
        
        }
    }
}