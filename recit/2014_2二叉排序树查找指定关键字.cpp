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

// 非递归 
treenode* find_key(tree t, char key){
	treenode* p = t;
	while(p){
		if(p->data == key){
			return p;
		}
		else if(p->data > key){
			p = p->lchild;
		}
		else{
			p = p->rchild;
		}
	}
	// while 循环结束，说明没有找到 
	return NULL;
}

// 递归 
treenode* Find(tree t, char x){
	if(t == NULL){
		return NULL;
	}
	else{
		if(t->data == x){
			return t;
		}
		else if(t->data > x){
			Find(t->lchild, x);
		}
		else{
			Find(t->rchild, x);
		}
	}
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	InOrder(t);
	
	treenode* p = find_key(t, 'M');
	if(p){
		printf("%c	", p->data);
	}
	else{
		printf("没找到！");
	}
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	return 0;
}
