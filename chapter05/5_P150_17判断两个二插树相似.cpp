#include<stdio.h>
#include <stdlib.h>
#include<iostream> 

using namespace std;

typedef struct treenode{
	char data;
	treenode *lchild,*rchild;
}treenode, *tree;

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
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
} 

bool similar(tree t1, tree t2){
	// 两树 均为 空；相似 
	if(t1 == NULL && t2 == NULL){
		return true;
	}
	// 只有一树 为 空：不相似 
	else if(t1 == NULL || t2 == NULL){
		return false;
	}
	// 两树 均不为 空：递归调用 左右子树 
	else{
		// 对 两树的左子树 递归 
		bool leftS = similar(t1->lchild, t2->lchild);
		// 对 两树的右子树 递归 
		bool rightS = similar(t1->rchild, t2->rchild);
		
		// 只有 两树的左、右子树都相似，两树才相似 
		// 1 && 1 = 1; 1 && 0 = 0; 0 && 1 = 0; 0 && 0 = 0; 
		return leftS && rightS;
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
	
	tree t1, t2;
	buildtree(t1); // AB###
	buildtree(t2); // C#D## 
	
	disp(t1);
	printf("\n");
	disp(t2);
	if(similar(t1, t2)){
		printf("相似");
	}
	else{
		printf("不相似");
	}
	return 0;
}
