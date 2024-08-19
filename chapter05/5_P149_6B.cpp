#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

int pos = 5;

tree build(char a[], char b[], int s, int e){
	if(s <= e){
		treenode *root = (treenode *)malloc(sizeof(treenode));
		root->data = a[pos];
		int i;
		for(i = s; i <= e; i++){
			// 注意：每一次递归调用，在 b数组中找到“当前”根节点 
			// i 停留的位置，就是根节点的位置 
			if(b[i] == root->data){
				break;
			}
		}
		pos--;
		/*
			从后往前：先根，右子树，左子树 
		*/ 
		// 构造右子树，只需要在右子树的区间里面去找 
		root->rchild = build(a, b, i+1, e);
		// 构造左子树，只需要在左子树的区间里面去找 
		root->lchild = build(a, b, s, i-1);
		
		return root;
	}
	
	// 递归出口条件 （即 无左右孩子的根节点） 
	return NULL;
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}
} 

int main(){
	// 后序序列 
	// DEBFCA
	char a[] = {'D', 'E', 'B', 'F', 'C', 'A'}; 
	// 中序序列 
	char b[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	
	tree root = build(a, b, 0, 5);
	
	printf("先序序列：");
	disp(root); 
	
	
	 
	return 0;
}

