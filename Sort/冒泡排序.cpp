#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n){
	int exchange = n - 1;
	while(exchange){
		int bound = exchange;
		// exchange 在 for 循环结束后，若仍未 0，则没有进行交换 
		exchange = 0;
		for(int i = 0; i < bound; i++){
			if(a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
				// exchange 记录 交换位置所处下标 
				exchange = i;
			}
		}
	}
}

void bubbleSort2(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		bool flag = false;
		// 每一趟 将 当前最大值 放到 当前的最后
		// 注意：j < n - i - 1 
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		// 本趟遍历 没有进行交换，说明表已经有序 
		if(flag == false){
			return;
		}
	}
}

int main(){
	
	int a[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	bubbleSort2(a, 8);
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
