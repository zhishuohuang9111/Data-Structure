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
		t = (treenode *) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 从 大 到 小 输出：右  根  左 
void Out(tree t, char k){
	if(t == NULL){
		return;
	}
	// 右子树不为空，递归调用右子树 
	if(t->rchild != NULL){
		Out(t->rchild, k);
	}
	
	// 根结点值 > K：根输出
	if(t->data >= k){
		printf("%c	", t->data);
	} 
	
	// 左子树不为空， 递归调用左子树
	if(t->lchild != NULL){
		Out(t->lchild, k); 
	}	
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	
	Out(t, 'E');
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
}
