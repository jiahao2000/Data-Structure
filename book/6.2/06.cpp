
#define MAXV 100

typedef struct{
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

int IsExistEL(MGraph G){
    int degree; //记录当前节点的度
    int count; //记录度为基数的顶点的个数
    for(int i = 0 ; i<MAXV;i++){
        for(int j = 0; j<MAXV;j++){
            if(G.Edge[i][j] != 0){
                degree++;
            }
        }
        if(degree%2 == 1){
            count++;
        }
        degree = 0;
    }
    if(count == 0 || count == 1){
        return 1;
    }
    else{
        return 0;
    }
}