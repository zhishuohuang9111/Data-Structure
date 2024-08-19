#include<stdio.h>
#include <stdlib.h>
 
typedef struct lnode{
	int data, fre;
	lnode *prior,*next;
	
}lnode, *linklist;

// 带有头节点的 非循环 双向链表 
void buildList(linklist &L, int a[], int n){
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L, *s;
	L->prior = NULL;
	L->next = NULL;
	
	for(int i = 0; i < n; i++){
		// 初始化 节点值 
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		s->fre = 0;
		
		r->next = s;
		s->prior = r;
		
		r = s; 
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

linklist Locate(linklist &L, int x){
	// p：工作指针，指向 data = x 的结点 
	lnode *p = L->next, *q;
	while(p && p->data != x){
		p = p->next;
	}
	
	if(!p){
		printf("没有 %d 这个节点", x);
	}
	
	else{
		p->fre++;
		// p 的后继非空 
		if(p->next != NULL){
			// p的后一个结点的前驱 指向 p的前一个结点 
			p->next->prior = p->prior;
		}
		// 无论 p的后继是否为空，p的前一个节点的后继 指向 p的后一个节点 
		p->prior->next = p->next;
		
		// q 指向 p节点的前一个结点 
		q = p->prior; 
		// 同一访问频度下，最近访问的 排放在最前面 
		while(q != L && q->fre <= p->fre){ 
		// q 不为头节点，并且 q的fre值 小于等于 p的fre 
			q = q->prior; 
		}
		// while循环结束：q->fre > p->fre，将 p结点 插在 q结点 的后面 
		p->next = q->next;
		q->next->prior = p;
		
		p->prior = q;
		q->next = p;
	}
	return p;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int n = 5;
	
	linklist L;
	buildList(L, a, n);
	disp(L);
	Locate(L, 5);
	disp(L);

	lnode* p = Locate(L, 10);
	if(p){
		printf("%d	", p->data);
	}
	disp(L);
	
	return 0;
} 
