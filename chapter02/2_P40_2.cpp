#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

// lnode*：表示结点 linklist：表示链表 

int a[8] = {1, 2, 5, 4, 5, 3, 5, 3};
int n = 8; 

void buildList(linklist &L){
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

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

void delete_X(linklist &L, int x){
	lnode *pre = L;
	lnode *p = L->next;
	lnode *q;
	
	while(p){
		if(p->data == x){
			// q 指向 待删除结点 
			q = p;
			
			p = p->next;
			pre->next = p;
			
			free(q);
		}
		else{
			p = p->next;
			pre = pre->next;
		}
	} 
}

int main(){
	
	linklist L;
	
	buildList(L);
	
	disp(L);
	
	delete_X(L, 5);
	
	disp(L);
	
	return 0;
}
