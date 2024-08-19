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
	} else{
		t = (treenode *) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

int num(tree t){
	if(t == NULL){
		return 0;
	} 
	else if(t->lchild != NULL && t->rchild != NULL){
		//  + 1：表示当前结点 是 双分支节点（有左右子树） 
		return num(t->lchild) + num(t->rchild) + 1;
	}
	else{
		return num(t->lchild) + num(t->rchild);
	}
}

void disp(tree t){
	if(t != NULL){
		printf("%c	", t->data);
		
		disp(t->lchild);
		disp(t->rchild);
	}
}


int main(){
	
	tree t;
	// 前序序列：ABD##E##CF##G##
	// ABD##E##C#G##
	// FECA#B##D###HG##I## 
	buildtree(t); 
	disp(t);
	printf("\n");
	
	printf("二叉树有左右孩子树：%d	", num(t));
	
	return 0;
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
}
