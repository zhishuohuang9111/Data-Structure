#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[5] = {3, 1, 6, 4, 8};

int n = 5;

void buildlist(linklist &L){
	// 创建 头节点 
	L = (linklist) malloc(sizeof(lnode));
	lnode *s;
	lnode *r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		// 尾插法 
		r->next = s;
		r = r->next;
	}
	// 将 尾指针 指向 头节点，构成 循环链表 
	r->next = L;
}

void disp(linklist L){
	lnode *s = L->next;
	while(s != L){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

void delete_min(linklist &L){
	lnode *p;
	lnode *pre;
	
	lnode *min;
	lnode *pre_min;
	
	while(L->next != L){
		// 每一次遍历，将 p 初始化指向 第一个 元素结点 
		p = L->next; 
		pre = L;
		// 初始时，最小值 设为 第一个结点值 
		min = p;
		pre_min = pre;
		while(p != L){
			// 当前结点值 < 最小结点值 
			if(p->data < min->data){
				min = p;
				pre_min = pre;
			}
			pre = p;
			p = p->next;
		}
		printf("当前最小元素：%d\n", min->data);
		pre_min->next = min->next;
		// 释放 当前最小值 结点 
		free(min);
		
		disp(L); 
	}
	// 释放头节点 
	free(L); 
	
}

int main(){

	linklist L;
	buildlist(L);
	
	disp(L);
	
	delete_min(L);
	
	return 0;
} 
