#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //最大顶点数为100
#define MaxInt 32767 //表示最大整数，表示 ∞ 

typedef char VertexType; //每个顶点数据类型为字符型 

//邻接矩阵结构体 
typedef struct{
	//存放顶点元素的一维数组 
	VertexType Vertex[VertexMax];
	//邻接矩阵二维数组 
	int AdjMatrix[VertexMax][VertexMax];
	//图的顶点数和边数 
	int vexnum,arcnum;
}MGraph;

//辅助数组结构体(候选最短边) 
typedef struct{
	//候选最短边的邻接点 
	VertexType adjvex;
	//候选最短边的权值 
	int lowcost;
	/*
	   lowcost = 0：表示 这个顶点已经放入 U集合中（即 已经生成的最小部分生成树） 
	   将 lowcost 置为 0，代表加入 U集合
	   lowcost 中记录的是 V0 到其它顶点的代价 
	
	  从 上一次求得的最短邻接边 出发 到 V集合中的顶点，将 其代价 与 lowcost数组中的值进行比较 
	*/
}ShortEdge; // ShortEdge数组下标 表示 顶点序号 

//查找 顶点v 在一维数组 Vertex[] 中的下标，并返回下标
int LocateVertex(MGraph *G, VertexType v){
	int i;
	for(i = 0; i < G->vexnum; i++){
		if(v == G->Vertex[i]){
			return i; 
		} 
	} 
	return -1;
}

//构建无向网（Undirected Network）
void CreateUDN(MGraph *G){
	int i, j;
	// 1.输入顶点数和边数
	printf("请输入顶点个数和边数：\n");
	printf("顶点数 n = "); 
	scanf("%d", &G->vexnum);
	printf("边  数 e = "); 
	scanf("%d", &G->arcnum);
	printf("\n\n"); 
	
	// 2.输入顶点元素 
	printf("输入顶点元素(无需空格隔开)：");
	scanf("%s", &G->Vertex);
	
	printf("\n\n");
	
	// 3.邻接矩阵初始化
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
			if(i == j){
				G->AdjMatrix[i][j] = 0;
			}
			else{
				G->AdjMatrix[i][j] = MaxInt;
			}
	    	
		}
	} 
	 
	// 4.构建邻接矩阵
	int n, m;
	VertexType v1, v2;
	// 顶点 v1、v2之间的权值 
	int w;
	 
	printf("请输入边的信息和权值(例：A B 15)：\n");
	// for循环：边数 
	for(i = 0; i < G->arcnum; i++){
		printf("请输入第 %d 条边信息及权值：",i+1);
		// 注：%c 前面需要添加空格符号 
	 	scanf(" %c %c %d", &v1,&v2,&w);
	 	
	 	//获取 v1、v2 所对应的在Vertex数组中的坐标 
	 	n = LocateVertex(G, v1); 
	 	m = LocateVertex(G, v2); 
	 	// 输入边的信息非法，重新输入 
	 	while(n == -1 || m == -1){
	 		printf("没有该边信息!\n");
	 		printf("请重新输入第 %d 条边信息及权值：", i+1);
	 		// 注：%c 前面需要添加空格符号 
	 		scanf(" %c %c %d", &v1, &v2, &w);
	 		n=LocateVertex(G, v1); 
	 		m=LocateVertex(G, v2); 
		} 
	 	// 将邻接矩阵相应位置赋上权值 
		G->AdjMatrix[n][m]=w;
	   	G->AdjMatrix[m][n]=w;
    } 
}

// 输出无向图 
void print(MGraph G){
	int i,j;
	printf("\n-------------------------------");
	printf("\n 邻接矩阵：\n\n"); 	
	
	printf("\t ");
	for(i = 0; i < G.vexnum; i++){
		printf("\t%c", G.Vertex[i]);
	}
	
	printf("\n");
		 
	for(i = 0; i < G.vexnum; i++){
   		printf("\t%c", G.Vertex[i]);
   	  	for(j = 0; j < G.vexnum; j++){
    		if(G.AdjMatrix[i][j] == MaxInt){
    			printf("\t∞");
			}
			else{
				printf("\t%d", G.AdjMatrix[i][j]);
			}
    	}
      	printf("\n");
    }	 
}
 
//找最短路径的顶点 （在 lowcost中 寻找 最小代价的顶点） 
// 注意：需要将 lowcost值已经为 0 的顶点排除掉 
int minimal(MGraph *G, ShortEdge *shortedge){
	int i, j;
	int min, locate;
	
	min = MaxInt;
	for(i = 0; i < G->vexnum; i++){
		// 代价最小 并且 不属于U集合 
		if(min > shortedge[i].lowcost && shortedge[i].lowcost != 0){
			min = shortedge[i].lowcost;
			// lowcost数组下标 表示 顶点序号 
			locate = i;
		}
	}
	// 返回 目前能到达的最小顶点（数组下标 表示 顶点序号 ） 
	return locate;
}

/*
	输出 最小生成树 路径 
	shortedge[5].adjvex = 0, shortedge[5].lowcost = 19
	表示 从 顶点0 出发 到达最短顶点5，代价为19 
*/
void outputMST(MGraph *G, VertexType k, ShortEdge shortedge[]){
	//输出找到的最短路径顶，及路径权值 
	printf("%c -> %c, weight = %d\n", shortedge[k].adjvex, G->Vertex[k], shortedge[k].lowcost);
}
 
// 最小生成树-普利姆算法 
void MiniSpanTree_Prim(MGraph *G, VertexType start){ 
	int i, j, k;
	ShortEdge shortedge[VertexMax];
	
	// 1.处理起始点start 
	k = LocateVertex(G, start);
	
	// 初始化辅助数组 shortedge（即 从开始顶点 到 其余顶点的代价） 
	for(i = 0; i < G->vexnum; i++){
		// 开始顶点start  到   顶点i 
		shortedge[i].adjvex = start;
		shortedge[i].lowcost = G->AdjMatrix[k][i];
	}
	// 将 起点start 放入集合U（已经生成的 部分最小生成树） 
	shortedge[k].lowcost = 0; //lowcost为0表示该顶点属于U集合 
	
	// 2.处理后续结点 
	//对集合U，去找最短路径的顶点 
	// 总共 vexnum 个顶点，开始顶点 已经处理了，因此只需要处理 vexnum - 1 个顶点 
	for(i = 0; i < G->vexnum-1; i++){
		//找 到达最短路径 的顶点 
		k = minimal(G, shortedge);
		//输出找到的最短路径顶，及路径权值 
		outputMST(G, k, shortedge); 
	    
	    //将找到的最短路径顶点加入集合U中，U集合扩展 
	    shortedge[k].lowcost = 0; 
	    
	    /* 
	        U集合中加入了新节点，通过 新加入节点 到达其他节点，
		   可能出现新的最短路径，故更新shortedge数组  
		*/
	    for(j = 0; j < G->vexnum; j++){ // 遍历 K顶点 到其他顶点 
			//有更短路径出现时，更新shortedge数组	 
	    	// 从 上一次求得的顶点 出发 到 V集合中的顶点，将 其代价 与 lowcost数组中的值进行比较 
	    	// G->AdjMatrix[k][j]：从 上一次求得的顶点 出发 到 V集合中的顶点 
	    	if(G->AdjMatrix[k][j] < shortedge[j].lowcost){
	    		// 到达顶点 j 的最短距离，从 K 到 j 
	    		shortedge[j].lowcost = G->AdjMatrix[k][j];
				// 经由 K 顶点，到达 j 顶点
	    		shortedge[j].adjvex = G->Vertex[k];
			}
		}
	} 
}

int main(){
	
	VertexType start;
	MGraph G;
	
	CreateUDN(&G);
	print(G); 
	
	while(true){
		printf("请输入起始点：");
		// 注：%c 前面需要添加空格符号 
		scanf(" %c", &start);
		MiniSpanTree_Prim(&G, start);
		int flag;
		printf("\n是否继续进行测试？（1：是，0：否）\n");
		scanf("%d", &flag);
		if(flag == 0){
			break;
		}
	} 
	
	return 0;
}
