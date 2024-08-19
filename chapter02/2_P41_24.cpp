#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[6] = {1, -4, 2, 3, 4, -2};

int n = 6;

void buildlist(linklist &L){
	// 建立 头节点 
	L = (linklist) malloc(sizeof(lnode));
	
	lnode *s,*r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next; 
	}
	r->next = NULL;
} 

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

void delete_same(linklist &L, int n){
	lnode *p = L;
	int *q;
	// 分配 n + 1 个数组空间 
	q = (int *)malloc(sizeof(int) * (n + 1));
	// 数组 初始化 
	for(int i = 0; i < n + 1; i++){
		*(q + i) = 0;
	} 
	
	int s;
	lnode *f;
	
	while(p->next != NULL){
		s = p->next->data > 0 ? p->next->data : -p->next->data;
		if(*(q + s) == 0){
			*(q + s) = 1;
			p = p->next;
		}
		else{
			// f指针 暂时保存 待删除的结点 
			f = p->next;
			p->next = f->next;
			free(f);
		}
	}
	// 释放 辅助数组空间 
	free(q);
}

int main(){
	
	linklist L;
	buildlist(L);
	
	disp(L);
	
	delete_same(L, 4);
	
	disp(L);
	
	return 0;
}
