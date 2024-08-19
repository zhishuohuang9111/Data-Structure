#include<stdio.h>
#include <stdlib.h>

using namespace std;

#define Max 20

typedef struct treenode{
	int data;
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

void disp(tree t){
	// 判断当前节点 是否为 NULL 
	if(t){
		disp(t->lchild);
		printf("%c	", t->data);
		disp(t->rchild);
	}
}

int wpl_LevelOrder(tree t){
	if(t == NULL){
		return 0;
	}
	if(t->lchild == NULL && t->rchild == NULL){
		return t->data -'0';
	}
	
	Queue q;
	InitQueue(q);
	int deep = 0;
	int wpl = 0;
	// 将 根节点入队后，再将 Latest = q.rear 
	treenode* p = t;
	EnQueue(q, p);
	int Latest = q.rear;
	
	while(!isEmpty(q)){
		DeQueue(q, p);
		if(p->lchild == NULL && p->rchild == NULL){
			wpl += (p->data-'0') * deep;
		}
		if(p->lchild != NULL){
			EnQueue(q, p->lchild);
		}
		if(p->rchild != NULL){
			EnQueue(q, p->rchild);
		}
		
		if(q.front == Latest){
			Latest = q.rear;
			deep++;
		}
	}
	return wpl;
}

int main(){
	
	tree t;
	// 124##5##36##7## 
	// 12##3##
	buildtree(t);
	disp(t);
	printf("\n");
	int wpl = wpl_LevelOrder(t);
	printf("wpl = %d	", wpl);
	/*
				1
			2		3
		  4   5   6   7
	*/

	return 0;
}
