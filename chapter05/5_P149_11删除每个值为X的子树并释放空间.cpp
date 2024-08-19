#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild,*rchild;
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

// 递归 删除结点 
void Release(tree &t){
	if(t){
		Release(t->lchild);
		Release(t->rchild);
		free(t); // free：表示该空间不使用 
	}
}

// 先序遍历 
void delete_x(tree &t, char x){
	if(t == NULL){
		return;
	}
	if(t->data == x){
		// 递归释放结点 
		Release(t);
		// 手动设置节点为 NULL，物理内存的一个释放 
		t = NULL; 
	}
	
	if(t != NULL){
		// 递归调用 去左、右子树删除 值为X 的节点 
		delete_x(t->lchild, x);
		delete_x(t->rchild, x);
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
	// 前序序列：ABD##E##CF##G##
	// 先序序列：FECA#B##D###HGJ##K##IL##M## 
	buildtree(t);
	disp(t);
	printf("\n");
	delete_x(t, 'H');
	
	disp(t);
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	return 0;
}
