#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞ 

typedef int VertexType; //每个顶点数据类型为 整数 

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
	
	int dist[VertexMax];//最短 路径长度 数组 
	// dist[i]：表示当前所找到的从 始点V 到终点Vi 的 最短路径长度 
	
	// path数组 记录的是上一个顶点的内容 
	int path[VertexMax];//最短 路径 数组 
	// path[i] 是一个字符串：表示当前所找到的 从起始点 到终点Vi的最短路径
	// 初态为：若 从V 到 Vi有弧，则 path[i]为0，否则置 path[i] = 1 
	// path数组下标表示 目标节点序号  path数组值表示 源点
	// 如  p[3] = 0  表示 从节点0 到 节点3
	 
	int s[VertexMax];//代表集合S（1代表该顶点已处理，属于集合S；0代表该顶点未处理，不属于集合S，属于集合V-S） 
	// 存放 源点 和 已经生成的终点，其初态为 只有一个源点V 
	
	//1.初始化dist和path数组 
	locate = LocateVex(G,start);//获取源点的下标位置 
	for(i = 0; i < G->vexnum; i++){
		// dist[i] = 顶点start 到 Vi 的距离 
		dist[i] = G->AdjMatrix[loc][i];
		
		if(dist[i] != MaxInt){
			// 顶点start 到 顶点Vi 有边，path[i] 存入 源点序号 
			path[i] = loc;
		}
		else{
			// 无边 
			path[i] = -1;
		}	  
	} 
    
    //2.初始化S数组（s数组：代表集合S，1代表该元素属于集合S(已处理的顶点)，0该元素不属于集合S(未处理的顶点)） 
    for(i = 0; i < G->vexnum; i++){
		s[i] = 0;
	} 
	s[locate] = 1; //代表起始点(源点)以处理完毕 
	num = 1; // 已处理顶点个数 
	
	//3.顶点个数num < 图的顶点个数 
	while(num < G->vexnum){
		//在dist数组中查找其对应s[i]=0，即未处理的最小值元素 
		// 找 当前能够到达的最短路径的顶点 
		min = FindMinDist(dist, s, G->vexnum);
		s[min] = 1;//将找到的最短边所对应的的顶点加入集合S
		 
		//加入新的顶点后，更新dist和path数组 
		// 在加入新顶点后，考察是否 经过加入的新顶点 到其它的顶点有更小的距离 
		for(i = 0; i < G->vexnum; i++){
			// s[i] == 0：顶点 i 不属于 U集合 
			// dist[i]：存放的是 0 到 i 的当前的最短路径长度 
			// dist[min]：0 到 能到当前顶点中 最小路径长度	 
			// G->AdjMatrix[min][i]) ：最小顶点 到 i 的路径长度 
			if((s[i] == 0) && (dist[i] > dist[min] + G->AdjMatrix[min][i])){
				// 更新 dist最小距离 
				dist[i] = dist[min] + G->AdjMatrix[min][i];
				// 更新 path路径 数组 
				path[i] = min;// min -> i：通过 节点min 到达 节点i  
			}
		}
	    num++; // 已处理顶点数 + 1 
	} 
    displayPath(dist, path, G, start);//展示dist数组、path数组及最短路径 
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
 
int main() {
	MGraph G;
	VertexType start;
	
	CreateDN(&G);
	print(G); 
	
	printf("输入起始点："); 
	scanf(" %d",&start);
	printf("\n");
	ShortestPath_Dijkstra(&G,start);
	
	return 0;
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

