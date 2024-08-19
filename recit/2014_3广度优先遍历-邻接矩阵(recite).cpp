#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //最大顶点数为100
#define Maxsize 100 //队列最大元素个数100 

typedef int VertexType; //每个顶点数据类型为字符型 
typedef int dataType; //队列元素类型 

/*图结构体*/
typedef struct{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum, arcnum;//图的顶点数和边数  
}MGraph;

/*队列结构体*/
typedef struct{
	dataType *base;
	int front;
	int rear;
	int tag;
}Queue;

/*循环队列基本操作*/
void InitQueue(Queue &q){
	q.base = (dataType *)malloc(Maxsize*sizeof(dataType));
	if(!q.base){
		printf("空间分配失败!\n");
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

/*广度优先遍历BFS*/ 
int visited[VertexMax];//定义"标志"数组为全局变量 

void BFS(MGraph *G, int i){
	int j;
	Queue q;
	InitQueue(q);
   //1.设置起始点 
   //  输出当前结点， 
	printf("%d	", G->Vertex[i]);
	// 将已访问的结点标志成 1
	visited[i] = 1;
	// 将第一个结点入队 
	EnQueue(q, i);
    
    //2.由起始点开始，对后续结点进行操作
	while(!isEmpty(q)){
		
		DeQueue(q,i);
		
		for(j = 0; j < G->vexnum; j++){
			if(G->AdjMatrix[i][j] == 1 && visited[j] == 0){
				// 输出 并 入队 
				printf("%d	",G->Vertex[j]);
	            visited[j] = 1;
	            EnQueue(q, j);
			}
		}
	} 	
} 

void BFSTraverse(MGraph *G, int start){
	int i;
	//数组初始化为全0 
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	} 
	
	BFS(G, start);
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			BFS(G, i);
		}
	}
} 

int main(){
	MGraph G; 
	CreateUDG(&G);
	
	printf("广度优先遍历："); 
	int start = 5
	BFSTraverse(&G, start); 
	 
	return 0;
}	
