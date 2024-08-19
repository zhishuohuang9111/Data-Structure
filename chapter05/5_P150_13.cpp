#include<stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

// 树结构体

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree; 

typedef struct{
	// 树的节点
	treenode *t;
	//  左右孩子访问变量 tag = 0，左孩子访问过，tag = 1，右孩子访问过
	int tag; 
}Stack;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		// 给节点分配空间 
		t = (treenode *)malloc(sizeof(treenode));
		// 对节点赋值 
		t->data = ch;
		// 左右孩子置空 
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归赋值左右孩子 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

tree Ancestor(tree t, treenode *p, treenode *q){
	// 两个辅助栈
	Stack S1[10], S2[10]; // 结构体数组
	// 栈顶指针初始化
	int top1 = 0,top2;
	// 遍历二叉树的指针
	treenode *tt = t;
	// 大循环体条件：当前遍历的节点不能为空 或者 栈1的栈顶指针 > 0(栈不为空)
	while(tt != NULL || top1 >0){
		
		// 向左延申压入栈
		while(tt != NULL){
			S1[++top1].t = tt; // 压入栈中 
			S1[top1].tag = 0;  //表示左孩子访问过 
			tt = tt->lchild;   // 继续指向左孩子 
		}
		
		while(top1 != 0 && S1[top1].tag == 1){  // 栈1不为空 并且tag = 1
		
			// 如果栈顶的节点就是p，就复制到栈2中，栈2的栈顶指针 此时赋值 top1的值
			if(S1[top1].t == p){
				for(int i =1; i < top1; i++){
					S2[i] = S1[i];
				}
				top2 = top1;
			}
			// 如果栈顶的节点就是q 与栈1 进行匹配 
			if(S1[top1].t == q){
				for(int i = top1 - 1; i > 0; i--){
					for(int j = top2; j > 0; j--){
						// 匹配，直接返回 
						if(S2[j].t == S1[i].t){
							return S1[i].t;
						}
					}
				}
			}
			
			top1--; // 退栈
		}
		
		// 栈不空时，将栈顶的tag = 1，并且当前的节点指向该节点的右孩子 
		if(top1 != 0){
			S1[top1].tag = 1;
			tt = S1[top1].t->rchild;
		}
	}
	
	return NULL; // 没有公共祖先，返回NULL 
	
} 

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HGJ##K##IL##M##
	buildtree(t);
	// 自定义 p q节点的指向 
	treenode *p = t->rchild->lchild, *q = t->rchild->rchild; 
	tree ancestor = Ancestor(t, p, q);
	printf("%c	", ancestor->data);
	
		/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/ 
	
	return 0;
}





