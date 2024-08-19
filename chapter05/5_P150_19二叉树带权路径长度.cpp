#include<stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;


typedef struct treenode{
	int weight;
	struct treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch =='#'){
		t = NULL;
	}
	else{
		// 分配空间
		t = (treenode *) malloc(sizeof(treenode));
		// 赋值
		t->weight = ch;
		// 初始化
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归赋值 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

int wplpre(tree t, int deep){
	// 静态变量，存储结果并函数末尾返回 
	static int wpl = 0;
	if(t == NULL){
		return wpl;
	}
	// 叶子节点，计算权值 
	if(t->lchild == NULL && t->rchild == NULL){
		wpl += (deep * (t->weight - '0'));
	}
	// 递归遍历左、右子树，deep + 1 
	wplpre(t->lchild, deep+1);
	wplpre(t->rchild, deep+1);

	return wpl;
}

int main(){
	tree t;
	// 124##5##36##7## 
	buildtree(t);
	int wpl = wplpre(t, 0);
	printf("%d	", wpl);
	
	/*
				1
			2		3
		  4   5   6   7
	*/
	
	return 0;
} 



