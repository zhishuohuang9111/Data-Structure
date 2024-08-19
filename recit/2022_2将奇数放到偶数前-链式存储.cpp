#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	L = (lnode*) malloc(sizeof(lnode));
	lnode *s, *r = L;
	for(int i = 0; i < n; i++){
		s = (lnode*) malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void swap(linklist &L){
	lnode *p = L->next;
	L->next = NULL;
	lnode *q;
	lnode *head;
	head->next = NULL;
	lnode *s = L;
	
	while(p){
		// q 指向 当前结点 
		q = p;
		p = p->next;
		// 偶数：头插法 插入 head 表 
		if(q->data % 2 == 0){
			q->next = head->next;
			head->next = q;
		}
		// 奇数 
		else{
			s->next = q;
			s = s->next;
		}
	}
	s->next = head->next;
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
	
	linklist L;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 10;
	buildlist(L, a, n);

	disp(L);
	
	swap(L);
	
	disp(L);
	
	return 0;
}
