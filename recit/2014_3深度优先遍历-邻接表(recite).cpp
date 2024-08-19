#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞

typedef int VertexType;

//单链表中的结点
typedef struct ArcNode{	
	int adjvex;	// 该弧所指向的顶点的位置 
	struct ArcNode *nextarc;	//指向下一条弧的指针 
	int weight;	//边信息，如权值
}ArcNode;
	
//顶点（存储在一维数组中）
typedef struct VNode{
	VertexType data; //顶点信息
	// 指针类型为 ArcNode结构体类型 
	ArcNode *firstarc;	//顶点的第一邻接点
}VNode,AdjList[VertexMax];	//AdjList表示邻接表类型

//邻接表
typedef struct{
	// AdjList[MVNum]：数组类型，数组的每一个元素为 VNode类型 
	AdjList vertices;	//一维数组vertices
	int vexnum, arcnum;	//图的当前顶点数和边数
}ALGraph;

/*深度优先遍历*/
int visited[VertexMax]; //定义数组为全局变量 

void DFS(ALGraph *G, int i){
	int j;
	ArcNode* p;
	int w;
	
	//1.访问当前节点 
	printf("%c	", G->vertices[i].data);
	//2.将当前节点标记成已访问结点
	visited[i] = 1;
	
	p = G->vertices[i].firstarc;
	while(p != NULL){
		w = p->adjvex;//w 是邻接点的坐标 
		if(visited[w] == 0){
			DFS(G, w);
		}
	    p = p->nextarc;//查找完之后，将p向后推一位 
	} 
} 

void DFSTraverse(ALGraph *G, int start){
	int i;
	
	//初始化"标志"数组
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	} 
	
	// 从 指定顶点 遍历 
	DFS(G, start);
	
	// for循环：防止图是非连通图，一次递归调用不能全部遍历到 
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			DFS(G, i);
		}
	}
}

int main(){
 	ALGraph G;
 	CreateUDG(&G);
	int start = 0;
	printf("\n\n深度优先遍历："); 
	DFSTraverse(&G, start);  
 	
	return 0;
}

