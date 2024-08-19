#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct BstNode{
	dataType data;
	struct BstNode *lchild;
	struct BstNode *rchild;
}BSTNode, *BSTtree;

// & 加引用 
void insertBST(BSTtree &bt, dataType key){
	if(bt == NULL){
		bt = (BSTtree) malloc(sizeof(BSTNode));
		bt->data = key;
		bt->lchild = NULL;
		bt->rchild = NULL;
	}
	else if(bt->data > key){
		insertBST(bt->lchild, key);
	}
	else if(bt->data < key){
		insertBST(bt->rchild, key);
	}
}

void create_BST(BSTtree &T, int a[], int n){
	T = NULL;
	for(int i = 0; i < n; i++){
		insertBST(T, a[i]);
	}
}

// 递归查找 
BSTNode* searchBST(BSTtree T, dataType key){
	if(T == NULL){
		return NULL;
	}
	else if(T->data == key){
		return T;
	}
	else if(T->data > key){
		return searchBST(T->lchild, key);
	}
	else{
		return searchBST(T->rchild, key);
	}
}

BSTNode* searchBST1(BSTtree T, dataType key){
	while(T != NULL && T->data != key){
		if(T->data > key){
			T = T->lchild;
		}
		else{
			T = T->rchild;
		}
	}
	return T;
}

void inOrder(BSTtree T){
	if(T != NULL){
		inOrder(T->lchild);
		printf("%d	", T->data);
		inOrder(T->rchild);
	}
}

// 引用传参 形参的改变 会影响 实际参数的改变
void deleteNode(BSTtree &bt){
	BSTNode *p;
	// 待删除节点 左、右子树 均为空 
	if(bt->lchild == NULL && bt->rchild == NULL){
		p = bt;
		bt = NULL;
		delete p;
	}
	// 待删除节点 左子树 为空 
	else if(bt->lchild == NULL){
		p = bt;
		bt = bt->rchild;
		delete p;
	}
	// 待删除节点 右子树 为空 
	else if(bt->rchild == NULL){
		p = bt;
		bt = bt->lchild;
		delete p;
	}
	// 待删除节点 左、右子树 均不为空 
	else{
		/*
		// 1 左子树 找 最大替换 
		BSTNode *parent = bt;
		// pre 指向 bt的左子树 
		BSTNode *pre = bt->lchild;
		// 左子树 找最大值 用来替换 
		while(pre->rchild != NULL){
			parent = pre;
			pre = pre->rchild;
		}
		// while 循环结束后，找到的 pre 一定只有左子树，无右子树 
		// 找到的左子树最大值 替换 待删除节点值 
		bt->data = pre->data;
		
		// parent == bt：表示 bt 的左子树的最大值 就是 bt的左孩子 
		if(parent == bt){
			parent->lchild = pre->lchild;
		}
		else{
			parent->rchild = pre->lchild;
		}
		delete pre; 
		*/
		
		// 2 右子树 找 最小替换 
		BSTNode *parent = bt;
		// pre 指向 bt的右子树 
		BSTNode *pre = bt->rchild;
		// 右子树 找最小值 用来替换 
		while(pre->lchild != NULL){
			parent = pre;
			pre = pre->lchild;
		}
		// while 循环结束后，找到的 pre 一定只有右子树，无左子树 
		// 找到的左子树最大值 替换 待删除节点值 
		bt->data = pre->data;
		
		// parent == bt：表示 bt 的左子树的最大值 就是 bt的左孩子 
		if(parent == bt){
			parent->rchild = pre->rchild;
		}
		else{
			parent->lchild = pre->rchild;
		}
		delete pre;
		//  
	}
} 

bool deleteBST(BSTtree &bt, dataType key){
	if(bt == NULL){
		return false;
	}
	else{
		if(bt->data == key){
			deleteNode(bt);
			return true;
		}
		else if(bt->data > key){
			return deleteBST(bt->lchild, key);
		}
		else{
			return deleteBST(bt->rchild, key);
		}
	} 
	
}


int main(){
	
	BSTtree T;
	
	int a[11] = {38, 12, 56, 6, 34, 40, 98, 3, 13, 78, 7};
	
	create_BST(T, a, 11);
	
	inOrder(T);
	
	printf("\n");
	
	bool flag = deleteBST(T, 38);
	if(flag == false){
		printf("删除失败！");
	}
	printf("\n");
	printf("T-data = %d	", T->data);
	
	inOrder(T);
	
	BSTNode* find = searchBST1(T, 70);
	
	if(find == NULL){
		printf("无该节点！");
	}
	else{
		printf("%d	", find->data);
	}
	
	return 0;
}
