#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 20

typedef struct lnode{
	int data;
	struct lnode* next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	L = (lnode*) malloc(sizeof(lnode));
	lnode *r = L, *p;
	for(int i = 0; i < n; i++){
		p = (lnode*) malloc(sizeof(lnode));
		p->data = a[i];
		
		r->next = p;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L){
	lnode* p = L->next;
	while(p){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n");
}

void Get_Common(linklist LA, linklist LB, linklist &LC){
	LC = (lnode*) malloc(sizeof(lnode));
	lnode *r = LC;
	lnode *s;
	lnode *p = LA->next, *q = LB->next;
	while(p && q){
		if(p->data < q->data){
			p = p->next;
		}
		else if(p->data > q->data){
			q = q->next;
		}
		else{
			s = (lnode*) malloc(sizeof(lnode));
			s->data = p->data;
			r->next = s;
			r = r->next;
			// 相等：两个指针 同时后移 
			p = p->next;
			q = q->next;
		}
	}
	// 尾指针置空 
	r->next = NULL;
}

int main(){
	linklist LA, LB, LC;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
	int b[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int n = 10;
	buildlist(LA, a, n);
	buildlist(LB, b, n);
	disp(LA);
	disp(LB);
	Get_Common(LA, LB, LC);
	disp(LC);
	return 0;
} 
