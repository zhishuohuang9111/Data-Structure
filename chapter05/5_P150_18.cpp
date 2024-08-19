#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
	// tag = 0：有左右孩子  tag = 1：无左右孩子 
	int ltag, rtag;
}treenode, *tree; 

void buildtree(tree &t){
	char ch;
	// 输入 
	cin>>ch;
	
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

tree pre;

// 中序线索化
void InThread(tree &t){
	// 结点 非空 
	if(t){
		// 向左延申 找叶子结点
		InThread(t->lchild); // 左子树线索化 
		
		if(t->lchild == NULL){ // 左孩子 为空 
			t->ltag = 1;
			t->lchild = pre;
		} 
		else{ // 左孩子 不为空 
			t->ltag = 0;
		} 
		if(pre != NULL && pre->rchild == NULL){ // 前驱结点 不为空 且 无右孩子 
			pre->rtag = 1; // 前驱结点有后继 
			pre->rchild = t;  // 将 前驱的右孩子 指向 当前结点 
		}
		// 跟新前驱结点 
		pre = t;
		
		InThread(t->rchild); // 右子树线索化 
	}
} 

// 中序线索二叉树 在 后序遍历中 找 前驱 
tree Inpostpre(tree t, treenode *p){
	// 结果指针
	treenode *q;
	// 该节点有右孩子 结果就是 右孩子 
	if(p->rtag == 0){
		q = p->rchild;
	} 
	// 该节点无右孩子，有左孩子 结果就是 右孩子
	else if(p->ltag == 0){
		q = p->lchild; 
	}
	// 该节点的前驱为空 即为中序遍历的第一个结点，该结点在后序遍历中也是第一个结点 无后序前驱 
	else if(p->lchild == NULL){
		q = NULL;
	}
	// 其他（无左右孩子，但不是中序遍历的第一个结点） 
	else{
		// 不断沿着线索找祖先 
		while(p->ltag == 1 && p->lchild != NULL){
			p = p->lchild;
		}
		if(p->ltag == 0){
			q = p->lchild;
		}
		else{
			// 没有后序前驱 （仅有单支树） 
			q = NULL;
		}
	}
	// 返回 目标结点 的 前驱结点 
	return q; 
} 

int main(){
	
	tree t;
	// 先序序列：ABD##E##CF##G##
	// ABD##E##CF### (该序列不对)
	buildtree(t);
	// 线索化 
	InThread(t);
	// t, 根结点的右孩子 
	treenode *q = Inpostpre(t, t->rchild);
	if(q){
		printf("%c	", q->data); 
	}
	else{
		printf("无前驱");
	}
	
	/*
				A
			B		C
		  D   E   F    G
	*/
	 
	
	return 0;
}
