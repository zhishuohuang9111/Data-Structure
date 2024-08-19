#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VertexMax 20 //最大顶点数为20
#define MaxInt 32767 //表示最大整数，表示 ∞ 

typedef char VertexType; //每个顶点数据类型为字符型 

typedef struct
{
	VertexType Vertex[VertexMax];//存放顶点元素的一维数组 
	int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组 
	int vexnum,arcnum;//图的顶点数和边数  
}MGraph;

int LocateVex(MGraph *G,VertexType v)//查找元素v在一维数组 Vertex[] 中的下标，并返回下标 
{
	int i;
	
	for(i=0;i<G->vexnum;i++)
	{
		if(v==G->Vertex[i])
		{
			return i; 
		} 
	 } 
	 
	 printf("No Such Vertex!\n");
	 return -1;
}

void CreateDN(MGraph *G) 
{
	int i,j;
	//1.输入顶点数和边数 
	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边  数 e="); 
	scanf("%d",&G->arcnum);

	//2.输入顶点元素 
	printf("输入顶点元素(无需空格隔开)：");
	scanf("%s",G->Vertex);
	printf("\n");
	//3.矩阵初始化
	for(i=0;i<G->vexnum;i++) 
	 for(j=0;j<G->vexnum;j++)
	    {
	    	G->AdjMatrix[i][j]=MaxInt;
		}
	
	 //4.构建邻接矩阵
	 int n,m;
	 VertexType v1,v2;
	 int w;//v1->v2的权值 
	 
	 printf("输入路径及路径长度：\n");
	 for(i=0;i<G->arcnum;i++)
	 {
	 	printf("输入第%d条路径信息：",i+1);
	 	scanf(" %c%c,%d",&v1,&v2,&w);
	 	n=LocateVex(G,v1); //获取v1所对应的在Vertex数组中的坐标 
	 	m=LocateVex(G,v2); //获取v2所对应的在Vertex数组中的坐标
	 	
	 	if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		  } 
	
	   G->AdjMatrix[n][m]=w;
	 }
}

void print(MGraph G)
{
	int i,j;
	printf("\n-----------------------------------------------");
	printf("\n 邻接矩阵：\n\n"); 
		
		printf("\t ");
		for(i=0;i<G.vexnum;i++)
		printf("\t%c",G.Vertex[i]);
		printf("\n");
		 
		for(i=0;i<G.vexnum;i++)
	   {
	   	  printf("\t%c",G.Vertex[i]);
	   	  
		  for(j=0;j<G.vexnum;j++)
	    {
	    	
	    	if(G.AdjMatrix[i][j]==MaxInt)
	 	    printf("\t∞");
	 	    else printf("\t%d",G.AdjMatrix[i][j]);
	    }
	      printf("\n");
	   }
	printf("\n-----------------------------------------------\n"); 
}

int dist[VertexMax][VertexMax];
VertexType path[VertexMax][VertexMax][VertexMax];  

// 字符串拼接，形成新的path路径 
char *NewPath(char temp1[VertexMax],char temp2[VertexMax]){
	int i=0;
	static char ch1[VertexMax],ch2[VertexMax];
	
	for(i=0;i<VertexMax;i++){
		ch1[i] = temp1[i];
		ch2[i] = temp2[i]; 
	}
	i=0;
	
    while(ch1[i]!='\0'){
    	i++;
	}
	
	if(ch1[i-1]!=ch2[0]){
		strcpy(&ch1[i],&ch2[0]);
	}
	else if(ch1[i-1]==ch2[0]){
		strcpy(&ch1[i-1],&ch2[0]);
	}
	
   return ch1;
}

void ShortestPath_Floyd(MGraph G){
	int i,j,k;
	char temp1[2]="0",temp2[2]="0";
	// dist[][]、path[][]数组的初始化 
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			dist[i][j]=G.AdjMatrix[i][j];
			// 有 权值，更新path数组 
			if(dist[i][j] != MaxInt){
              	temp1[0] = G.Vertex[i];
              	temp2[0] = G.Vertex[j];
              	strcpy(path[i][j],NewPath(temp1,temp2));
			}
			// 无权值、权值为0，path数组为空串 
			else{
				strcpy(path[i][j],"0");
			}
		}
	}
	
	//拿出每个顶点作为遍历条件，即 将 顶点K 作为中间顶点，看是否有最短路径 
	for(k = 0; k < G.vexnum; k++){
		// 两层 for 循环，遍历 dist[][]二维数组 
		for(i = 0; i < G.vexnum; i++){
			for(j = 0; j < G.vexnum; j++){
				// dist[i][j]：顶点i 到 顶点j 路径长度
				// dist[i][k]+dist[k][j]：顶点i 经由顶点K 到 顶点j 路径长度 
		   	    if(dist[i][j] > dist[i][k]+dist[k][j]){
		   	    	// 路径长度更新 
		   	    	dist[i][j] = dist[i][k] + dist[k][j];
		   	    	// 路径更新 
		   	    	strcpy(path[i][j],NewPath(path[i][k],path[k][j]));
				} 
	        }
		}	  
	}	 
}	  


void DisplayPath(MGraph G){
	
	int i,j,k;
	
	printf("Dist:\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(dist[i][j]==MaxInt)
			{
				printf("\t∞");
			}
			else printf("\t%d",dist[i][j]);
		}
		printf("\n");
	}
	
	printf("Path:\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("\t%s",path[i][j]); 
		}
		printf("\n");
	}
	printf("\n"); 
	
	for(i=0;i<G.vexnum;i++)//打印最短路径 
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("%c到%c的最短路径:",G.Vertex[i],G.Vertex[j]);
			if(path[i][j][0]=='0')
			{
				printf("不可达\n\n"); 
			}
			else
			{
				printf("%s",path[i][j]);
				printf(" (%d)\n\n",dist[i][j]);
			} 
			
		}
	}
}

int main() 
{
	MGraph G;
	VertexType start;

	CreateDN(&G);
	print(G);
	ShortestPath_Floyd(G);
    DisplayPath(G);
	return 0;
}

