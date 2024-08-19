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
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0; 
	} 
	
	// 从 指定顶点 遍历 
	DFS(G,start);
	visited[start] = 1;
	// for循环：防止图是非连通图，一次递归调用不能全部遍历到 
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			DFS(G, i);
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
