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
}VNode,AdjList[VertexMax];	//AdjList表示邻接表类型

//邻接表
typedef struct{
	// AdjList[MVNum]：数组类型，数组的每一个元素为 VNode类型 
	AdjList vertices;	//一维数组vertices
	int vexnum,arcnum;	//图的当前顶点数和边数
}ALGraph;

// 邻接矩阵 
typedef struct{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum, arcnum;//图的顶点数和边数  
}MGraph;

// 邻接矩阵 转换为 邻接表 
void VGTransformLG(MGraph G, ALGraph *LG){
	int i, j;
	//1.顶点数、边数 赋值 
	LG->vexnum = G.vexnum;
	LG->arcnum = G.arcnum;
	
	//输入各点，构造一维数组
	for(i = 0; i < LG->vexnum; ++i){
		// 数组下标 就是 顶点值 
		LG->vertices[i].data = i;
		LG->vertices[i].firstarc = NULL;	//初始化顶点指针域
	}
	
	for(i = 0; i < G.vexnum; i++){
		for(j = 0; j < G.vexnum; j++){
			// 顶点 i 与 顶点 j 之间存在边 
			if(G.AdjMatrix[i][j] != MaxInt){
				//生成新结点(指针p1指向该结点
				ArcNode* p = (ArcNode*) malloc(sizeof(ArcNode));
				p->adjvex = j;	//邻接点在一维数组中的下标值赋值给该结点
				p->weight = G.AdjMatrix[i][j]; // 权值信息 
				// 链表 采用头插法 
				p->nextarc = LG->vertices[i].firstarc;	
				LG->vertices[i].firstarc = p;	
			}
		}
	}
}

int main(){
	
	ALGraph LG;
	MGraph G;
	
	Create(G);
	VGTransformLG(G, &LG);

	return 0;
} 

