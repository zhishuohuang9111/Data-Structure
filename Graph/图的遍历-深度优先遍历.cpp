#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //最大顶点数为100

typedef int VertexType; //每个顶点数据类型为字符型 

typedef struct
{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum,arcnum;//图的顶点数和边数  
}MGraph;

int LocateVex(MGraph *G,VertexType v)//查找元素v在一维数组 Vertex[] 中的下标，并返回下标 
{
	int i;
	
	for(i = 0; i < G->vexnum; i++){
		if(v == G->Vertex[i]){
			return i; 
		} 
	} 
	 
	printf("No Such Vertex!\n");
	return -1;
}

//无向图
void CreateUDG(MGraph *G){
	int i,j;

	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边  数 e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	for(i = 0; i < G->vexnum; i++){
		G->Vertex[i] = i + 1;
	}
	
	for(i=0;i<G->vexnum;i++){
		for(j=0;j<G->vexnum;j++){
	    	G->AdjMatrix[i][j]=0;
		}
	}
	int n,m;
	VertexType v1,v2;
	 
	printf("请输入边的信息：\n");
	// for循环：边数 
	for(i=0;i<G->arcnum;i++){
		printf("输入第%d条边信息及权值：",i+1);
	 	scanf("%d %d",&v1,&v2);
	 	
	 	n=LocateVex(G,v1); //获取v1所对应的在Vertex数组中的坐标 
	 	m=LocateVex(G,v2); //获取v2所对应的在Vertex数组中的坐标
	 	// 输入边的信息非法，重新输入 
	 	while(n == -1 || m == -1){
	 		printf("NO This Vertex!\n");
	 		printf("请重新 输入第%d条边信息及权值：",i+1);
	 		scanf("%d %d",&v1,&v2);
	 		n=LocateVex(G,v1); 
	 		m=LocateVex(G,v2); 
		} 
	 	
		G->AdjMatrix[n][m]=1;
	   	G->AdjMatrix[m][n]=1;//无向网仅此处不同 
     } 
}

void print(MGraph G){
	int i,j;
	printf("\n-------------------------------");
	printf("\n 邻接矩阵：\n\n"); 	

	printf("\t ");
    for(i=0;i<G.vexnum;i++){
    	printf("  %d",G.Vertex[i]);
	}
	printf("\n");
		 
	for(i=0;i<G.vexnum;i++){
	   	printf("\t%d",G.Vertex[i]);
	   	for(j=0;j<G.vexnum;j++){
	 	    printf("  %d",G.AdjMatrix[i][j]);
	    }
	        printf("\n");
	}
}


/*深度优先遍历DFS*/ 
// 用 数组下标 表示 顶点 
int visited[VertexMax];//定义"标志"数组为全局变量 

void DFS(MGraph *G,int i){
	int j;
	
	//1.处理起始点 
	printf("%d	",G->Vertex[i]);//1.输出起始结点 
	visited[i] = 1;//2.将已访问的结点标志成1
	
	//2.由起始点开始，对后续结点进行操作
	//依次搜索vi的邻接点 
	for(j = 0; j < G->vexnum; j++){
		//当满足有边且未被访问过时，递归调用去查找该邻接点 
		if(G->AdjMatrix[i][j] == 1 && visited[j]==0){
			// 递归调用 
			DFS(G,j);//注意此处的G已经是指针类型，不需要再&G 
		}
	}
	// 当有边 但均被访问过时 或者 无边，递归结束，返回上一层 
}

void DFSTraverse(MGraph *G, int start){
	int i;
	
	//初始化"标志"数组为0，代表未访问
	for(i=0;i<G->vexnum;i++){
		visited[i]=0; 
	} 
	
	DFS(G,start);
	visited[start] = 1;
	// for循环：防止图是非连通图，一次递归调用不能全部遍历到 
	
	for(i=0;i<G->vexnum;i++){
		if(visited[i]==0){
			DFS(G,i);
		}
	} 
	
}

int main() 
{
	MGraph G;
	CreateUDG(&G);
	print(G); 

	printf("\n\n深度优先遍历：");
	int start = 6; 
	DFSTraverse(&G, start); 
	 
	return 0;
}	
	

