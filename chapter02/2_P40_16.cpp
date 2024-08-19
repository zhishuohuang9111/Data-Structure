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

bool isok(linklist L1, linklist L2){
	lnode* p1 = L1->next;
	lnode* p2 = L2->next;
	// 记录每一次比较的起始位置 
	lnode* r = L1->next;
	
	while(p1 && p2){
		if(p1->data != p2->data){
			r = r->next;
			p1 = r;
			p2 = L2->next;
		}
		else{
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	// p2 为 NULL 表示 p2 链表全遍历完 
	if(p2 == NULL){
		return true;
	}
	return false;
}

int main(){
	
	int a[6] = {1, 2, 3, 4, 5, 6};
	int b[3] = {3, 4, 5};
	
	linklist L1, L2;
	buildlist(L1, a, 6);
	buildlist(L2, b, 3);
	
	if(isok(L1, L2)){
		printf("yes");
	}
	else{
		printf("no");
	}
	
	
	return 0;
} 
