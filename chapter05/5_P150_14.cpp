
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

typedef struct{
	tree data[10];
	int level[10];
	int f, r;
}Qu;

buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *) malloc(sizeof(treenode));
		// 赋值 
		t->data = ch;
		// 左右孩子先置空 
		t->lchild = NULL;
		t->rchild = NULL;
		
		// 左右孩子递归赋值 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 层次遍历 
int width(tree t){
	// 队列 
	Qu Q;
	// 出队节点的指向 
	treenode* p; 
	// 保存出队节点的层次 
	int k;
	// 头尾指针初始化 
	Q.f = -1;
	Q.r = -1;
	// 尾指针后移，根节点入队 
	Q.r++;
	Q.data[Q.r] = t;
	// 根节点层次为 1 
	Q.level[Q.r] = 1;
	
	while(Q.f < Q.r){
		// 头指针后移出队 
		Q.f++;
		// 保存出队节点
		p = Q.data[Q.f];
		// 保存出队节点层次 
		k = Q.level[Q.f]; 
		
		// 左孩子非空，左孩子进队
		if(p->lchild != NULL){
			// 尾指针后移 用来入队 
			Q.r++;
			// 左孩子进入队列 
			Q.data[Q.r] = p->lchild;
			// 进入队列的节点的层次 = 出队节点的层次 + 1 
			Q.level[Q.r] = k + 1;
		}
		// 右孩子非空，右孩子进队 
		if(p->rchild != NULL){
			Q.r++;
			Q.data[Q.r] = p->rchild;
			// 进入队列的节点的层次 = 出队节点的层次 + 1 
			Q.level[Q.r] = k + 1; 
		}
	}
	
	int max = 0, i = 0, n;
	// 从 第一层 开始 
	k = 1;
	while(i <= Q.r){
		// 一开始默认每层默认0个
		n = 0;
		while(i <= Q.r && Q.level[i] == k){
			// 每层个数递增
			n++;
			// 遍历的下标后移
			i++; 
		} 
		// 下一层的层次 
		k = Q.level[i];
		
		if(n > max){
			max = n;
		}
	}
	
	return max;
	
}

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	int w = width(t); 
	printf("%d	", w);
	/*
				A
			B		C
		  D   E   F    G
	*/ 
	
	return 0;
}
