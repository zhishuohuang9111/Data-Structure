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

// 选择排序：每次选择出 当前最大值，都链表进行 头插法 
void SelectSort(linklist &L){
	lnode *h = L->next, *p, *pre_p, *max, *pre_max;
	// 将 表置空 
	L->next = NULL;
	// 最外面的循环条件
	while(h != NULL){
		// 最大值指针初始化，最大值初始为第一个节点值  
		max = h;
		// 工作指针初始化 
		p = h;
		pre_p = NULL;
		pre_max = NULL;
		// 每一趟开始遍历
		while(p != NULL){
			if(p->data > max->data){
				// 跟新最大值结点位置 
				max = p;
				pre_max = pre_p;
			}
			// 更新 工作指针前驱 和 工作指针  
			pre_p = p;
			p = p->next;
		}
		// 最大结点 是 表头结点，表头结点后移 
		if(max == h){
			h = h->next;
		} 
		else{
			pre_max->next = max->next;
		}
		// 将 最大结点 插入 
		max->next = L->next;
		L->next = max; 
	} 
}

int main(){
	int a[5] = {4, 3, 5, 2, 1};
	
	linklist L;
	
	buildlist(L, a, 5);
	
	disp(L);
	
	SelectSort(L); 
	
	disp(L);
	
	return 0;
}
