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

treenode* find(tree t, char k){
	treenode *p = t;
	// 树不为空 才执行 if 语句 
	if(p != NULL){
		// 退出循环时，已找到 待查结点 
		while(p->data != k){
			// 当前结点值 > 待查值 
			if(p->data > k){
				p = p->lchild;
			}
			// 当前结点值 < 待查值 
			else{
				p = p->rchild;
			}
		}
	}
	return p;
	
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	// 查找结点 G 
	treenode *p = find(t, 'G');
	printf("%c	", p->data);
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
}
