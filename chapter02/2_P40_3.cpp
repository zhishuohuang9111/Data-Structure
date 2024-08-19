#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int n = 8; 

void buildList(linklist &L){
	// L所指向的结点 为 头节点 
	L = (linklist)malloc(sizeof(lnode));
	
	lnode *s;
	lnode *r = L;
	for(int i = 0; i < n; i++){
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next; 
	}
	
	r->next = NULL;
}

void reverse_disp(linklist L){
	if(L->next != NULL){
		reverse_disp(L->next);
	}
	
	if(L != NULL){
		printf("%d	", L->data);
	}
}

void Ignore_Head(linklist L){
	if(L->next != NULL){
		reverse_disp(L->next);
	}
}

int main(){
	
	lnode list;
	lnode *L = &list;
	buildList(L);
	
	Ignore_Head(L);
	
	
	return 0;
}
