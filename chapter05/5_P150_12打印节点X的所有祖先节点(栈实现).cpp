#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

// 非递归 后序遍历 算法 

// 树结构体
typedef struct treenode{
	char value;
	struct treenode *lchild, *rchild;
	// 节点的左右孩子访问变量 
	// tag = 0：左孩子已经访问过，tag = 1：右孩子访问过 
	int tag;
}treenode, *tree;

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
		t->value = ch;
		// 将 左、右孩子 置为 空
		t->lchild = NULL;
		t->rchild = NULL;
		
		// 递归给 左右孩子赋值
		buildtree(t->lchild);
		buildtree(t->rchild); 
	}
}

// 节点栈 的结构体 
typedef struct{
	// 树的节点
	treenode* data[Max];
	int top;
}Stack;

void InitStack(Stack &s){
	s.top = -1;
}

bool isEmpty(Stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

bool isFull(Stack s){
	if(s.top == Max -1){
		return true;
	}
	return false;
}

void Push(Stack &s, treenode* x){
	if(isFull(s)){
		printf("栈满！！！");
		return;
	}
	s.data[++s.top] = x;
}

void Pop(Stack &s){
	if(isEmpty(s)){
		printf("栈空！！！");
		return;
	}
	s.top--;
}

// 非递归后序遍历
void grand(tree t, char x){
	// 栈 栈的栈顶指针top的初始化指向 0
	Stack s;
	InitStack(s);
	treenode* p = t;

	// 当前结点不为空 或者 栈非空 
	while(p != NULL || !isEmpty(s)){
		while(p != NULL && p->value != x){
			// 从根节点出发向左延申压入栈中 并且节点的值不为 x 
			Push(s, p);
			// 表示 栈顶结点 的左孩子 已访问 
			s.data[s.top]->tag = 0;
			p = p->lchild;
		}
		
		// 如果找到 值为 x 的节点，将栈中节点输出
		if(p != NULL && p->value == x){
			printf("所有的祖先结点为：\n");
			for(int i = 0; i <= s.top; i++){
				printf("%c	", s.data[i]->value);
			}
		}
		
		// 判断当前栈顶的结点的 tag值，
		// tag == 1：表示 栈顶结点 的左右孩子均被访问，依次退栈
		// top != 0 ：表示栈不为空 
		while(!isEmpty(s) && s.data[s.top]->tag == 1){
			// 出栈，出栈结点不需要带回 
			Pop(s);
		}
		
		// 当前栈顶不为 0（即非空），
		if(!isEmpty(s)){
			// 将栈顶的tag赋值为 1
			s.data[s.top]->tag = 1;
			// 结点指向该结点的右孩子
			p = s.data[s.top]->rchild;  	
		}
	}
} 

void disp(tree t){
	if(t){
		disp(t->lchild);
		disp(t->rchild);
		printf("%c	", t->value);
	}	
}

int main(){
	
	tree t;
	// 先序序列：FECA#B##D###HGJ##K##IL##M## 
	buildtree(t);
	disp(t);
	printf("\n");
	grand(t, 'B');
	
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	
	return 0;
} 
