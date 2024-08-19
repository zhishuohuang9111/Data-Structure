#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	// int a[Max] = {5, 5, 5, 5, 5, 5, 5, 5};
	int a[Max] = {3, 5, 8, 3, 3, 20, 8, 18};
	int length = 8;
};

// 无序表中 删除重复元素 
void delete_dup(SqList &L){
	int count = 0;
	for(int i = 0; i < L.length; i++){
		bool flag = true;
		for(int j = 0; j < i; j++){
			// 当前元素 在 后面有 
			if(L.a[i] == L.a[j]){
				flag = false;
				break;
			}
		}
		if(flag){
			L.a[count++] = L.a[i];
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
	delete_dup(L);
	show(L);
	
	return 0;
}
