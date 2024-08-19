#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

int pos = 5;

void build(char a[], char b[], int s, int e, tree &t){
	if(s <= e){
		t = (treenode *)malloc(sizeof(treenode));
		t->data = a[pos];
		int i;
		for(i = s; i <= e; i++){
			// 注意：每一次递归调用，在 b数组中找到“当前”根节点 
			// i 停留的位置，就是根节点的位置 
			if(b[i] == t->data){
				break;
			}
		}
		pos--;
		/*
			从后往前：先根，右子树，左子树 
		*/ 
		// 构造右子树，只需要在右子树的区间里面去找 
		build(a, b, i+1, e, t->rchild);
		// 构造左子树，只需要在左子树的区间里面去找 
		build(a, b, s, i-1, t->lchild);
	}
	else{
		t = NULL;
	}
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
	// 后序序列 
	// DEBFCA
	char a[] = {'D', 'E', 'B', 'F', 'C', 'A'}; 
	// 中序序列 
	char b[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	
	build(a, b, 0, 5, t);
	
	printf("先序序列：");
	disp(t); 
	
	return 0;
}

