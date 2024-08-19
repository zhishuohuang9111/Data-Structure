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

linklist Union(linklist &L1, linklist &L2){
	// p1 p2 工作指针 
	lnode *p1 = L1->next;
	lnode *p2 = L2->next;
	lnode *r = L1;
	// 保存 待删除结点 指针 
	lnode *q;
	
	while(p1 && p2){
		if(p1->data == p2->data){
			r->next = p1;
			r = p1;
			
			q = p2;
			// 后移 
			p1 = p1->next;
			p2 = p2->next;
			free(q); 
		}
		else if(p1->data < p2->data){
			q = p1;
			p1 = p1->next;
			free(q);
		}
		else{
			q = p2;
			p2 = p2->next;
			free(q);
		}
	}
	// 尾指针 置为 NULL 防止有乱指向 
	r->next = NULL;
	// L1 未遍历完 
	while(p1){
		q = p1;
		p1 = p1->next;
		free(q);
	}
	// L2 未遍历完 
	while(p2){
		q = p2;
		p2 = p2->next;
		free(q);
	}
	free(L2);
	return L1;
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
	
	linklist A;
	linklist B;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[10] = {2, 4, 6, 8, 10, 12, 14, 16}; 
	int n = 10;
	buildlist(A, a, n);
	buildlist(B, b, 8);

	disp(A);
	disp(B);
	
	Union(A, B);
	disp(A);
	
	return 0;
}
