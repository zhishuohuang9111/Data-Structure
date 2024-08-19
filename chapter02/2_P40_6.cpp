#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist; 

int a[8] = {1, 5, 3, 7, 2, 6, 8, 4};
int n = 8; 

void buildlist(linklist &L){
	// 带 头节点 
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L, *s;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L){
	lnode *p = L->next;
	while(p){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n");
}

void sortlist(linklist &L){
	lnode *p = L->next, *r = p->next, *f;
	
	p->next = NULL;
	// p 指针 重新指向 原链表 
	p = r;
	while(p){
		r = p->next;
		f = L;
		// 找到 插入位置 
		while(f->next != NULL && f->next->data < p->data){
			f = f->next;
		}
		p->next = f->next;
		f->next = p;
		
		p = r; 
	}
}

int main(){
	
	linklist L;
	buildlist(L);
	
	disp(L);
	
	sortlist(L);
	
	disp(L);
	
	return 0;
}
