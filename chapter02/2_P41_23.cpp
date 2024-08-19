#include<stdio.h>
#include <stdlib.h>

typedef struct lnode{
	char data;
	lnode *next;
	
}lnode, *linklist;

char a[7] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};
char b[5] = {'b', 'e', 'i', 'n', 'g'};

int n1 = 7, n2 = 5;

void buildlist(linklist &L, char aa[], int n){
	L = (linklist) malloc(sizeof(lnode));
	lnode *s, *r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = aa[i];
		
		r->next = s;
		r = r->next;
	}
	
	r->next = NULL;
}

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%c	", s->data);
		s = s->next; 
	}
	printf("\n");
}

int length(linklist L){
	int len = 0;
	lnode *s = L->next;
	while(s){
		len++;
		s = s->next;
	}
	return len;
}

linklist first(linklist L1, linklist L2){
	int len1 = length(L1);
	int len2 = length(L2);
	
	int distant = abs(len1 - len2);
	printf("两个链表的长度差：%d\n", distant);
	
	lnode *p = L1->next, *q = L2->next;
	
	if(len1 > len2){
		while(distant--){
			p = p->next;
		}
	}
	else{
		while(distant--){
			q = q->next;
		}
	}
	
	while(p){
		if(p->data != q->data){
			p = p->next;
			q = q->next;
		}
		else{
			return p;
		}
	}
	
	return p;
	
}

int main(){
	linklist L1, L2;
	buildlist(L1, a, n1);
	buildlist(L2, b, n2);
	disp(L1);
	disp(L2);
	
	linklist ans = first(L1, L2);
	if(ans){
		printf("%c", ans->data);
	}
	else{
		printf("没有公共后缀！！！");
	}
	
	return 0;
	
}

