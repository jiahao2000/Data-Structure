//一个无向图G是一棵树的判断条件是，G必须是无回路的连通图，或是有n-1条边的连通图
//可以使用深度优先遍历，统计访问到的顶点和边的个数
bool isTree(Graph &G){
    for(int i = 0;i<=G,vexnum;i++){
        visited[i] = false;
    }

    int Vnum = 0, Enum = 0; //初始化统计量为0
    DFS(G,1,Vnum,Enum,visited);
    if(Vnum == G.vexnum && Enum == 2*(G.vexnum - 1))
        return true;
    else 
        return false; 
}

void DFS(Graph &G,int v, int &Vnum, int &Enum, int visited[]){
    visited[v] = true;
    Vnum++;
    int w = FirstNeighbor(G,v);
    while(w! = - 1){
        Enum++;//Enum实际统计的是图的所有节点的度之和
        if(!visited[w]){
            DFS(G,w,Vnum,Enum,visited);
        }
        w = NextNeighbor(G,v,w);
    }
}