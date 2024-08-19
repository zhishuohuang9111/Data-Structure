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

int Count(tree t){
	if(t == NULL){
		return 0;
	}
	int countl = Count(t->lchild);
	int countr = Count(t->rchild);
	// 左孩子结点个数 + 右孩子个数 + 当前根节点 
	return countl + countr + 1;
	
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
	// 前序序列：FECA#B##D###HG##I## 
	buildtree(t);
	printf("%d ", Count(t)); // 9 个 
	return 0;
		/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 
