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
	++s.top;
	s.data[s.top] = x;
}

void Pop(Stack &s){
	if(isEmpty(s)){
		printf("栈空！！！");
		return;
	}
	s.top--;
}

// 后序非递归找公共祖先结点：假定后序序列中 X 在 Y 的前面 
treenode* Ancestor(tree t, char X, char Y){
	Stack s1, s2;
	InitStack(s1);
	InitStack(s2); 
	// 遍历二叉树的指针
	treenode *p = t;
	// 大循环体条件：当前遍历的节点不能为空 或者 栈1的栈顶指针 != -1(栈不为空)
	while(p != NULL || !isEmpty(s1)){
		// 向左延申压入栈
		while(p != NULL){
			Push(s1, p);
			s1.data[s1.top]->tag = 0;
			p = p->lchild;   // 继续指向左孩子 
		}
		// 栈1不为空 并且 tag = 1
		while(s1.top != -1 && s1.data[s1.top]->tag == 1){  
		
			// 如果栈顶的节点就是p，就复制到栈2中，栈2的栈顶指针 此时赋值 top1的值
			if(s1.data[s1.top]->value == X){
				for(int i = 0; i < s1.top; i++){
					s2.data[i] = s1.data[i];
				}
				s2.top = s1.top;
			}
			// 如果栈顶的节点就是q 与栈1 进行匹配 
			// 要求找最近公共祖先：从 栈顶往下进行匹配 
			if(s1.data[s1.top]->value == Y){
				for(int i = s1.top - 1; i > -1; i--){
					for(int j = s2.top; j > -1; j--){
						// 匹配成功，直接返回 
						if(s2.data[j]->value == s1.data[i]->value){
							return s1.data[i];
						}
					}
				}
			}
			// 退栈
			Pop(s1); 
		}
		
		// 栈不空时，将栈顶的tag = 1，并且当前的节点指向该节点的右孩子 
		if(!isEmpty(s1)){
			s1.data[s1.top]->tag = 1;
			p = s1.data[s1.top]->rchild;
		}
	}
	return NULL; // 没有公共祖先，返回NULL 
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

	tree ancestor = Ancestor(t, 'B', 'A');
	printf("%c	", ancestor->value);
	
	/*
				F
			E		 H
		 C        G     I
	  A    D    J   K  L M
	   B
	*/ 
	
	return 0;
} 
