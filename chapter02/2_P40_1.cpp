#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
		不带头节点
		递归算法 
*/


typedef struct lnode{
	int data;
	struct lnode *next;
}lnode;

int a[4] = {1, 2, 3, 4};

int n = 4;

// 引用 & 不带为什么也行 ：不带头节点，用指针来实现 
void buildlist(lnode *&L){
	lnode *s, *r = L;
	r->data = a[0];
	
	if(n == 1){
		r->next = NULL;
	}
	else{
		for(int i = 1; i < n; i++){
			s = (lnode *)malloc(sizeof(lnode));
			s->data = a[i];
			
			r->next = s;
			r = r->next;
		}
	}
	
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

void delete_x(lnode *&L, int x){
	if(L == NULL){
		return;
	}
	
	lnode *p;
	
	if(L->data == x){
		p = L;
		L = L->next;
		free(p);
		delete_x(L, x);
	}
	else{
		delete_x(L->next, x);
	}
}

int main(){
	
	lnode list;
	lnode *L = &list;
	
	buildlist(L);
	
	disp(L);
	
	delete_x(L, 2);
	
	disp(L);
	
	return 0;
}



