#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
	// tag = 0：有左右孩子  tag = 1：无左右孩子 
	int ltag, rtag;
}treenode, *tree; 

void buildtree(tree &t){
	char ch;
	// 输入 
	cin>>ch;
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		t->ltag = 0;
		t->rtag = 0;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 定义为全局变量 
tree pre;

// 中序线索化
void InThread(tree t){
	// 结点 非空 
	if(t){
		// 向左延申 找中序遍历的第一个结点 
		InThread(t->lchild); // 左子树线索化 
		
		if(t->lchild == NULL){ // 左孩子 为空 
			t->ltag = 1;
			// 将 左孩子指针 指向 中序变量时的 前驱结点 
			t->lchild = pre;
		} 
		
		if(pre != NULL && pre->rchild == NULL){ // 前驱结点 不为空 且 前驱结点无右孩子 
			pre->rtag = 1; // 前驱结点有后继 
			pre->rchild = t;  // 将 前驱的右孩子指针 指向 当前结点 
		}
		// 更新前驱结点 
		pre = t;
		
		InThread(t->rchild); // 右子树线索化 
	}
} 

treenode *q;

// 中序线索化 找后继 
treenode* ThreadNext(tree t){
	// 右标志为 1，可直接得到 后继结点 
	if(t->rtag == 1){
		q = t->rchild;
	}
	// 右标志为 0，则 后继为 右子树最左下角结点 
	else{
		q = t->rchild;
		// 查找 最左下结点 
		while(q->ltag == 0){ // q 的左标记 
			q = q->lchild;
		}
	}
	return q; 
} 

void visit(treenode *p){
	printf("%c	", p->data);
}

// p->tag = 1：右指针就是线索
// p->tag = 0：该结点有右孩子，则其后继为 右子树中的最左下结点 
void ThreadInOrder(tree t){
	treenode *p;
	// 树为空 
	if(t == NULL){
		return;
	}
	p = t;
	// 查找中序遍历的第一个结点 
	while(p->ltag == 0){ // p 的左标记 
		p = p->lchild;
	}
	// 访问第一个结点 
	printf("当前结点：%c	", p->data);
	visit(p);
	// 当前 p结点存在后继，依次访问后继结点 
	while(p->rchild != NULL){
		p = ThreadNext(p);
		visit(p);
	}
} 

int main(){
	
	tree t;
	// 先序序列：ABD##E##CF##G##
	// ABD##E##CF### (该序列不对)
	buildtree(t);
	// 线索化 
	InThread(t);
	
	// 线索化后，中序遍历 
	ThreadInOrder(t);
	
	/*
				A
			B		C
		  D   E   F    G
	*/
	 
	return 0;
}
