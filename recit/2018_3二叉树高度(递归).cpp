#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode*) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild); 
	}
}

void InOrder(tree t){
	if(t){
		InOrder(t->lchild);
		printf("%c	", t->data);
		InOrder(t->rchild);
	}
}

int height(tree t){
	// 树 为 空树 
	if(t == NULL){
		return 0;
	}
	
	int h1 = height(t->lchild);
	int h2 = height(t->rchild);
	
	if(h1 < h2){
		h1 = h2;
	}
	// 树的高度为：子树最高高度 + 根节点 
	return h1 + 1;
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	
	int h = height(t);
	printf("%d	", h);
	
	return 0;
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 
