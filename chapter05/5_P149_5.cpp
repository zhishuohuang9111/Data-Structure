#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

// 非递归计算二叉树的高度

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
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
} 

int dept(tree t){
	// 树为空 高度为0 
	if(!t){
		return 0;
	}
	// 队列：树结点类型 数组 
	treenode *q[10]; 
	// tree q[10];
	int f = -1, r = -1;
	int Latest = 0, depth = 0;
	
	q[++r] = t;
	// 指针 p 指向出队结点 
	treenode *p; 
	// tree p;
	// 队列非空 
	while(f < r){
		p = q[++f];
		// 左右孩子不为空，分别入队 
		if(p->lchild){
			q[++r] = p->lchild;
		}
		if(p->rchild){
			q[++r] = p->rchild;
		}
		// f == L：表示遍历到当前层 的 最右 结点 
		if(f == Latest){
			// 高度 + 1 
			depth++;
			// L 指向下一层 的 最右 结点 
			Latest = r;
		}
	}
	return depth; 
}

int main(){
	
	tree t;
	buildtree(t);
	printf("树高：%d", dept(t));
	
	return 0;
} 





