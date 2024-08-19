#include<stdio.h>
#include <stdlib.h>
using namespace std;

// 后序非递归算法 

typedef struct TreeNode{
	char data;
	// 标志域：表示左右孩子是否被访问过 
	int tag; 
	struct TreeNode *lchild, *rchild;
}TreeNode, *Tree;

// 通过 先序序列 来构造 二叉树 
void buildTree(Tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (TreeNode *) malloc(sizeof(TreeNode));
		t->data = ch;
		// 初始时，标志域置为 0 
		t->tag = 0;
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归去赋值该节点的左右孩子 
		buildTree(t->lchild);
		buildTree(t->rchild);

	}
}

void PostOrder(Tree t){
	struct TreeNode *stack[100];
	int top = -1;
	TreeNode *p = t;
	// 用来保存出栈结点 
	TreeNode *q;
	
	// p 结点不为空 或者 栈非空 
	while(p != NULL || top != -1){
		if(p != NULL){
			top++;
			stack[top] = p;
			p = p->lchild;
		} 
		// p为空 
		else{
			// 将 p 指向栈顶元素 
			p = stack[top];
			
			// p(栈顶元素) 右孩子非空，并且右孩子没有被访问过 
			if(p->rchild != NULL && p->rchild->tag == 0){
				p = p->rchild;
			}
			// p(栈顶元素) 右孩子非空，但 右孩子被访问过 
			else{
				// 出栈，输出栈顶元素 
				p = stack[top];
				top--;
				printf("%c	", p->data);
				// p 当前指向的结点的 tag值 赋为 1 
				p->tag = 1;
				// p 指向空 
				p = NULL;
			}
		}
	} 
}

void disp(Tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	
}

int main(){
	
	Tree t;
	// 前序序列：ABD##E##CF##G##
	buildTree(t);
	
	disp(t);
	
	printf("\n");

	PostOrder(t);
	
	return 0;
	
	return 0;
}



