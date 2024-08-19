#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef struct lnode{
	int data;
	lnode *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	// 为 头节点 分配内存空间  
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

void divide(linklist &L1, linklist &L2){
	// 为 L2 链表 分配存储空间 
	L2 = (linklist) malloc(sizeof(lnode));
	
	lnode *p = L1->next;
	L1->next = NULL;
	lnode *r1 = L1, *r2 = L2; 
	int count = 0;
	while(p != NULL){
		count++;
		
		if(count % 2 != 0){
			r1->next = p;
			r1 = r1->next;
		}
		else{
			r2->next = p;
			r2 = r2->next;
		}
		p = p->next;
	}
	r1->next = NULL;
	r2->next = NULL;
}

void disp(linklist L){
	lnode *p = L->next;
	while(p){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n");
} 

int main(){
	
	linklist L1, L2;
	
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	
	buildlist(L1, a, n);

	disp(L1);
	
	divide(L1, L2);
	
	disp(L1);
	disp(L2);

	return 0;
} 
