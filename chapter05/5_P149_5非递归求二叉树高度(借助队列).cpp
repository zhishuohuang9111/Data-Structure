#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

// 非递归计算二叉树的高度

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
} 

typedef struct{
	treenode *data[Max];
	int front;
	int rear;
	int tag;
}Queue;

void InitQueue(Queue &q){
	q.front = 0;
	q.rear = 0;
	q.tag = 0;
}

bool isFull(Queue q){
	if(q.front == q.rear && q.tag == 1){
		return true;
	}
	return false;
}

bool isEmpty(Queue q){
	if(q.front == q.rear && q.tag == 0){
		return true;
	}
	return false;
}

void EnQueue(Queue &q, treenode *x){
	if(isFull(q)){
		printf("队满\n");
		return;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % Max;
	q.tag = 1;
}

void DeQueue(Queue &q, treenode *&x){
	if(isEmpty(q)){
		printf("队空\n");
		return;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % Max;
	q.tag = 0;
}

int dept(tree t){
	// 树为空 高度为0 
	if(!t){
		return 0;
	}
	Queue q;
	InitQueue(q);
	treenode *p = t; 
	int depth = 0;
	
	EnQueue(q, p);
	printf("节点 %c	入队\n", p->data);
	int Latest = q.rear;
	
	// 队列非空 
	while(!isEmpty(q)){
		DeQueue(q, p);
		printf("节点 %c	出队\n", p->data);
		// 左右孩子不为空，分别入队 
		if(p->lchild){
			EnQueue(q, p->lchild);
			printf("节点 %c	入队\n", p->lchild->data);
		}
		if(p->rchild){
			EnQueue(q, p->rchild); 
			printf("节点 %c	入队\n", p->rchild->data);
		}
		// f == L：表示遍历到当前层 的 最右 结点，
		// 当前层的下一层所有节点都已经入队 
		if(q.front == Latest){
			// 高度 + 1 
			depth++;
			// L 指向下一层 的 最右 结点 
			Latest = q.rear;
		}
	}
	return depth; 
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	printf("树高：%d", dept(t));
	
	return 0;
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 





