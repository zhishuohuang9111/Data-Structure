#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

/*
		1、为什么要线索化二叉树？
		对于经常需要遍历或查找结点 在遍历所得线性序列中的 前驱和后继信息，
		线索化二叉树查找效率高，不需要设栈。
		
		2、如何查找前驱和后继信息？ 
		当二叉树以二叉链表作为存储结构时，只能找到结点的左、右孩子信息，
		而不能直接得到结点在一序列中的前驱和后继信息，前序和后继信息只有在遍历的动态过程中才能得到。 
*/ 



typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
	// ltag = 0：lchild指针指向结点的左孩子  ltag = 1：lchild指针指向结点的前驱 
	// rtag = 0：rchild指针指向结点的右孩子  rtag = 1：rchild指针指向结点的后继 
	int ltag, rtag;
}treenode, *tree; 

void buildtree(tree &t);
void InOrderThreading(tree &thrt, tree t);
void InThreading(tree p);
void InOrderTraverse(tree thrt); 
void InOrderTraverseReverse(tree thrt);

// 先序序列建立二叉树 
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
		t->ltag = 0;
		t->rtag = 0;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}


treenode* pre; 

// 中序线索化 
void InOrderThreading(tree &thrt, tree t){
	// 建头结点 (为头节点指针分配存储空间)
	thrt = (treenode*) malloc(sizeof(treenode));
	thrt->ltag = 0;
	thrt->rtag = 1;
	// 右指针 回指 
	thrt->rchild = thrt;
	if(t == NULL){
		// 二叉树t 为空，头节点的左指针 回指 
		thrt->lchild = thrt;
	} 
	else{
		thrt->lchild = t;
		pre = thrt;
		// 中序遍历 进行 中序线索化 
		InThreading(t);
		// 最后一个结点 线索化
		pre->rchild = thrt;
		pre->rtag = 1;
		thrt->rchild = pre; 
	}
}

// 中序遍历 进行中序线索化
void InThreading(tree p){
	// 结点 非空 
	if(p){
		// 向左延申 找中序遍历的第一个结点 
		InThreading(p->lchild); // 左子树线索化 
		
		if(p->lchild == NULL){ // 当前结点 左孩子 为空 
			p->ltag = 1;
			// 将 左孩子指针 指向 中序遍历时的 前驱结点 
			p->lchild = pre;
		} 
		
		if(pre->rchild == NULL){ // 前驱结点 右孩子 为空 
			pre->rtag = 1;
			// 将 前驱结点的右孩子指针 指向 当前结点 
			pre->rchild = p;  
		}
		// 更新前驱结点 
		pre = p;
		
		InThreading(p->rchild); // 右子树线索化 
	}
} 


// p->rtag = 1：右指针是线索,其后继为 右孩子 
// p->rtag = 0：该结点有右孩子，则其后继为 右子树最左下结点
// 中序线索二叉树的遍历
void InOrderTraverse(tree thrt){
	// p 指向原二叉树的根结点 
	treenode* p = thrt->lchild;
	while(p != thrt){
		// 第一次 while 循环：找到 中序遍历的第一个结点 
		// 后面每一次 while 循环：找到 右子树最左下结点 
		while(p->ltag == 0){
			p = p->lchild;
		}
		// 访问第一个结点 
		printf("%c	", p->data);
		// 右标志为 1，可直接得到 后继结点 
		while(p->rtag == 1 && p->rchild != thrt){
			p = p->rchild;
			printf("%c	", p->data);
		}
		// while循环结束，p->rtag = 0;
		// 右标志为 0，则 后继为 右子树最左下角结点 
		// 右标志为 0，将 p指针 指向 p的右孩子  
		p = p->rchild;
	} 
} 

// p->ltag = 1：左指针是线索,其前序为 左孩子 
// p->ltag = 0：该结点有左孩子，则其前驱为 左子树最右下结点
// 逆序遍历中序线索二叉树 
void InOrderTraverseReverse(tree thrt){
	treenode* p = thrt->lchild;
	while(p != thrt){
		// 第一次 while 循环：查找中序遍历的最后一个结点 
		// 后面每一次 while 循环：找到左子树最右下结点 
		while(p->rtag == 0){
			p = p->rchild;
		}
		// 访问最后一个结点 
		printf("%c	", p->data);
		while(p->ltag == 1 && p->lchild != thrt){
			p = p->lchild;
			printf("%c	", p->data);
		}
		p = p->lchild;
	}
	printf("\n");
}

int main(){
	
	tree t;
	tree thrt;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	// 中序线索化 
	InOrderThreading(thrt, t);
	
	// 中序线索二叉树的遍历：A B C D E F G H I  
	InOrderTraverse(thrt); 
	printf("\n"); 
	// 逆序遍历中序线索二叉树：I H G F E D C B A 
	InOrderTraverseReverse(thrt);
	/*
				F
			E		H
		 C        G    I
	  A    D
	    B
	*/
	return 0;
}
