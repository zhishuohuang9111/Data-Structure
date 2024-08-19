#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[8] = {4, 5, 6, 4, 7, 3, 7, 8};
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

void delete_min(linklist &L){
	lnode *pre = L;
	lnode *p = L->next;
	
	lnode *min_pre = L;
	lnode *min_p = L->next;
	
	while(p){
		if(p->data < min_p->data){
			min_pre = pre;
			min_p = p;
		}
		pre = p;
		p = p->next;
	}
	
	min_pre->next = min_p->next;
	free(min_p); 
}

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

int main(){
	
	lnode list;
	lnode *L = &list;
	
	buildList(L);
	
	disp(L);
	
	delete_min(L);
	
	disp(L);
	
	return 0;
}
