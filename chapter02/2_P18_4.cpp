#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	int a[Max] = {3, 5, 8, 10, 11, 13, 15, 18};
	int length = 8;
};

bool delete_range(SqList &L, int s, int t){
	if(L.length == 0 || s >= t){
		return false;
	}
	int ss = 0, tt = 0;
	
	// 线性表最大元素 < s  或  线性表最小元素 > t 
	if(L.a[L.length - 1] < s || L.a[0] > t){
		return false; 
	}
	
	for(int i = 0; i < L.length; i++){
		if(L.a[i] >= s){
			// 找到 第一个要删除的元素 
			ss = i;
			break;
		}
	}
	
	for(tt = ss; tt < L.length; tt++){
		if(L.a[tt] > t){
			// 找到 第一个 不需要删除的元素 
			break;
		}
	}
	
	// 待删除元素个数 
	int count = tt - ss;
	
	for(int i = tt; i < L.length; i++){
		L.a[ss++] = L.a[i]; 
	}
	L.length = L.length - count;
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
	delete_range(L, 4, 14);
	show(L);
	
	return 0;
}
