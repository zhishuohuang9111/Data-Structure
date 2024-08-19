#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

// 孩子兄弟表示法，求树的深度

/*
		树空，返回 0.
		高度为 第一子女树高度 + 1  和 兄弟子树高度  的大者 
*/ 

typedef struct treenode{
	char data;
	struct treenode *child, *brother;
}treenode, *tree;
// treenode：表示结点  *tree：表示树

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->child = NULL;
		t->brother = NULL;
		
		buildtree(t->child);
		buildtree(t->brother);
	}
} 

int height(tree t){
	if(t == NULL){
		return 0;
	}
	else{
		// 计算左孩子高度 
		int l = height(t->child);
		// 计算右兄弟高度 
		int r = height(t->brother);
		
		return l + 1 > r ? l + 1 : r; 
	}
}

int main(){
	
	tree t;
	// 先序序列 GHK#L##I#JMP##N#O####  
	buildtree(t);
	printf("树高：%d", height(t));
	
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
