#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

void buildlist(lnode *L, int a[], int n){
	// 不带头节点 对只有一个结点的 特殊处理 
	lnode *s;
	lnode *r = L;
	
	r->data = a[0];
	
	if(n == 1){
		r->next = NULL;
	}
	else{
		for(int i = 1; i < n; i++){
			s = (lnode *) malloc(sizeof(lnode));
			s->data = a[i];
	
			r->next = s;
			r = r->next; 
		}
		r->next = NULL;
	}
	
	
	
}

void disp(linklist L){
	lnode *p = L;
	while(p != NULL){
		printf("%d	", p->data);
		p = p->next;
	}
}

void SelectSort(linklist &L){
	lnode *h = L, *p, *pre_p, *max, *pre_max;
	// 将 表置空 
	L = NULL;
	
	// 最外面的循环条件
	while(h != NULL){
		// 最大值指针  工作指针初始化 
		max = h;
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
			// 将 最大结点 摘出来，重新连链 
			pre_max->next = max->next;
		}
		
		// 将 最大结点 插入 
		max->next = L;
		// L 指针后移 
		L = max; 
	} 
}

int main(){
	int a[10] = {9, 7, 5, 6, 3, 4, 1, 2, 8};
	
	lnode list;
	lnode *L = &list;
	
	buildlist(L, a, 9);
	
	disp(L);
	
	printf("\n");
	
	SelectSort(L); 
	
	disp(L);
	
	return 0;
}
