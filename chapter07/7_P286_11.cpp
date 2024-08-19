#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	int count;
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
		t->count = 0;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 计算 每一个结点 所含结点数 （包括结点本身） 
int num(tree &t){
	if(t){
		if(t->lchild == NULL && t->rchild == NULL){
			// 将 当前结点的count 赋值 
			t->count = 1;
			return t->count;
		}
		else{
			// 递归调用 左子树 
			int b1 = num(t->lchild);
			// 递归调用 右子树 
			int b2 = num(t->rchild);
			// 将 当前结点的count 赋值 
			t->count = b1 + b2 + 1; 
			return t->count;
		}
	}
}

treenode *min_k(tree t, int k){
	// 输入的 K值 非法 
	if(k < 1 || k > t->count){
		return NULL;
	}
	// 左子树 为空 
	if(t->lchild == NULL){
		if(k == 1){
			return t;
		}
		else{
			min_k(t->rchild, k-1);
		}
	}
	// 左子树 不为空 
	else{
		// 左子树结点个数 = K-1，第 K 小结点就是根节点 
		if(t->lchild->count == k-1){
			return t;
		}
		// 左子树结点个数 > K-1，在左子树找 第 K 小 
		if(t->lchild->count > k-1){
			return min_k(t->lchild, k);
		}
		// 左子树结点个数 < K-1，在右子树找 第 (K - 左子树结点个数) 小 
		if(t->lchild->count < k-1){
			return min_k(t->rchild, k - (t->lchild->count + 1));
		}
	}
}

// 中序遍历 
void disp(tree t){
	if(t->lchild != NULL){
		disp(t->lchild);
	}
	
	printf("data = %c, count = %d	", t->data, t->count);
	
	if(t->rchild != NULL){
		disp(t->rchild);
	}
}


int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HG##I##
	buildtree(t);
	
	num(t);
	disp(t);
	
	treenode *p = min_k(t, 7);
	printf("%c	", p->data); 
	
	// printf("结点数：%d	", t->count);
	
	// printf("test");
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
} 
