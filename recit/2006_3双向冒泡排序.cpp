#include<stdio.h>
#include<stdlib.h>

typedef struct lnode{
	int n;
	int a[6];
}SqList;

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(SqList &L){
	int low = 0, high = L.n - 1;
	bool flag = true;
	
	// flag：用于记录每一趟遍历是否有交换 
	// 没有交换，说明表已经有序，可以提前结束 
	while(low <= high && flag){
		flag = false;
		for(int i = low; i < high; i++){
			if(L.a[i] > L.a[i+1]){
				swap(L.a[i], L.a[i+1]);
				flag = true;
			}
		} 
		high--;
		
		for(int j = high; j > low; j--){
			if(L.a[j] < L.a[j-1]){
				swap(L.a[j], L.a[j-1]);
				flag = true;
			}
		}
		low++;
	}
}

int main(){
	
	SqList L;
	L.n = 6;
	
	for(int i = 0; i < L.n; i++){
		printf("请输入第 %d 个数：", i + 1);
		scanf("%d", &L.a[i]);
	}
	
	BubbleSort(L);
	
	for(int i = 0; i < L.n; i++){
		printf("%d	", L.a[i]);
	}
	
	return 0;
}
