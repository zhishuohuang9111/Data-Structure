#include<stdio.h>
#include <stdlib.h>
using namespace std;

// 前、中、后序非递归算法

// 树结构体
typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// 节点栈 的结构体 
typedef struct{
	// 树的节点
	treenode *t;
	// 节点的左右孩子访问变量 
	// tag = 0：左孩子已经访问过，tag = 1：右孩子访问过 
	int tag;
}Stack;

void buildtree(tree &t){
	// 先序序列 建树 
	char ch;
	// getchar：获取输入的字符，每次获取一个 
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	} 
	else{
		// 分配内存空间给结点
		t = (treenode *) malloc(sizeof(treenode));
		// 给结点赋值 
		t->data = ch;
		// 将 左、右孩子 置为 空
		t->lchild = NULL;
		t->rchild = NULL;
		
		// 递归给 左右孩子赋值
		buildtree(t->lchild);
		buildtree(t->rchild); 
	}
}

void visit(char c){
	printf("%c	", c); 
}

// 非递归先序遍历 
void PreOrder(tree t){
	// 栈的栈顶指针top的初始化值 置为 -1 
	Stack s[10]; 
	int top = -1;
	treenode* p = t;
	// 当前结点 不为NULL 且 栈非空 
	while(p != NULL || top != -1){
		while(p != NULL){
			// 访问根结点 
			visit(p->data);
			// 压入栈中 
			s[++top].t = p;
			// 遍历左子树 
			p = p->lchild;
		}
		// 栈非空 
		if(top != -1){
			// 栈顶元素（即“当前根结点”）出栈 
			p = s[top].t;
			top--;
			// 访问右子树 
			p = p->rchild;
		}
	}
}

// 非递归中序遍历 
void InOrder(tree t){
	// 栈的栈顶指针top的初始化值 置为 -1 
	Stack s[10]; 
	int top = -1;
	treenode* p = t;
	// 当前结点 不为NULL 且 栈非空 
	while(p != NULL || top != -1){
		while(p != NULL){
			// 压入栈中 
			s[++top].t = p;
			// 遍历左子树 
			p = p->lchild;
		}
		// 栈非空 
		if(top != -1){
			// 栈顶元素（即“当前根结点”）出栈 
			p = s[top].t;
			top--;
			// 访问根结点 
			visit(p->data);
			// 访问右子树 
			p = p->rchild;
		}
	}
}

// 非递归后序遍历
void PostOrder(tree t){
	treenode* p = t;
	// 栈 栈的栈顶指针top的初始化值 置为 -1 
	Stack s[10]; 
	int top = -1;
	
	// 当前结点不为空 或者 栈非空 
	while(p != NULL || top != -1){
		while(p != NULL){
			// 从根节点出发向左延申压入栈中 并且节点的值不为 x 
			s[++top].t = p;
			// 表示 栈顶结点 的左孩子 已访问  
			s[top].tag = 0; 
			p = p->lchild;
		} // while循环结束，p 指向 NULL 
		
		// 判断当前栈顶的结点的 tag值，
		// tag == 1：表示 栈顶结点 的左右孩子均被访问，依次退栈
		// top != -1 ：表示栈不为空 
		while(top != -1 && s[top].tag == 1){
			// 栈顶结点 的左右孩子均被访问：输出栈顶元素
			visit(s[top].t->data); 
			top--;
		}
		
		// 当前栈顶不为 -1（即非空），
		if(top != -1){
			// 将栈顶的tag赋值为 1
			s[top].tag = 1;
			// 结点 指向 栈顶结点的右孩子  
			p = s[top].t->rchild;
		}
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
	tree t;
	// 前序序列：ABD##E##CF##G##
	buildtree(t);
	disp(t); // 前序 
	printf("\n");
	printf("前序遍历：");
	PreOrder(t);
	printf("\n");
	printf("中序遍历：");
	InOrder(t);
	printf("\n");
	printf("后序遍历：");
	PostOrder(t);

	return 0;
} 
