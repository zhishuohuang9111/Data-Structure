#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 10

// 层次遍历的 逆序输出 
// 队列 + 栈 

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// 先序建树 
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

typedef struct stack{
	// 栈存的类型是 指针 
	struct treenode *data[Max];
	int top; 
}stack;

bool isEmptyStack(stack s){
	// 栈为空 
	if(s.top == -1){
		return true;
	}
	// 栈非空 
	return false; 
} 

bool isFullStack(stack s){
	// 栈为满 
	if(s.top == Max -1){
		return true;
	}
	// 栈非满 
	return false;
} 

bool enterStack(stack &s, treenode *p){
	if(isFullStack(s)){
		printf("栈满");
		return false;
	}
	s.data[++s.top] = p;
	return true;
} 

bool outStack(stack &s, treenode *&p){
	if(isEmptyStack(s)){
		printf("栈空");
		return false;
	}
	p = s.data[s.top--];
	return true;
}

typedef struct squeue{
	treenode *data[Max];
	// f:头指针 r:尾指针 tag:判断队列是否 空 或 满 
	int f,r,tag;	
}squeue;

bool isEmptyQueue(squeue q){
	if(q.f == q.r && q.tag == 0){
		return true;
	}
	return false;
}

bool isFullQueue(squeue q){
	if(q.f == q.r && q.tag == 1){
		return true;
	}
	return false;
}

bool entersqueue(squeue &q, treenode *x){
	if(isFullQueue(q)){
		printf("队满");
		return false;
	}
	q.data[q.r] = x;
	q.r = (q.r + 1) % Max;
	q.tag = 1;
	return true; 
}

// *& x 结果需要带回，且是指针类型 
// &：表示 结果 需要带回，*：表示指针类型 
bool outsqueue(squeue &q, treenode* &x){
	if(isEmptyQueue(q)){
		printf("队空");
		return false;
	}
	x = q.data[q.f];
	q.f = (q.f + 1) % Max;
	q.tag = 0;
	return true;
}

void solve(tree t){
	stack s;
	squeue q;
	treenode *p;
	if(t){
		s.top = -1;
		q.f = q.r = 0;
		q.tag = 0; 
		// 入队 
		entersqueue(q, t);
		// 当队列非空时，while循环执行 
		// 层次遍历 
		while(!isEmptyQueue(q)){
			// p 指针 保存出队节点 
			outsqueue(q, p); // 出队 
			enterStack(s, p); // 入栈 
			// 如果 左右孩子存在，分别进队 
			if(p->lchild != NULL){
				entersqueue(q, p->lchild);
			}
			if(p->rchild != NULL){
				entersqueue(q, p->rchild);
			}
		}
		
		// 当 栈 非空时，while循环执行 
		while(!isEmptyStack(s)){
			outStack(s, p);
			printf("%c	", p->data); 
		} 
	}
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	solve(t);
	return 0;
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
}
