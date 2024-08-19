#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[6] = {2, 3, 6, 7, 8, 9};
int b[4] = {4, 5, 1, 10};

int n = 6;
int m = 4; 

void build(linklist &L,int a[], int n){
	// 创建 头节点
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L;
	lnode *s;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next; 
	}
	r->next = L;
}

void disp(linklist L){
	lnode *p = L->next;
	while(p != L){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n");
}

void link(linklist &L1, linklist &L2){
	lnode *p = L1->next;
	lnode *q = L2->next;
	while(p->next != L1){
		p = p->next;
	}
	p->next = q;
	
	while(q->next != L2){
		q = q->next;
	}
	q->next = L1;
	// 释放 L2 头节点 
	free(L2);
}

int main(){
	
	linklist L1;
	linklist L2;
	
	build(L1, a, n);
	build(L2, b, m);
	disp(L1);
	disp(L2);

	link(L1, L2);
	disp(L1);
	 
	
	return 0;
}
