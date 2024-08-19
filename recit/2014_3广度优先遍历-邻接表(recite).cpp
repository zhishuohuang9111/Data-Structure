#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞
#define Maxsize 100 //队列最大元素个数100

typedef int VertexType; //每个顶点数据类型为字符型 
typedef int dataType; //队列元素类型 

//单链表中的结点
typedef struct ArcNode{	
	int adjvex;	// 该弧所指向的顶点的位置 
	struct ArcNode *nextarc;	//指向下一条弧的指针 
	int weight;	//边信息，如权值
}ArcNode;
	
//顶点（存储在一维数组中）
typedef struct VNode{
	VertexType data; //顶点信息
	// 指针类型为 ArcNode结构体类型 
	ArcNode *firstarc;	//顶点的第一邻接点
}VNode,AdjList[VertexMax];	//AdjList表示邻接表类型

//邻接表
typedef struct{
	// AdjList[MVNum]：数组类型，数组的每一个元素为 VNode类型 
	AdjList vertices;	//一维数组 vertices
	int vexnum, arcnum;	//图的当前顶点数和边数
}ALGraph;

/*队列结构体*/
typedef struct{
	dataType *base;
	int front;
	int rear;
	int tag;
}Queue;

/*循环队列基本操作*/
void InitQueue(Queue &q){
	q.base = (dataType *)malloc(Maxsize *sizeof(dataType));
	if(!q.base){
		printf("内存分配失败!\n");
		return;
	}
	q.front = q.rear = 0;
	q.tag = 0;
	return;
}

void EnQueue(Queue &q, dataType value){
	if(q.rear == q.front && q.tag == 1){
		printf("队满!\n");
		return;
	}
	q.base[q.rear] = value;
	q.rear = (q.rear+1) % Maxsize;
	q.tag = 1;
	return;
}

void DeQueue(Queue &q, dataType &value){
	if(q.front == q.rear && q.tag == 0){
		printf("队空!\n");
		return;
	}
	value = q.base[q.front];
	q.front = (q.front+1) % Maxsize;
	q.tag = 0;
	return;
} 

bool isEmpty(Queue q){
    if (q.front == q.rear && q.tag == 0){
        return true;
    }
    return false;
}

/*广度优先遍历*/
int visited[VertexMax]; //定义数组为全局变量 

void BFS(ALGraph *G, int i){
	int j;
	struct ArcNode *p;
	Queue q;
	InitQueue(q);
	
    //1.设置起始点
	printf("%d	",G->vertices[i].data);//1.输出起始结点
	visited[i] = 1;//2.将已访问的结点标志成 1
	EnQueue(q, i);//3.将第一个结点入队 

    //2.由起始点开始，对后续结点进行操作
	while(!isEmpty(q)){
		DeQueue(q, i);
		
		p = G->vertices[i].firstarc;
		
		while(p != NULL){
			
			if(visited[p->adjvex] == 0){
				printf("%d	", G->vertices[p->adjvex].data);
	            visited[p->adjvex] = 1;
	            EnQueue(q, p->adjvex);
			}
			p = p->nextarc;//查找完之后，将p向后推一位 
		}
	} 	
} 

void BFSTraverse(ALGraph *G){
	int i;
	
	//数组初始化为全0 
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	} 
	
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			BFS(G, i);
		}
	}
} 

int main() {
	ALGraph G; 
	// CreateUDG(&G);
	
	printf("\n\n广度优先遍历："); 
	BFSTraverse(&G); 
	 
	return 0;
}	

