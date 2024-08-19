#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞ 

typedef int VertexType; //每个顶点数据类型为字符型 

typedef struct{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum,arcnum;//图的顶点数和边数  
}MGraph;

int LocateVex(MGraph *G,VertexType v)//查找元素v在一维数组 Vertex[] 中的下标，并返回下标 
{
	int i;
	
	for(i = 0; i < G->vexnum; i++){
		if(v == G->Vertex[i]){
			return i; 
		} 
	} 
	 
	printf("No Such Vertex!\n");
	return -1;
}

void CreateDN(MGraph *G){
	int i,j;
	//1.输入顶点数和边数 
	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边  数 e="); 
	scanf("%d",&G->arcnum);

	//2.输入顶点元素 
	for(int i = 0; i < G->vexnum; i++){
		// 数组下标 就是 顶点值 
		G->Vertex[i] = i; 
		// printf("输入顶点元素：");
		// scanf("%d",&G->Vertex[i]);
	}
	// printf("输入顶点元素(无需空格隔开)：");
	// scanf("%s",G->Vertex);
	printf("\n");
	//3.矩阵初始化
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
	    	G->AdjMatrix[i][j]=MaxInt;
		}
	}
	 
	//4.构建邻接矩阵
	int n,m;
	VertexType v1,v2;
	int w;//v1->v2的权值 
	 
	printf("输入路径及路径长度：\n");
	for(i=0;i<G->arcnum;i++){
		printf("输入第%d条路径信息：",i+1);
	 	scanf("%d %d %d",&v1,&v2,&w);
	 	n=LocateVex(G,v1); //获取v1所对应的在Vertex数组中的坐标 
	 	m=LocateVex(G,v2); //获取v2所对应的在Vertex数组中的坐标
	 	
	 	// 输入边的信息非法，重新输入 
	 	while(n == -1 || m == -1){
	 		printf("NO This Vertex!\n");
	 		printf("请重新 输入第%d条边信息及权值：",i+1);
	 		scanf("%d %d %d",&v1,&v2,&w);
	 		n=LocateVex(G,v1); 
	 		m=LocateVex(G,v2); 
		} 
		// 赋权值 
	    G->AdjMatrix[n][m]=w;
	}
}

// 输出 邻接矩阵 
void print(MGraph G){
	int i,j;
	printf("\n-------------------------------");
	printf("\n 邻接矩阵：\n\n"); 	
	printf("\t ");
	for(i=0;i<G.vexnum;i++){
		printf("\t%d",G.Vertex[i]);
	}
	printf("\n");
	for(i=0;i<G.vexnum;i++){
		printf("\t%d",G.Vertex[i]);
	  	for(j=0;j<G.vexnum;j++){
	    	if(G.AdjMatrix[i][j]==MaxInt){
	    		printf("\t∞");
			}
	 	    else{
	 	    	printf("\t%d",G.AdjMatrix[i][j]);
			}
		}
    	printf("\n");
	} 
}

void displayPath(int dist[],int path[],MGraph *G,VertexType start){
	int i,k,j=0;
	int temp[VertexMax];//临时数组 
	// VertexType target;//目标地点 
	int loc = 0; 
	
	/*
	printf("\n-----------------------------------------------\n");
	printf("结果展示：\n");
	printf("\n\n");
	//打印dist数组 
	printf("\tdist[i]:\n\t");
	for(i=0;i<G->vexnum;i++)
	printf("\t%d",i);
	printf("\n\t"); 
	for(i=0;i<G->vexnum;i++){
    	printf("\t%d",dist[i]);
	}
	printf("\n");
	
	//打印path数组 
	printf("\n\tpath[i]:\n\t");
	for(i=0;i<G->vexnum;i++)
	printf("\t%d",i);
	printf("\n\t"); 
	for(i = 0; i < G->vexnum; i++){
    	printf("\t%d",path[i]);
	}
	
	*/
    printf("\n\n"); 
	 //最短路径 
	printf("最短路径:\n\n"); 
	for(i = 0; i < G->vexnum; i++){
		// 临时数组初始化 
		for(k = 0; k < VertexMax; k++){
	    	temp[k]=-1;
		}
		
		loc = i;
		j = -1;
		while(loc != -1){
    		temp[++j] = loc;
    		loc = path[loc];
		}
		
		if(j == 0 && G->Vertex[temp[j]] == start){
			printf("\t");
			printf("%d -> %d:%d为起始点!",start,G->Vertex[i],G->Vertex[temp[j]]);
		}
		else if(j == 0 && G->Vertex[temp[j]] != start){
			printf("\t");
			printf("%d -> %d:%d不可达%d",start,G->Vertex[i],start,G->Vertex[temp[j]]);
		}
		else{
			printf("\t");
			printf("%d -> %d:",start,G->Vertex[i]);
			for(j ;j >= 0; j--){
				printf("%d ", G->Vertex[temp[j]]);
			}
			printf("(总路径长度:%d)", dist[i]);
		}
	    
	 	printf("\n\n");
	}
}

int FindMinDist(int dist[], int s[], int vexnum){
	int i;
	int loc;
	int min = MaxInt+1;
	for(i = 0; i < vexnum; i++){
		//只对s[i]=0的顶点进行查找（即查找 不属于 S集合中的顶点） 
		if(s[i] == 0){
			if(dist[i] < min){
				min = dist[i];
				loc = i;
			}
		}
	}
	return loc;//返回dist中最小元素的下标，即 能够到达的当前最小顶点 
}

void ShortestPath_Dijkstra(MGraph *G, VertexType start){
	int i,j,num;
	int loc;
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
	loc=LocateVex(G,start);//获取源点的下标位置 
	for(i = 0; i < G->vexnum; i++){
		// dist[i] = 顶点start 到 Vi 的距离 
		dist[i] = G->AdjMatrix[loc][i];
		
		if(dist[i]!=MaxInt){
			// 顶点start 到 顶点Vi 有边，path[i] 存入 源点序号 
			path[i] = loc;
		}
		else{
			// 无边 
			path[i]=-1;
		}	  
	} 
    
    //2.初始化S数组（s数组：代表集合S，1代表该元素属于集合S(已处理的顶点)，0该元素不属于集合S(未处理的顶点)） 
    for(i = 0; i < G->vexnum; i++){
		s[i] = 0;
	} 
	s[loc] = 1; //代表起始点(源点)以处理完毕 
	num = 1;
	
	//3.顶点个数num < 图的顶点个数 
	while(num < G->vexnum){
		//在dist数组中查找其对应s[i]=0，即未处理的最小值元素 
		// 找 当前能够到达的最短路径的顶点 
		min = FindMinDist(dist,s,G->vexnum);
		s[min] = 1;//将找到的最短边所对应的的顶点加入集合S
		
		//加入新的顶点后，更新dist和path数组 
		// 在加入新顶点后，考察是否 通过加入的新顶点 到其它的顶点有更小的距离 
		for(i = 0; i < G->vexnum; i++){
			// s[i] == 0：顶点 i 不属于 U集合 
			// dist[i]：存放的是 0 到 i 的路径长度 
			// dist[min]：0 到 能到当前顶点中 最小路径长度	 
			// G->AdjMatrix[min][i]) ：最小顶点 到 i 的路径长度 
			if((s[i] == 0) && (dist[i] > dist[min] + G->AdjMatrix[min][i])){
				// 更新 dist最小距离 
				dist[i] = dist[min] + G->AdjMatrix[min][i];
				// 更新 path路径 数组 
				path[i] = min;// min -> i：通过 节点min 到达 节点i  
			}
		}
	    num++;	
	} 
	for(int i = 0; i < G->vexnum; i++){
		printf("%d	", path[i]);
	}
	printf("\n");
	for(int i = 0; i < G->vexnum; i++){
		printf("%d	", dist[i]);
	}
    displayPath(dist, path, G, start);//展示dist数组、path数组及最短路径 
} 

int main() 
{
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

