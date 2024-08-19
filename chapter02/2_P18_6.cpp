#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	// int a[Max] = {5, 5, 5, 5, 5, 5, 5, 5};
	int a[Max] = {3, 3, 5, 5, 5, 8, 8, 18};
	int length = 8;
};

// 有序表中 删除重复元素 
void delete_duplicate(SqList &L){
	
	int i = 0;
	
	for(int j = 1; j < L.length; j++){
		if(L.a[i] != L.a[j]){
			L.a[++i] = L.a[j];
		}
	}
	
	L.length = i + 1;
	
}

// 无序表中 删除重复元素 
void delete_dup(SqList &L){
	int count = 0;
	for(int i = 0; i < L.length; i++){
		bool flag = true;
		for(int j = i + 1; j < L.length; j++){
			// 当前元素 在 后面有 
			if(L.a[i] == L.a[j]){
				flag = false;
				break;
			}
		}
		// 当前元素 在 后面没有 
		if(flag){
			bool f = true;
			for(int k = 0; k < count; k++){
				// 当前元素 在 已选出的元素中 有 
				if(L.a[k] == L.a[i]){
					f = false;
				}
			}
			// 当前元素 不在 已选出的元素中
			if(f){
				L.a[count++] = L.a[i];
			}
		}
	}
	L.length = count;
}

void show(SqList s){
	if(s.length == 0){
		printf("线性表为空");
		return;
	}
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.a[i]);
	}
	printf("\n"); 
}

int main(){
	
	SqList L;
	
	show(L);
	delete_duplicate(L);
	show(L);
	
	return 0;
}
