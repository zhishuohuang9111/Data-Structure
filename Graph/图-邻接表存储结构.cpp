#include <stdio.h>
#include <stdlib.h>
#define VertexType char //顶点的数据类型（char） 
#define VertexMax 20 //最大顶点个数 

//边表 
typedef struct ArcNode{
	int adjvex;//存储的是该顶点在顶点数组即AdjList[]中的位置 
	struct ArcNode *next;
}ArcNode;

//单个顶点 
typedef struct VNode {
	VertexType vertex;
	struct ArcNode *firstarc;
}VNode;

//顶点表 
typedef struct{
	VNode AdjList[VertexMax];//由顶点构成的结构体数组 
	int vexnum,arcnum; //顶点数和边数 
	int kind; //记录图的类型 
}ALGraph;

int LocateVex(ALGraph *G, VertexType v){    
    int i;
	for(i=0;i<G->vexnum;i++)
	{
		if(v==G->AdjList[i].vertex)
		{
			return i;
		}
	}
	
	printf("No Such Vertex!\n");
	return -1;
}

//1.有向图 
void CreateDG(ALGraph *G){
	int i,j;
	//1.输入顶点数和边数 
	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边  数 e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	printf("\n");
	//2.顶点表数据域填值初始化顶点表指针域 
	printf("输入顶点元素(用空格隔开)：");
	for(i=0;i<G->vexnum;i++)
	{
		scanf(" %c",&G->AdjList[i].vertex);
		G->AdjList[i].firstarc=NULL;
	} 
	printf("\n");
	
	//3.输入边信息构造邻接表 
	int n,m;
	VertexType v1,v2;
	ArcNode *p1,*p2; 
	
	printf("请输入边的信息：\n\n"); 
	for(i=0;i<G->arcnum;i++)
	{   //输入边信息，并确定v1和v2在G中的位置，即顶点在AdjList[]数组中的位置（下标）  
		printf("输入第%d条边信息：",i+1); 
		scanf(" %c%c",&v1,&v2);
		n=LocateVex(G,v1);
		m=LocateVex(G,v2);
		
		if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		 } 
		
		p1=(ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex=m;//填上坐标 
		p1->next=G->AdjList[n].firstarc;//改链（头插法）  
		G->AdjList[n].firstarc=p1;
	
	}//for  
	G->kind=1;
} 

//2.无向图 
void CreateUDG(ALGraph *G)
{
	int i,j;
	//1.输入顶点数和边数
	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边  数 e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	printf("\n");
	//2.顶点表数据域填值初始化顶点表指针域
	printf("输入顶点元素(无需空格隔开)：");
	for(i=0;i<G->vexnum;i++)
	{
		scanf(" %c",&G->AdjList[i].vertex);
		G->AdjList[i].firstarc=NULL;
	} 
	printf("\n");
	
	//3.输入边信息构造邻接表
	int n,m;
	VertexType v1,v2;
	ArcNode *p1,*p2; 
	
	printf("请输入边的信息：\n\n"); 
	for(i=0;i<G->arcnum;i++)
	{   //输入边信息，并确定v1和v2在G中的位置，即顶点在AdjList[]数组中的位置（下标） 
		printf("输入第%d条边信息：",i+1); 
		scanf(" %c%c",&v1,&v2);
		n=LocateVex(G,v1);
		m=LocateVex(G,v2);
		
		if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		  } 
		
		p1=(ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex=m;//填上坐标 
		p1->next=G->AdjList[n].firstarc;//改链（头插法） 
		G->AdjList[n].firstarc=p1;
		
		p2=(ArcNode *)malloc(sizeof(ArcNode));//无向图的对称 
		p2->adjvex=n;
		p2->next=G->AdjList[m].firstarc;
		G->AdjList[m].firstarc=p2;
		
	}//for 
	G->kind=2; 
} 

void print(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("\n-------------------------------");
	printf("\n图的邻接表表示：\n");
	
	for(i=0;i<G.vexnum;i++)
	{
		printf("\n   AdjList[%d]%4c",i,G.AdjList[i].vertex);
		p=G.AdjList[i].firstarc;
		
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex);
			p=p->next;
		}
	 } 
	 printf("\n");
} 

void GraphChoice(ALGraph *G)
{
	int target;
    printf(" 请选择图的类型：1.有向图DG  2.无向图UDG\n\n");
    scanf("%d",&target);//选择图的类型 
    printf("\n");

    switch (target) //根据所选类型，调用不同的函数实现构造图的功能 
	{
        case 1:
        	 printf("您选择的是 1.DG\n\n"); 
        	 printf("-------------------------------\n");
             CreateDG(G);
            break;
        case 2:
        	 printf("您选择的是 2.UDG\n\n"); 
        	 printf("-------------------------------\n");
             CreateUDG(G);
            break;
        default:
        	printf("无效选择!!!请重新选择！\n\n"); 
        	printf("-------------------------------\n");
			GraphChoice(G);   
            break;
    }
}

int main() 
{
	ALGraph G;
	GraphChoice(&G);
	print(G);
	
	return 0;
}

