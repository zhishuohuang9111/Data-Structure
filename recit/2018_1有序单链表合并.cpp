#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	// 带 头节点 
	L = (lnode *) malloc(sizeof(lnode));
	// 存储链表结点个数 
	L->data = n;
	L->next = NULL;
	lnode *s;
	lnode *r = L;
	
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
	while(p != NULL){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n"); 
}

void Merge(linklist &LA, linklist &LB, linklist &LC){
	lnode *p1 = LA->next;
	lnode *p2 = LB->next;
	LC = (lnode*) malloc(sizeof(lnode));
	lnode* r = LC;
	lnode* s;
	
	while(p1 != NULL && p2 != NULL){
		s = (lnode*) malloc(sizeof(lnode));
		if(p1->data <= p2->data){
			s->data = p1->data;
			
			r->next = s;
			r = r->next;
			p1 = p1->next;
		}
		else{
			s->data = p2->data;
			
			r->next = s;
			r = r->next;
			p2 = p2->next;
		}
	}
	// 两个 if 语句 一定会执行一个 
	if(p1 != NULL){
		r->next = p1;
	}
	if(p2 != NULL){
		r->next = p2;
	}
}

int main(){
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[5] = {1, 7, 9, 12, 16};
	
	linklist LA, LB, LC;
	
	buildlist(LA, a, 10);
	buildlist(LB, b, 5);
	
	Merge(LA, LB, LC);
	
	disp(LC);
	
	return 0;
}
