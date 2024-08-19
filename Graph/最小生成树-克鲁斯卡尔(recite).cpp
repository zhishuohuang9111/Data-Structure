#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20

typedef int VertexType; 

// 采用 边集数组 存储图中的边 
typedef struct{
	VertexType begin;
	VertexType end;
	// 边上的权值 
	int weight;
}Edge;//边集数组 edge[]的单元 

typedef struct{
	VertexType Vertex[VertexMax];//顶点数组 
	Edge edge[VertexMax];//边集数组 
	int vexnum;//顶点数 
	int edgenum;//边数 
}EdgeGraph;  // 图的结构体 

// 创建图 
void CreateEdgeGraph(EdgeGraph *E)

// 将 图中的边 从小到大排序 
int partition(EdgeGraph *E, int low, int high){
	Edge pivot = E->edge[low];
	// int pivot = a[low]; 

	while(low < high){
		while(low < high && pivot.weight <= E->edge[high].weight){
			high--;
		}
		E->edge[low] = E->edge[high];
		// a[low] = a[high];
		
		while(low < high && E->edge[low].weight <= pivot.weight){
			low++;
		}
		E->edge[high] = E->edge[low];
		// a[high] = a[low];
	}
	E->edge[low] = pivot;
	// a[low] = pivot;
	// 返回 中间位置 
	return low;
}

void QuickSort(EdgeGraph *E, int low, int high){
	// 递归出口条件 
	if(low < high){
		// 划分 
		int pos = partition(E, low, high);
	
		quickSort(E, low, pos - 1);
		quickSort(E, pos + 1, high);
	}
} 

//t接收到是结点在Vertex数组中的下标 
int FindRoot(int t, int parent[]){
	//parent=-1表示没有双亲，即没有根节点 
	while(parent[t] != -1){
		//逐代查找根节点 
		t = parent[t];
	}
	// while 循环结束条件：parent[t] == -1，t没有双亲节点，t就是根节点 
	//将找到的根节点返回，若没有根节点返回自身 
	return t;
}

void outputMST(EdgeGraph *E, int i){
	printf("\t\t%d-%d, weight = %d\n", E->edge[i].begin, E->edge[i].end, E->edge[i].weight);//输出此边 
}

void MiniSpanTree_Kruskal(EdgeGraph *E){
	int i;
	int num;//生成边计数器，当num=顶点数-1 就代表最小生成树生成完毕 
	int root1, root2; 
	int parent[VertexMax];//用于查找顶点的双亲，判断两个顶点间是否有共同的双亲，来判断生成树是否会成环 
	
	//1.按权值从小到大排序 
	QuickSort(E, 0, E->vexnum - 1);
	print(E);
	
	//2.初始化parent数组 
	for(i = 0; i < E->vexnum; i++){
		// 认为 图中所有顶点 都是 一棵只有根结点的树 
		parent[i] = -1;
	}
	
	printf("\n 最小生成树(Kruskal):\n\n");
	//3. for循环，遍历 edge边数组 
	for(num = 0,i = 0; i < E->edgenum; i++){
		// 找到 所在生成树的根结点 
		root1 = FindRoot(E->edge[i].begin, parent);
		root2 = FindRoot(E->edge[i].end, parent);
	
		//若不会成环，则在最小生成树中构建此边
		// 根结点不相等 即 在不同的连通分量中 
		if(root1 != root2){
			outputMST(E, i); //输出此边 
			//合并生成树 将 root1 作为 根结点
			parent[root2] = root1; // root2 的双亲为 root1 
			num++;
			
			//若num=顶点数-1，代表树生成完毕，提前返回 
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

