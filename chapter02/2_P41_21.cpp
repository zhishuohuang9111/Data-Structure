#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// 有 问题 

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9};

int n = 15;

void buildlist(lnode *L){
	lnode *s, *r = L;
	
	r->data = a[0];
	
	for(int i = 1; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next;
	}
	// 尾结点的指针域置为 NULL，防止有乱指向 
	r->next = NULL;
}

void disp(lnode *L){
	lnode *s = L;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

// 返回结点：环的入口 
lnode* findnode(lnode *L){
	// f：快指针   s：慢指针 
	lnode *f = L, *s = L;
	printf("%d	test", s->data);
	while(s != NULL && f->next != NULL){
		
		// s指针走一步  f指针走两步 
		s = s->next;
		f = f->next->next; 
		if(s->data == f->data){
			printf("相遇了");
			break;
		}
		// 快指针 或者 慢指针 为 NULL，说明没有环 
		if(s == NULL || f == NULL){
			return NULL;
		}
		
		lnode *p = L, *q = s;
		while(p->data != q->data){
			p = p->next;
			q = q->next;
		} 
		return p;
	} 
}

int main(){
	
	lnode list;
	lnode *L = &list;
	
	buildlist(L);
	
	disp(L);
	lnode *ans = findnode(L);
	printf("环口值为：%d", ans->data);
	
	return 0;
}
