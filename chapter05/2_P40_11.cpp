#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef struct lnode{
	int data;
	lnode *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
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

void cut1(linklist &L1, linklist &L2){
	L2 = (linklist) malloc(sizeof(lnode));
	L2->next = NULL; 
	lnode *r = L1, *p = L1->next, *q;
	// L1->next = NULL;
	
	while(p){
		r->next = p;
		r = r->next;
		
		p = p->next;
		
		if(p){
			q = p->next;
			p->next = L2->next;
			L2->next = p;
				// 将 p指针 重新指向原链表 
			p = q;
		}
	}
	r->next = NULL;
}

void cut2(linklist &L1, linklist &L2){
	// 为 L2 链表 分配存储空间 
	L2 = (linklist) malloc(sizeof(lnode));
	L2->next = NULL;
	lnode *p = L1->next, *q;
	L1->next = NULL;
	lnode *r1 = L1; 
	int count = 0;
	
	while(p != NULL){
		count++;
		if(count % 2 != 0){
			r1->next = p;
			r1 = r1->next;
			p = p->next;
		}
		else{
			q = p->next;
			// 头插法 
			p->next = L2->next;
			L2->next = p;
			p = q;
		}
	}
	r1->next = NULL;
	// r2->next = NULL;
}

int main(){
	
	linklist L1, L2;
	
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	
	buildlist(L1, a, n);

	disp(L1);
	
	cut1(L1, L2);
	// cut2(L1, L2);
	
	disp(L1);
	disp(L2);
	
	return 0;
} 
