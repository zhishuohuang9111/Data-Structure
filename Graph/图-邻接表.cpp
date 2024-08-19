#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞

#define MVNum 100
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
	ArcNode *firstarc;	//顶点的第一邻接点
}VNode,AdjList[MVNum];	//AdjList表示邻接表类型

//邻接表
typedef struct{
	// AdjList[MVNum]：数组类型 
	AdjList vertices;	//一维数组vertices
	int vexnum,arcnum;	//图的当前顶点数和边数
}ALGraph;

//查找元素v在一维数组 Vertex[] 中的下标，并返回下标 
int LocateVex(ALGraph *G, VertexType v){
	int i;
	for(i = 0; i < G->vexnum; i++){
		if(v == G->vertices[i].data){
			return i; 
		} 
	} 
	printf("No Such Vertex!\n");
	return -1;
}


// 构建 无向图 邻接表 
void CreateUDG(ALGraph *G){
	int i;
	//1.输入顶点数和边数 
	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边数 e="); 
	scanf("%d",&G->arcnum);
	
	//输入各点，构造一维数组
	for(i = 0; i < G->vexnum; ++i){
		// 数组下标 就是 顶点值 
		G->vertices[i].data = i;
		G->vertices[i].firstarc = NULL;	//初始化顶点指针域
	}
	
	//输入各边，构造邻接表
	VertexType v1,v2;
	int weight;//v1->v2的权值 
	int n,m;
	for(i = 0; i < G->arcnum; i++){
		printf("输入第%d条路径信息：",i+1);
	 	scanf("%d %d %d",&v1,&v2,&weight);
		n = LocateVex(G,v1);	//确定顶点v1在图G中的位置（一维数组下标）
		m = LocateVex(G,v2);	//确定顶点v2在图G中的位置（一维数组下标）
		
		// 输入边的信息非法，重新输入 
	 	while(n == -1 || m == -1){
	 		printf("NO This Vertex!\n");
	 		printf("请重新 输入第%d条边信息及权值：",i+1);
	 		scanf("%d %d %d",&v1,&v2,&weight);
	 		n=LocateVex(G,v1); 
	 		m=LocateVex(G,v2); 
		} 
		
		ArcNode* p1 = (ArcNode*) malloc(sizeof(ArcNode));	//生成新结点(指针p1指向该结点，用p1代表该结点)
		p1->adjvex = m;		//邻接点在一维数组中的下标值赋值给该结点
		p1->weight = weight;
		// 链表 采用头插法 
		p1->nextarc = G->vertices[n].firstarc;	
		G->vertices[n].firstarc = p1;	
		
		ArcNode* p2 = (ArcNode*) malloc(sizeof(ArcNode));	//生成新结点(指针p2指向该结点，用p2代表该结点)
		p2->adjvex = n;		//邻接点在一维数组中的下标值赋值给该结点
		p2->weight = weight;
		
		p2->nextarc = G->vertices[m].firstarc;
		G->vertices[m].firstarc = p2;	
	}
	return;
}

// 输出 邻接表 
void printLG(ALGraph G){
	bool flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		ArcNode* p = G.vertices[i].firstarc;
		if(p == NULL){
			printf("顶点 %d 的出度为 0", i);
			flag = false;
		}
		if(flag){
			printf("从 顶点 %d 出发的边有：", i);
			while(p != NULL){
				printf("顶点 %d 到顶点 %d，权值为：%d ", i, p->adjvex, p->weight);
				p = p->nextarc;
			}
		}
		
		printf("\n");
	}
}

int main(){
	
	ALGraph LG;

	CreateUDG(&LG);

	printLG(LG);
	
	return 0;
}


