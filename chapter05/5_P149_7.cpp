#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 15

typedef struct treenode{
	char data;
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
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

struct squeue{
	struct treenode* data[Max];
	int f,r;
	// 标志 
	int tag;
};

bool isEmpty(squeue s){
	if(s.f == s.r && s.tag == 0){
		// 队空 
		return true;
	}
	// 队非空 
	return false;
}

bool isFull(squeue s){
	if(s.f == s.r && s.tag == 1){
		// 队满 
		return true;
	}
	// 队未满 
	return false;
} 

bool enters(squeue &s, treenode *p){
	if(isFull(s)){
		// 队满 
		return false;
	}
	s.data[s.r] = p;
	// 尾指针后移 
	s.r = (s.r + 1) % Max;
	// 只有 入队 才可能使 队满 
	// 入队将 tag 值 置为 1 
	s.tag = 1;
	return true;
}

bool outs(squeue &s, treenode *p){
	if(s.f == s.r && s.tag == 0){
		return false;
	}
	// 用 p结点 保存 出队结点 
	p = s.data[s.f];
	s.f = (s.f + 1) % Max;
	// 只有 出队 才可能使 队空 
	s.tag = 0;
	
	return true;
}

bool isok(tree t){
	squeue s;
	s.f = s.r = 0;
	s.tag = 0;
	// flag 为 true 表示：之前遍历的结点 都有左右孩子  
	bool flag = true;
	// 结果变量 
	bool ans = true;

	// 空树 
	if(t == NULL){
		ans = true;
	}
	// 只有 根结点 
	if(t->lchild == NULL && t->rchild == NULL){
		ans = true;
	}
	// 根结点 入队 
	enters(s, t);
	// printf("%c	", s.data[s.f]->data);
	treenode *p;
	
	// 队列不为空时，while执行 
	while(isEmpty(s) == false){
		
		outs(s, p);
		
		if(!p->lchild){ // 缺 左孩子 
			flag = false;
			if(p->rchild){
				// 缺 左孩子， 有 右孩子：不是完全二叉树 
				ans = false;
			}
		}
		// 当前结点 有 左孩子 
		else{
			// flag == true：表示 之前不存在 缺孩子 结点 
			if(flag){
				enters(s, p->lchild); // 左孩子 进队 
				if(p->rchild){
					// 右孩子 进队 
					enters(s, p->rchild);
				}
				else{
					// 有左孩子，无右孩子 
					flag = false;
				} 
			} 
			// 之前存在 缺孩子的结点 
			else{
				ans = false; 
			} 
		} 
	}
	if(ans){
		return true;
	}
	else{
		return false;
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
	// ABD##E##CF##G##
	buildtree(t);
	
	disp(t);
	
	if(isok(t)){
		printf("yes!!!");
	}
	else{
		printf("no!!!");
	}
	
	return 0;
}
