#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

typedef struct treenode{
	char data;
	struct treenode *child, *brother; 
}treenode, *tree;

void create(tree &t, char e[], int degree[], int n){
	// 树结点类型 数组 
	tree* point = new tree[10];
	// tree *point = (tree*) malloc(sizeof(tree) * Max);
	for(int i = 0; i < n; i++){
		// 结点初始化 
		point[i] = (treenode *) malloc(sizeof(treenode));
		point[i]->data = e[i];
		point[i]->child = NULL;
		point[i]->brother = NULL;
	}
	
	// 孩子结点序号 
	int k = 0; 
	// 按照给的结点顺序访问结点
	for(int i = 0; i < n; i++){
		int d = degree[i];
		// 如果有度 说明有孩子
		if(d){
			// 将第一个孩子 作为自己的左孩子结点 
			k++;
			point[i]->child = point[k];
			// d 当前结点的度 
			// 剩余的孩子 每个结点依次为前一个结点的兄弟结点
			for(int j = 2; j <= d; j++){
				k++;
				point[k-1]->brother = point[k];
			} 
		} 
	}
	// 链表的头 为 第一个结点 
	t = point[0]; 
	// 动态申请的内存进行释放 防止内存泄露
	delete [] point; 
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->child);
		disp(t->brother);
	}
} 

int main(){
	
	tree t;
	// 层次遍历序列 
	char e[8] = "ABCDEFG";
	// 每个结点度的数组 
	int degree[8] = {3, 2, 1, 0, 0, 0}; 
	/*
					A
				B		C	D
			  E   F     G 
	*/
	create(t, e, degree, 7);
	
	disp(t);
	
	return 0;
}
