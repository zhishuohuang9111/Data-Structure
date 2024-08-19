#include<stdio.h>
#include <stdlib.h>
using namespace std;

/*
		平衡二叉树：任意结点的左右子树 高度差的绝对值不超过 1 
		平衡因子：左子树 与 右子树 的高度差，平衡因子的值只能是 -1、0、1 
*/ 

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
		t = (treenode *) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 后序遍历 来判断是否是 平衡二叉树  
void isAVL(tree t,int &height, int &balance){
	// 左、右子树高度  
	int h1 = 0, h2 = 0;
	// 左、右子树平衡因子 
	int b1 = 0, b2 = 0;
	
	// 空树：高度为 0 平衡因子为 1
	if(t == NULL){
		height = 0;
		balance = 1;
	} 
	// 只有一个根节点：高度为 1 平衡因子为 1 
	else if(t->lchild == NULL && t->rchild == NULL){
		height = 1;
		balance = 1; 
	}
	else{
		// 递归调用左子树
		isAVL(t->lchild, h1, b1);
		// 递归调用右子树
		isAVL(t->rchild, h2, b2);
		// 当前结点的树高 = 左、右子树较大者 + 1 
		height = (h1 > h2 ? h1 :h2) + 1;
		
		// 左、右子树高度差的绝对值 小于等于 1 
		if(abs(h1 - h2) <= 1){
			// 左、右子树都是平衡二叉树时，是平衡二叉树 
			balance = b1 && b2;
		}
		else{
			balance = 0;
		}
	}
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	
	int height, balance;
	isAVL(t, height, balance);
	
	printf("height = %d, balance = %d", height, balance);
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
}

