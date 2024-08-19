#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞

typedef int VertexType;

// 邻接矩阵 
typedef struct{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum,arcnum;//图的顶点数和边数  
}MGraph;

// 计算 出度为 0 的顶点个数 
int Count_Out(MGraph G){
	int count = 0;
	bool flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		for(int j = 0; j < G.vexnum; j++){
			if(G.AdjMatrix[i][j] != MaxInt){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("出度为 0 的顶点：%d	", i);
			count++;
		}
	}
	return count;
}

// 计算 入度为 0 的顶点个数
int Count_In(MGraph G){
	int count = 0;
	int flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		for(int j = 0; j < G.vexnum; j++){
			if(G.AdjMatrix[j][i] != MaxInt){
				flag = false;
			}
		}
		if(flag){
			printf("入度为 0 的顶点：%d	", i);
			count++;
		}
	}
	return count;
}

int main(){
	
	MGraph G;
	CreateDN(&G);
	
	int count_out = Count_Out(G);
	int count_in = Count_In(G);
	printf("出度为 0 的顶点个数：%d\n", count_out);
	printf("入度为 0 的顶点个数：%d\n", count_in);

	return 0;
}
