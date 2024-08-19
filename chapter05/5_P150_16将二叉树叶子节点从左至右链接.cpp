#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// 先序建树 
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

void disp(tree t){
	if(t){
		disp(t->lchild);
		printf("%c	", t->data);
		disp(t->rchild);
	}
} 

// 全局变量 
// 对 头节点 进行内存分配 
tree head = (treenode *) malloc(sizeof(treenode)); 
// 前驱结点  初始值 置空 
tree pre = NULL;

// 中序递归遍历 
tree InOrder(tree t){
	// "当前结点" 不为空  若为空，不做任何操作 
	if(t){
		// 递归遍历 左子树 
		InOrder(t->lchild);
		
		// 找到 叶子结点（左右孩子均为空） 
		if(t->lchild == NULL && t->rchild == NULL){
			// 如果是 第一个叶子结点 
			if(pre == NULL){
				head = t;
				pre = t;
			}
			// 不是 第一个叶子结点  
			else{
				// 将前驱结点的右指针 指向 当前叶子结点 
				pre->rchild = t;
				// 更新前驱结点 保证后面再次遇到叶子结点时，知道前驱 并能够链接起来 
				pre = t;
			}
		}
		
		// 递归遍历 右子树 
		InOrder(t->rchild);
		
		// 将 最后一个叶子结点 的右指针 置为空 
		pre->rchild = NULL; 
	}
} 

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	disp(t);
	printf("\n");
	
	InOrder(t);
	while(head){
		printf("%c	", head->data);
		head = head->rchild;
	}
	
	return 0;
}
