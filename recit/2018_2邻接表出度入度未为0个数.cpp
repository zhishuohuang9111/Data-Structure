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

// 计算 出度为 0 的顶点个数
int Count_Out(ALGraph G){
	int count = 0;
	for(int i = 0; i < G.vexnum; i++){
		ArcNode* p = G.vertices[i].firstarc;
		if(p == NULL){
			printf("顶点 %d 的出度为 0\n", i);
			count++;
			break;
		}
	}
	return count;
}

// 计算 入度为 0 的顶点个数
int Count_In(ALGraph G){
	int i, j;
	int count = 0;
	bool flag;
	for(i = 0; i < G.vexnum; i++){
		flag = true;
		for(j = 0; j < G.vexnum; j++){
			// G.vertices[j]：注意：是 j 不是 i 
			ArcNode* p = G.vertices[j].firstarc;
			while(p){
				if(p->adjvex == i){
					flag = false;
					break;
				}
				p = p->nextarc;
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			printf("顶点 %d 入度为 0\n", i);
			count++;
		}
	}
	return count;
}

int main(){
	
	ALGraph LG;
	CreateUDG(&LG);
	
	int count_out = Count_Out(LG);
	int count_in = Count_In(LG);
	
	printf("出度为 0 的顶点个数：%d", count_out);
	printf("入度为 0 的顶点个数：%d", count_in);
	
	return 0;
} 
