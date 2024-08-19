#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

/*
		判断是否为满二叉树：
		1、若节点无左孩子，则必定无右孩子
		2、若节点无孩子，则层次遍历中，后继节点也必无孩子 
*/

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
		t = (treenode *) malloc(sizeof(treenode));
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

bool isCompleteBinaryTree(tree t){
	Queue q;
	InitQueue(q);
	// 空树 
	if(t == NULL){
		return true;
	}
	// 只有 根结点 
	if(t->lchild == NULL && t->rchild == NULL){
		return true;
	}
	// flag 为 true 表示：之前遍历的结点 都有左右孩子  
	bool flag = true;
	// 根结点 入队 
	treenode *p = t;
	EnQueue(q, p);
	
	// 队列不为空时，while执行 
	while(!isEmpty(q)){
		DeQueue(q, p);
		
		if(!p->lchild){ // 缺 左孩子 
			flag = false;
			if(p->rchild){
				// 缺 左孩子， 有 右孩子：不是完全二叉树 
				return false;
			}
		}
		// 当前结点 有 左孩子 
		else{
			// flag == true：表示 之前不存在 缺孩子 结点 
			if(flag){
				EnQueue(q, p->lchild); // 左孩子 进队
				 
				if(p->rchild){
					// 右孩子 进队 
					EnQueue(q, p->rchild);
				}
				else{
					// 有左孩子，无右孩子 
					flag = false;
				} 
			} 
			// 之前存在 缺孩子的结点，而该节点又存在孩子节点
			// 则 该二叉树一定不是二叉树 
			else{
				return false; 
			} 
		} 
	}
	return true; 
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	
}

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	disp(t);
	
	if(isCompleteBinaryTree(t)){
		printf("yes!!!");
	}
	else{
		printf("no!!!");
	}
	
	return 0;
} 
