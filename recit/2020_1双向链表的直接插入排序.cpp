#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *prior, *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	// 带 头节点 
	L = (lnode *) malloc(sizeof(lnode));
	// 存储链表结点个数 
	L->data = n;
	L->prior = NULL;
	L->next = NULL;
	lnode *s;
	lnode *r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];

		r->next = s;
		s->prior = r;
		
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

void InsertSort(linklist &L){
	lnode* head = L;
	lnode* q = L->next;
	lnode* p = L->next->next;
	lnode* r1, *r2;
	
	while(p != NULL){
		printf("test 1");
		r1 = q;
		r2 = p->next;
		
		while(q != L){
			printf("q->data = %d, p->data = %d\n", q->data, p->data);
			if(q->data > p->data){
				q = q->prior;
			}
			else{
				break;
			}
		}
		
		p->next = q->next;
		q->next->prior = p;
		
		q->next = p;
		p->prior = q;
		if(q == r1){
			r1 = r1->next;
		}
		q = r1;
		p = r2;
	}
	r1->next = NULL;
}

int main(){
	int a[5] = {4, 3, 5, 2, 1};
	
	linklist L;
	
	buildlist(L, a, 5);
	
	disp(L);
	
	InsertSort(L);
	
	// disp(L);
	
	return 0;
}
