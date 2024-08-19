#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	char data;
	struct lnode *next;
}lnode, *linklist;

char s1[6] = {'a', 'b', 'c', 'c', 'b', 'a'};

int n = 6;

void buildlist(linklist &L){
	L = (linklist) malloc(sizeof(lnode));
	lnode *s, *r = L;
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = s1[i];
		
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

bool isok(linklist L, int n){
	char str[n/2];
	lnode *p = L->next;
	int i;
	
	for(i = 0; i < n/2; i++){
		str[i] = p->data;
		p = p->next;
	}
	// 恢复 i 的值 
	i--;
	// 若 n 是奇数，后移过中心结点 
	if(n % 2 == 1){
		p = p->next;
	} 
	// 检查是否中心对称 
	while(p && p->data == str[i]){
		i--;
		p = p->next;
	}
	
	if(i == -1){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	
	linklist L;
	buildlist(L);
	if(isok(L, n)){
		printf("yes");
	}
	else{
		printf("no");
	}
	
	return 0;
} 
