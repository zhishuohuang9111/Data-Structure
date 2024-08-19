#include<stdio.h>
#include <stdlib.h>
using namespace std;

// 非递归 后序遍历 算法 

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

// 非递归后序遍历
void grand(tree t, char x){
	// 栈 栈的栈顶指针top的初始化指向 0
	Stack s[10];
	int top = 0;
	
	// 当前结点不为空 或者 栈非空 
	while(t != NULL || top > 0){
		while(t != NULL && t->data != x){
			// 从根节点出发向左延申压入栈中 并且节点的值不为 x 
			s[++top].t = t;
			
			// 表示 栈顶结点 的左孩子 已访问  
			s[top].tag = 0; 
			t = t->lchild;
		}
		
		// 如果找到 值为 x 的节点，将栈中节点输出
		if(t != NULL && t->data == x){
			printf("所有的祖先结点为：\n");
				for(int i = 1; i <= top; i++){
					printf("%c	", s[i].t->data);
			}
		}
		
		// 判断当前栈顶的结点的 tag值，
		// tag == 1：表示 栈顶结点 的左右孩子均被访问，依次退栈
		// top != 0 ：表示栈不为空 
		while(top != 0 && s[top].tag == 1){
			top--;
		}
		
		// 当前栈顶不为 0（即非空），
		if(top != 0){
			// 将栈顶的tag赋值为 1
			s[top].tag = 1;
			// 结点指向该结点的右孩子  
			t = s[top].t->rchild;
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
	
	buildtree(t);
	// 前序序列：ABD##E##CF##G##
	disp(t);
	printf("\n");
	grand(t, 'A');
	
	return 0;
} 
