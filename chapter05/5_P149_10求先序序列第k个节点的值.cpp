#include<stdio.h>
#include <stdlib.h>

typedef struct treenode{
	char data;
	struct treenode *lchild,*rchild;
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

// 计数器 全局变量 
int i = 1;
// 获取结果字符 全局变量 
char ch; 

char PreOrder(tree t, int k){
	if(t == NULL){
		// 没有找到，返回一个特殊字符 
		return '#';
	}
	if(i == k){
		return t->data;
	}
	// 计数器递增 
	i++;
	// 对左子树递归遍历 
	ch = PreOrder(t->lchild, k);
	
	if(ch != '#'){
		// 在 左子树 已经找到 第 k 个结点 
		return ch;
	}
	// 对右子树递归遍历 
	ch = PreOrder(t->rchild, k);
	
	// 可能二叉树总节点个树 < k：没有找到 
	return ch;
	
} 

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	printf("%c	", PreOrder(t, 5));
	
	return 0;
}
