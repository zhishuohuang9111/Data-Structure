#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// pos:position(注意：全局变量) 
int pos = 0;
// s:start(开始区间) e:end(结束区间) 
void build(char a[], char b[], int s, int e, tree &t){
	if(s <= e){
		t = (treenode *)malloc(sizeof(treenode));
		t->data = a[pos];
		int i;
		for(i = s; i <= e; i++){
			// 注意：每一次递归调用，在 b数组(中序序列) 中找到 "当前" 根节点 
			// i 停留的位置，就是根节点的位置 
			if(b[i] == t->data){
				break;
			}
		}
		pos++;
		// 构造左子树，只需要在左子树的区间里面去找 
		build(a, b, s, i-1, t->lchild);
		// 构造右子树，只需要在右子树的区间里面去找 
		build(a, b, i+1, e, t->rchild);
	}
	else{
		t = NULL;
	}
	
}

void disp(tree t){
	if(t){
		disp(t->lchild);
		disp(t->rchild);
		printf("%c	", t->data);
	}
} 

int main(){
	tree t;
	// 先序序列 
	char a[] = {'A', 'B', 'D', 'E', 'C', 'F'}; 
	// 中序序列 
	char b[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	
	build(a, b, 0, 5, t);
	
	printf("后序序列：");
	disp(t); 
	
	return 0;
}






