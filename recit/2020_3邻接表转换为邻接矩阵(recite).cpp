#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞

typedef int VertexType;

//单链表中的结点
typedef struct ArcNode{	
	int adjvex;	//顶点的第一邻接点在一维数组中的下标
	struct ArcNode *nextarc;	//指向顶点的下一邻接点
	int weight;	//边信息，如权值
}ArcNode;
	
//顶点（存储在一维数组中）
typedef struct VNode{
	VertexType data;	//顶点信息
	// 指针类型为 ArcNode结构体类型 
	ArcNode *firstarc;	//顶点的第一邻接点
}VNode, AdjList[VertexMax];	//AdjList表示邻接表类型

//邻接表
typedef struct{
	// AdjList[MVNum]：数组类型，数组的每一个元素为 VNode类型 
	AdjList vertices;	//一维数组vertices
	int vexnum,arcnum;	//图的当前顶点数和边数
}ALGraph;

typedef struct{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum,arcnum;//图的顶点数和边数  
}MGraph;

// 邻接表 转换为 邻接矩阵 
void LGTransformV(ALGraph LG, MGraph *G){
	int i, j;
	// 1.顶点数、边数 赋值 
	G->vexnum = LG.vexnum;
	G->arcnum = LG.arcnum;
	
	// 2.输入顶点元素 
	for(i = 0; i < G->vexnum; i++){
		// 数组下标 就是 顶点值 
		G->Vertex[i] = i; 
	}
	
	// 3.矩阵初始化
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
	    	G->AdjMatrix[i][j] = MaxInt;
		}
	}
	// 4.邻接表 转换为 邻接矩阵 
	for(i = 0; i < G->vexnum; i++){
		ArcNode* p = LG.vertices[i].firstarc;
		if(p == NULL){
			break;
		}
		while(p != NULL){
			G->AdjMatrix[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	} 
}

int main(){
	
	ALGraph LG;
	MGraph G;
	
	CreateUDG(LG);
	LGTransformV(LG, &G);
	
	return 0;
}


