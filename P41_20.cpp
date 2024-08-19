#include<stdio.h>
#include <stdlib.h>

typedef struct lnode{
	int data, fre;
	lnode *prior,*next;
	
}lnode, *linklist;

int a[5] = {1, 2, 3, 4, 5};

int n = 5;

void buildList(linklist &L){
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L, *s;
	L->prior = NULL;
	L->next = NULL;
	
	/* 
	循环 双链表 
	L->prior = L;
	L->next = L;
	*/
	 
	
	for(int i = 0; i < n; i++){
		// 初始化 节点值 
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		s->fre = 0;
		
		/*
		循环 双链表 
		s->next = r->next;
		r->next->prior = s;
		r->next = s;
		s->prior = r;
		*/
		
		r->next = s;
		s->prior = r;
		
		r = s; 
	}
	
	r->next = NULL; // 尾指针的后继指向 NULL 
	
}

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

// 需要返回的是节点类型 
linklist Locate(linklist &L, int x){
	lnode *p = L->next, *q;
	while(p && p->data != x){
		p = p->next;
	}
	
	if(!p){
		printf("没有 %d 这个节点", x);
	}
	
	else{
		p->fre++;
		if(p->next != NULL){
			p->next->prior = p->prior;
		}
		// 无论 p的后继是否为空，p的前一个节点 指向 p的后一个节点 
		p->prior->next = p->next;
			
		q = p->prior; // q 指向 p节点的前驱
			
		while(q != L && q->fre <= p->fre){ 
		// q 不为头节点，并且 q的fre值 小于等于 p的fre 
			q = q->prior; 
		}
		// 找出来的 q的fre 大于 p的fre  p 插在 q 的后面 
		p->next = q->next;
		q->next->prior = p;
		
		p->prior = q;
		q->next = p;
		
		return p;
	}
}

int main(){
	
	linklist L;
	buildList(L);
	disp(L);
	Locate(L, 5);
	disp(L);
	
	Locate(L, 4);
	Locate(L, 4);
	Locate(L, 3);
	Locate(L, 5);
	disp(L);
	
	return 0;
} 





