#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 
#define MaxInt 32767 

typedef int VertexType;

typedef struct{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum, arcnum; //图的顶点数和边数  
}MGraph;

int FindMinDist(int dist[], int s[], int vexnum) {
	int i;
	int locate;
	int min = MaxInt+1;
	for(i = 0; i < vexnum; i++){
		//只对s[i]=0的顶点进行查找（即查找 不属于 S集合中的顶点） 
		if(s[i] == 0){
			if(dist[i] < min){
				min = dist[i];
				locate = i;
			}
		}
	}
	return locate;//返回dist中最小元素的下标，即 能够到达的当前最小顶点 
}

void ShortestPath_Dijkstra(MGraph *G, VertexType start){
	int i,j,num;
	int locate;
	int min;
	//最短 路径长度 数组 
	int dist[VertexMax];
	// path数组 记录的是上一个顶点的内容 
	int path[VertexMax];//最短 路径 数组 
	// 存放 源点 和 已经生成的终点，其初态为 只有一个源点V 
	int s[VertexMax];
	
	//1.初始化dist和path数组 
	locate = LocateVex(G,start);//获取源点的下标位置 
	for(i = 0; i < G->vexnum; i++){
		// dist[i] = 顶点start 到 Vi 的距离 
		dist[i] = G->AdjMatrix[loc][i];
		
		if(dist[i] != MaxInt){
			// 顶点start 到 顶点Vi 有边，path[i] 存入 源点序号 
			path[i] = locate;
		}
		else{
			// 无边 
			path[i] = -1;
		}	  
	} 
    
    //2.初始化S数组
    for(i = 0; i < G->vexnum; i++){
		s[i] = 0;
	} 
	s[locate] = 1; //代表起始点(源点)以处理完毕 
	num = 1; // 已处理顶点个数 
	
	//3.顶点个数num < 图的顶点个数 
	while(num < G->vexnum){
	
		min = FindMinDist(dist, s, G->vexnum);
		s[min] = 1;
		 
		for(i = 0; i < G->vexnum; i++){
			if((s[i] == 0) && (dist[i] > dist[min] + G->AdjMatrix[min][i])){
				// 更新 dist最小距离 
				dist[i] = dist[min] + G->AdjMatrix[min][i];
				// 更新 path路径 数组 
				path[i] = min;// min -> i：通过 节点min 到达 节点i  
			}
		}
	    num++; // 已处理顶点数 + 1 
	} 
	//展示dist数组、path数组及最短路径
    displayPath(dist, path, G, start); 
} 

void displayPath(int dist[],int path[],MGraph *G,VertexType start){
	int i,k,j=0;
	int temp[VertexMax];//临时数组 
	int loc = 0; 

	printf("最短路径:\n\n"); 
	// for循环一次，每一次找到从 开始顶点 到 顶点 i 的路径 
	for(i = 0; i < G->vexnum; i++){
		// 每一次 for 循环，临时数组初始化 
		for(k = 0; k < VertexMax; k++){
	    	temp[k] = -1;
		}
		
		loc = i;
		j = -1;
		// path[start] = -1：开始顶点的 path值为 - 1 
		while(loc != -1){
    		temp[++j] = loc;
    		loc = path[loc];
		}
		
		if(j == 0 && temp[j] == start){
			printf("%d为起始点!", temp[j]);
		}
		else if(j == 0 && temp[j] != start){
			printf("%d 不可达 %d", start, temp[j]);
		}
		else{
			for(j ;j >= 0; j--){
				printf("%d ", temp[j]);
			}
			printf("(总路径长度:%d)", dist[i]);
		}
	 	printf("\n\n");
	}
}
 
int main(){
	MGraph G;
	VertexType start;
	CreateDN(&G);
	
	printf("输入起始点："); 
	scanf(" %d", &start);
	ShortestPath_Dijkstra(&G, start);

	return 0;
}

