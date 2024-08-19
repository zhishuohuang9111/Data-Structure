#include<stdio.h>
#include<stdlib.h>

//包含最大顶点个数 
#define MaxVertices 100 
//不邻接时为32767，但输出时用 "∞"
#define MaxWeight 32767 

#include<stdio.h>
#include<stdlib.h>
//邻接矩阵结构
typedef char VertexType;
typedef int EdgeType;
 
#define MAX 10
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef int Boole;  //布尔类型 存储TRUE FALSE
Boole visited[MAX];    //访问标志数组 

//包含权的邻接矩阵的的定义
typedef struct{
	//顶点信息的数组
    int Vertices[MaxVertices]; 
	//边的权信息的数组
    int Edge[MaxVertices][MaxVertices]; 
    //当前的顶点数
    int numV; 
    //当前的边数
    int numE; 
}MGraph;

//图的生成函数
void CreateGraph(MGraph *G){ 
    int n, e, vi, vj, w, i, j;
    printf("请输入图的顶点数和边数（以空格分隔）：");
    scanf("%d%d",&n,&e);
    G->numV = n;G->numE = e;
    //图的初始化
    for(i = 0;i < n; i++){
        for(j = 0;j < n; j++){ 
            if(i == j){
            	G->Edge[i][j] = 0;
			}  
            else{
            	G->Edge[i][j] = 32767;
			}     
        }
        
        //将顶点存入数组中
        for(i = 0; i < G->numV; i++){ 
            printf("请输入第%d个顶点的信息(整型):",i+1);
            scanf("%d",&G->Vertices[i]);
        }
    }
        
    printf("\n");

    for(i = 0; i <G->numE; i++)
    { 
        printf("请输入边的信息i,j,w(以空格分隔):");
        scanf("%d%d%d",&vi,&vj,&w); 
        //若为不带权值的图，则w输入1
        //若为带权值的图，则w输入对应权值

        G->Edge[vi-1][vj-1]=w;//①
        // G->Edge[vj-1][vi-1]=w;//②
        //无向图具有对称性的规律，通过①②实现
        //有向图不具备此性质，所以只需要①
    }
}

//输出邻接矩阵的信息
void DispGraph(MGraph G){ 
    int i,j;
    printf("\n输出顶点的信息（整型）:\n");
    for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);

    printf("\n输出邻接矩阵:\n");
    printf("\t");
    for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //两点之间无连接时权值为默认的32767，
        // 在无向图中一般用"0"表示，在有向图中一般用"∞",
        // 这里为了方便统一输出 "∞"
            printf("%8s", "∞");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}

//深度优先递归算法
void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TRUE;   //被访问的标记 
	printf("%c->",G.Vertices[i]);
	for(j=0;j<G.numV;j++){
		//边(i,j)存在且j顶点未被访问，递归
		if(G.Edge[i][j]==1&&!visited[j]){
			DFS(G,j);
		}  	
	} 
}
 
//深度优先遍历
void DFStraverse(MGraph G)
{
	
	int i;
	for(i=0;i<G.numV;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numV;i++)
			if(!visited[i])
				DFS(G,i);		
				
} 

int main()
{ 
    MGraph G;
    CreateGraph(&G);
    DispGraph(G);
}
