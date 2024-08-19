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
	while(p){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n");
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
	
	while(p1){
		q = p1;
		p1 = p1->next;
		free(q);
	}
	
	while(p2){
		q = p2;
		p2 = p2->next;
		free(q);
	}
	
	free(L2);
	
	return L1;
}

int main(){
	
	linklist L1, L2;
	int a[6] = {1, 3, 5, 7, 9, 10};
	int b[6] = {1, 5, 6, 7, 8, 10};
	
	buildlist(L1, a, 6);
	buildlist(L2, b, 6);
	
	disp(L1);
	disp(L2);
	
	Union(L1, L2);
	
	disp(L1);
	
	
	
	return 0;
} 
