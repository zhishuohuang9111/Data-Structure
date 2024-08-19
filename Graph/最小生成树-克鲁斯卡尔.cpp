#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20

typedef char VertexType;

// 采用 边集数组 存储图中的边 
typedef struct{
	VertexType begin;
	VertexType end;
	// 边上的权值 
	int weight;
}Edge;//边集数组 edge[]的单元 

typedef struct{
	//顶点数组 
	VertexType Vertex[VertexMax];
	//边集数组 
	Edge edge[VertexMax];
	//顶点数 
	int vexnum;
	//边数 
	int edgenum;
}EdgeGraph;

void CreateEdgeGraph(EdgeGraph *E){
	int i;
	// 1.输入顶点数和边数
	printf("请输入顶点数和边数:\n");
	printf("顶点数 n = "); 
	scanf("%d", &E->vexnum);
	printf("边  数 e = "); 
	scanf("%d", &E->edgenum);
	printf("\n"); 
	
	// 2.输入顶点元素 
	printf("输入顶点(无需空格隔开):"); 
	scanf("%s", &E->Vertex);
	printf("\n\n");
	
	printf("输入边信息和权值(如：A B 15):\n");
	for(i = 0; i < E->edgenum; i++){
		printf("请输入第 %d 边的信息:", i+1);
		scanf(" %c %c %d", &E->edge[i].begin, &E->edge[i].end, &E->edge[i].weight);
	}	
}

void print(EdgeGraph *E){
	int i;
	
	printf("-----------------------------------\n"); 
	printf(" 顶点数组Vertex:");
	for(i = 0; i < E->vexnum; i++){
		printf("%c ", E->Vertex[i]);
	}
	printf("\n\n");
	
	printf(" 边集数组edge:\n\n");
	printf("\t\tBegin	End	Weight\n");
	for(i = 0; i < E->edgenum; i++){
		printf("\tedge[%d]	%c	%c	%d\n", i, E->edge[i].begin, E->edge[i].end,E->edge[i].weight);
	}
	printf("-----------------------------------\n");
}

int partition(EdgeGraph *E, int low, int high){
	Edge pivot = E->edge[low];

	while(low < high){
		while(low < high && pivot.weight <= E->edge[high].weight){
			high--;
		}
		E->edge[low] = E->edge[high];
		
		while(low < high && E->edge[low].weight <= pivot.weight){
			low++;
		}
		E->edge[high] = E->edge[low];
	}
	E->edge[low] = pivot;
	// 返回 中间位置 
	return low;
}

// 将 图中的边 从小到大进行排序 (快速排序)
void quickSort(EdgeGraph *E, int low, int high){
	// 递归出口条件 
	if(low < high){
		// 划分 
		int pos = partition(E, low, high);
	
		quickSort(E, low, pos - 1);
		quickSort(E, pos + 1, high);
	}
} 

//查找元素v在一维数组 Vertex[] 中的下标，并返回下标 
int LocateVertex(EdgeGraph *E, VertexType v){
	int i;
	for(i = 0; i < E->vexnum; i++){
		if(v == E->Vertex[i]){
			return i; 
		} 
	}
	printf("No Such Vertex!\n");
	return -1;
}

// 参数 v：结点在Vertex数组中的下标 
int FindRoot(int v,int parent[]){
	//parent=-1表示没有双亲，即没有根节点 
	while(parent[v] != -1){
		//逐代查找根节点 
		v = parent[v];
	}
	//将找到的根节点返回，若没有根节点，返回自身 
	return v;
}

void outputMST(EdgeGraph *E, int i){
	printf("%c — %c, w = %d\n", E->edge[i].begin, E->edge[i].end, E->edge[i].weight);//输出此边 
}

// 最小生成树-克鲁斯卡尔算法算法 
void MiniSpanTree_Kruskal(EdgeGraph *E){
	int i;
	//生成边计数器，当 num = 顶点数-1 时，最小生成树生成完毕 
	int num;
	int root1, root2; 
	int LocateV1, LocateV2; 
	//用于查找顶点的双亲，判断两个顶点间是否有共同的双亲，来判断生成树是否会成环 
	int parent[VertexMax];
	
	//1.按权值从小到大排序 
	printf("排序前的边集数组：\n");
	print(E); 
	quickSort(E, 0, E->edgenum -1);
	printf("排序后的边集数组：\n");
	print(E);
	
	//2.初始化parent数组 
	for(i = 0; i < E->vexnum; i++){
		// 视 图中所有顶点 都是 一棵只有根结点的树 
		parent[i] = -1;
	}
	
	printf("\n 最小生成树(Kruskal):\n\n");
	//3. for循环，遍历 edge边数组 
	for(num = 0, i = 0; i < E->edgenum; i++){
		LocateV1 = LocateVertex(E, E->edge[i].begin);
		LocateV2 = LocateVertex(E, E->edge[i].end);
		// 找到 所在生成树的根结点 
		root1 = FindRoot(LocateV1, parent);
		root2 = FindRoot(LocateV2, parent);
	
		// 若不会成环，则在最小生成树中构建此边
		// 根结点不相等 即 在不同的连通分量中 
		if(root1 != root2){
			// 输出该边 
			outputMST(E, i);
			//合并生成树，将 root1 作为 根结点，即 root2 的双亲为 root1 
			parent[root2] = root1;
			// 最小生成树边数 + 1 
			num++;
			
			//若num=顶点数-1，代表树生成完毕，提前结束 
			if(num == E->vexnum-1){
				return;
			}
		} 
	}
}

int main(){
	EdgeGraph E;
	CreateEdgeGraph(&E);
	MiniSpanTree_Kruskal(&E);
	
	return 0;
}
