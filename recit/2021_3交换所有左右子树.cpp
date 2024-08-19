#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

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
 
void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}
	
} 

// 交换左右子树 
void swap(tree &t){
	// 结点 非空 
	if(t){
		// 递归交换左子树 
		swap(t->lchild);
		// 递归交换右子树 
		swap(t->rchild);
		// 交换 根结点的左右子树 
		treenode* p = t->lchild;
		t->lchild = t->rchild;
		t->rchild = p;
	}
}

int main(){
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	
	swap(t);
	
	printf("交换后的二叉树为：");
	disp(t); 
	
	/*
				F
			E		H
		 C        G    I
	  A    D
	    B
	*/
	
	return 0;
}
