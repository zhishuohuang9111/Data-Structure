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
		t = (treenode*) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild); 
		buildtree(t->rchild);

	}
}

// 初始化前驱 
int pre = -3555;

int isok(tree t){
	// 判断树 是否为空    空树 也是 二叉排序树 
	if(t == NULL){
		return 1;
	}
	
	else{
		// 递归求左子树 是否是 二叉排序树
		int b1 = isok(t->lchild);
		// 判断左子树的值 和 当前结点 与 前驱结点值 的比较
		// 左子树 不是 二叉排序树  或者   当前结点 < 前驱结点值
		if(b1 == 0 || ((t->data) - '0') <= pre){
			// 左子树不是二叉排序树，直接返回 
			return 0;
		} 
		// 更新前驱结点
		pre = (t->data) - '0'; 
		// 递归求右子树之前，左子树必须是二叉排序树 
		// 递归求右子树 是否是 二叉排序树
		return isok(t->rchild);
	}
} 

int main(){
	
	tree t;
	// FECA#B##D###HG##I##
	/*
						F
					E		 H
				C         G    I
			  A    D 
			    B 
	*/
	buildtree(t);
	
	int ok = isok(t);
	
	if(ok){
		printf("yes");
	}
	else{
		printf("no");
	}
	
	return 0;
}
