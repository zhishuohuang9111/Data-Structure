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

void InsertSort(linklist &L){
	lnode* p = L->next->next;
	lnode* p_next;
	lnode* q = L;
	L->next->next = NULL;
	
	while(p != NULL){
		p_next = p->next;

		while(q->next != NULL){
			if(p->data > q->next->data){
				q = q->next;
			}
			else{
				break;
			}
		}
		// 将结点进行插入 
		p->next = q->next;
		q->next = p;
		
		// q 重新指向表头结点，p 指向原链表的下一个结点 
		q = L;
		p = p_next;
	} 
}

int main(){
	int a[5] = {4, 3, 5, 2, 1};
	
	linklist L;
	
	buildlist(L, a, 5);
	
	disp(L);
	
	InsertSort(L);
	
	disp(L);
	
	return 0;
}
