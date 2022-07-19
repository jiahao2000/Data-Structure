//本题采用基于递归的深度优先遍历算法，从结点u出发，递归深度优先遍历图中节点，若访问到结点v，则输出该收缩路径上的结点。为此，设置一个path数组来存放路径上的结点
//d表示路径长度（初始未-1）.查找从顶点u到v的简单路径

void FindPath(AGraph *G, int u , int v, int path[],int d){
    int w,i;
    ArcNode *p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if(u == v){
        printf(path[]);
    }
    p = G->adjlist[u].firstarc;
    while(p!=NULL){
        w=p->adjvex;
        if(visited[w] == 0)
            FindPath(G,w,V,path,d);
        p->p->nextarc;
    }
    visited[u] = 0;
}