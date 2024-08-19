#include<stdio.h>
#include<stdlib.h>

//������󶥵���� 
#define MaxVertices 100 
//���ڽ�ʱΪ32767�������ʱ�� "��"
#define MaxWeight 32767 

#include<stdio.h>
#include<stdlib.h>
//�ڽӾ���ṹ
typedef char VertexType;
typedef int EdgeType;
 
#define MAX 10
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef int Boole;  //�������� �洢TRUE FALSE
Boole visited[MAX];    //���ʱ�־���� 

//����Ȩ���ڽӾ���ĵĶ���
typedef struct{
	//������Ϣ������
    int Vertices[MaxVertices]; 
	//�ߵ�Ȩ��Ϣ������
    int Edge[MaxVertices][MaxVertices]; 
    //��ǰ�Ķ�����
    int numV; 
    //��ǰ�ı���
    int numE; 
}MGraph;

//ͼ�����ɺ���
void CreateGraph(MGraph *G){ 
    int n, e, vi, vj, w, i, j;
    printf("������ͼ�Ķ������ͱ������Կո�ָ�����");
    scanf("%d%d",&n,&e);
    G->numV = n;G->numE = e;
    //ͼ�ĳ�ʼ��
    for(i = 0;i < n; i++){
        for(j = 0;j < n; j++){ 
            if(i == j){
            	G->Edge[i][j] = 0;
			}  
            else{
            	G->Edge[i][j] = 32767;
			}     
        }
        
        //���������������
        for(i = 0; i < G->numV; i++){ 
            printf("�������%d���������Ϣ(����):",i+1);
            scanf("%d",&G->Vertices[i]);
        }
    }
        
    printf("\n");

    for(i = 0; i <G->numE; i++)
    { 
        printf("������ߵ���Ϣi,j,w(�Կո�ָ�):");
        scanf("%d%d%d",&vi,&vj,&w); 
        //��Ϊ����Ȩֵ��ͼ����w����1
        //��Ϊ��Ȩֵ��ͼ����w�����ӦȨֵ

        G->Edge[vi-1][vj-1]=w;//��
        // G->Edge[vj-1][vi-1]=w;//��
        //����ͼ���жԳ��ԵĹ��ɣ�ͨ���٢�ʵ��
        //����ͼ���߱������ʣ�����ֻ��Ҫ��
    }
}

//����ڽӾ������Ϣ
void DispGraph(MGraph G){ 
    int i,j;
    printf("\n����������Ϣ�����ͣ�:\n");
    for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);

    printf("\n����ڽӾ���:\n");
    printf("\t");
    for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //����֮��������ʱȨֵΪĬ�ϵ�32767��
        // ������ͼ��һ����"0"��ʾ��������ͼ��һ����"��",
        // ����Ϊ�˷���ͳһ��� "��"
            printf("%8s", "��");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}

//������ȵݹ��㷨
void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TRUE;   //�����ʵı�� 
	printf("%c->",G.Vertices[i]);
	for(j=0;j<G.numV;j++){
		//��(i,j)������j����δ�����ʣ��ݹ�
		if(G.Edge[i][j]==1&&!visited[j]){
			DFS(G,j);
		}  	
	} 
}
 
//������ȱ���
void DFStraverse(MGraph G)
{
	
	int i;
	for(i=0;i<G.numV;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numV;i++)
			if(!visited[i])
				DFS(G,i);		
				
} 

int main()
{ 
    MGraph G;
    CreateGraph(&G);
    DispGraph(G);
}