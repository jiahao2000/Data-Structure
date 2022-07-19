//图的深度优先算法的非递归表示（使用邻接表存储）

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

//在非递归算法中使用了一个栈来记忆下一步可能访问的节点

void DFS_Non_RC(ALGraph &G, int v){
    int w; //顶点序号
    InitStack(S);
    for(int i = 0;i<G.vexnum;i++){
        visited[i] = false;
    }
    Push(S,v);
    visited[v] = true;
    while(!isEmpty(S)){
        k = Pop(S); //取出栈顶元素
        visit(k);//先访问该节点，再将子节点入栈
        for(w = FirstNeighbot(G,v); w > 0; w = NextNeighbor(G,v,w)){
            if(!visited[w]){
                Push(S,w);//如果w未被访问，则将w入栈
                visited[w] = true; //访问
            }
        }
    }
}