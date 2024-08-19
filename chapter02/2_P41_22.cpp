#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int n = 9;

void buildlist(linklist &L){
	L = (linklist) malloc(sizeof(lnode));
	lnode *s, *r = L;
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

int find_k(linklist L, int k){
	lnode *p = L->next;
	lnode *q = L->next;
	int count = 0;
	while(q != NULL){
		if(count < k){
			count++;
		}
		else{
			p = p->next;
		}
		
		q = q->next;
	}
	
	if(count < k){
		printf("不满足条件");
		return 0;
	}
	else{
		printf("倒数第 %d 的元素的值：%d",k, p->data);
		return 1;
	}
}

int main(){
	
	linklist L;
	
	buildlist(L);
	
	find_k(L, 10);
	
	return 0;
} 
