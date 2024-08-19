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

// 构建 有向图 邻接表 
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
		
		// 输入边的信息非法，重新输入 
	 	while(v1 < 0 || v1 > G->vexnum - 1 || v2 < 0 || v2 > G->vexnum - 1){
	 		printf("NO This Vertex!\n");
	 		printf("请重新 输入第%d条边信息及权值：",i+1);
	 		scanf("%d %d %d",&v1,&v2,&weight);
		} 
		ArcNode* p = (ArcNode*) malloc(sizeof(ArcNode));	//生成新结点(指针p1指向该结点，用p1代表该结点)
		p->adjvex = v2;	//邻接点在一维数组中的下标值赋值给该结点
		p->weight = weight; // 权值信息 
		// 链表 采用头插法 
		p->nextarc = G->vertices[v1].firstarc;	
		G->vertices[v1].firstarc = p;	
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

// 输出 邻接表 
void printReverse(ALGraph G){
	bool flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		ArcNode* p = G.vertices[i].firstarc;
		if(p == NULL){
			printf("顶点 %d 的入度为 0", i);
			flag = false;
		}
		if(flag){
			printf("顶点 %d 入队的边有：", i);
			while(p != NULL){
				printf("顶点 %d 到顶点 %d，权值为：%d ", p->adjvex, i, p->weight);
				p = p->nextarc;
			}
		}
		
		printf("\n");
	}
}

void Reverse(ALGraph GA, ALGraph &GB){
	GB.vexnum = GA.vexnum;
	GB.arcnum = GA.arcnum;
	//输入各点，构造一维数组
	for(int i = 0; i < GB.vexnum; ++i){
		// 数组下标 就是 顶点值 
		GB.vertices[i].data = i;
		GB.vertices[i].firstarc = NULL;	//初始化顶点指针域
	}
	for(int i = 0; i < GA.vexnum; i++){
		ArcNode* p = GA.vertices[i].firstarc;
		while(p != NULL){
			int j = p->adjvex;
			ArcNode* q = (ArcNode*) malloc(sizeof(ArcNode));
			q->adjvex = i;
			q->weight = p->weight;
			
			q->nextarc = GB.vertices[j].firstarc;
			GB.vertices[j].firstarc = q;
			
			p = p->nextarc;
		}
	}
}

int main(){
	
	ALGraph LA, LB;
	CreateUDG(&LA);
	printLG(LA);
	printf("\n");
	Reverse(LA, LB);
	printReverse(LB);
	
	return 0;
} 
