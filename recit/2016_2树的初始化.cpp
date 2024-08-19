#include<stdio.h>
#include <stdlib.h>
using namespace std;

// 树结构体
typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	// 先序序列 建树 
	char ch;
	// getchar：获取输入的字符，每次获取一个 
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	} 
	else{
		// 分配内存空间给结点
		t = (treenode *) malloc(sizeof(treenode));
		// 给结点赋值 
		t->data = ch;
		// 将 左、右孩子 置为 空
		t->lchild = NULL;
		t->rchild = NULL;
		
		// 递归给 左右孩子赋值
		buildtree(t->lchild);
		buildtree(t->rchild); 
	}
}

// 先序 
void PreOrder(tree t){
	if(t){
		printf("%c	", t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

// 中序 
void InOrder(tree t){
	if(t){
		InOrder(t->lchild);
		printf("%c	", t->data);
		InOrder(t->rchild); 
	}
}

// 后序 
void PostOrder(tree t){
	if(t){
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		printf("%c	", t->data);
	}
}

void Release(tree &t){
	if(t){
		Release(t->lchild);
		Release(t->rchild);
		// free：表示该空间不使用 
		free(t); 
		// 设置节点为 NULL，物理内存的一个释放 
		t = NULL;
	}
}

int main(){
	tree t;
	// 前序序列：FECA#B##D###HG##I## 
	buildtree(t);
	
	Release(t);
	
	return 0;
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 
