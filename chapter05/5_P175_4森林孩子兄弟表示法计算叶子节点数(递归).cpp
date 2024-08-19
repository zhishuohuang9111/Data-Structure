#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

// 求 孩子兄弟表示法存储森林的 叶子结点数

/*
		若结点没有孩子，则它 必是叶子。 
		总的 叶子节点数 = 孩子子树上的叶子数 + 兄弟子树上的叶子结点数 
*/ 

typedef struct treenode{
	char data;
	struct treenode *child, *brother;
}treenode, *tree; 

// 建树 需要加引用 &，因为结果需要带回 
void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		// 分配内存 
		t = (treenode *)malloc(sizeof(treenode));
		// 赋值 
		t->data = ch;
		// 初始化：左孩子、右兄弟 分别置空 
		t->child = NULL;
		t->brother = NULL;
		// 递归赋值 
		buildtree(t->child);
		buildtree(t->brother);
	}
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->child);
		disp(t->brother);
	}
}

int Leaves(tree t){
	// 树为 空 
	if(t == NULL){
		return 0;
	}
	// 无孩子结点，当前节点 在原森林中 是叶子节点 
	if(t->child == NULL){
		return 1 + Leaves(t->brother);
	}
	// 有孩子结点 
	else{
		return Leaves(t->child) + Leaves(t->brother);
	}
}

int count = 0;

void leaves(tree t){
	if(t){
		if(t->child == NULL){
			count++;
			leaves(t->brother);
		}
		else{
			leaves(t->child);
			leaves(t->brother);
		}
	}
}

int main(){
	
	tree t;
	// 先序序列 GHK#L##I#JMP##N#O#### 
	buildtree(t);
	disp(t);
	printf("\n");
	leaves(t);
	printf("叶子结点数：%d\n", Leaves(t));
	printf("叶子结点数：%d", count);
	
	return 0;
	/*
	王道书 P175 
					G
				H
			K	  I
			  L     J
			      M
			    P   N
			          O
					
					
					G
			  H     I	   J
			K   L       M  N  O
			            P
	*/
}
