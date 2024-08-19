#include<stdio.h>
#include <stdlib.h>

using namespace std;

#define Max 20

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *) malloc(sizeof(treenode));
		// 赋值 
		t->data = ch;
		// 左右孩子先置空 
		t->lchild = NULL;
		t->rchild = NULL;
		
		// 左右孩子递归赋值 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

typedef struct{
	treenode* data[Max];
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


// 层次遍历 
int width(tree t){
	Queue q;
	InitQueue(q); 
	
	treenode* p = t; 
	EnQueue(q, p);
	int Latest = q.rear;
	
	int count = 0;
	int max = 1;
	int depth = 0;

	while(!isEmpty(q)){
		DeQueue(q, p); 
		// 左孩子非空，左孩子进队
		if(p->lchild != NULL){
			EnQueue(q, p->lchild);
			count++;
		}
		// 右孩子非空，右孩子进队 
		if(p->rchild != NULL){
			EnQueue(q, p->rchild);
			count++;
		}
		
		if(Latest == q.front){
			max = count > max ? count : max;
			Latest = q.rear;
			depth++;
			count = 0; 
		}
	}
	printf("depth = %d\n", depth);
	return max;
}

void disp(tree t){
	// 判断当前节点 是否为 NULL 
	if(t){
		disp(t->lchild);
		printf("%c	", t->data);
		disp(t->rchild);
	}
}

int main(){
	
	tree t;
	// ABD##E##CF##G##
	// 先序序列：FECA#B##D###HGJ##K##IL##M##
	buildtree(t);
	disp(t);
	printf("\n");
	
	int w = width(t); 
	printf("width = %d\n", w);
	/*
				A
			B		C
		  D   E   F    G
	*/ 
	
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	
	return 0;
}
