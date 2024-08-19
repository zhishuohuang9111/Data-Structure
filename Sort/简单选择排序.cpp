#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void selectSort(int a[], int n){
	int min;
	// 最后一个选择排序的元素 一定是 最大者 
	for(int i = 0; i < n - 1; i++){
		min = i;
		for(int j = i; j < n; j++){
			if(a[min] > a[j]){
				// min 更新最小值下标 
				min = j;
			}
		}
		if(min != i){
			// min == i：min 所指下标 就是 当前元素中 最小者 
			swap(a[i], a[min]);
		}
		
	}
}

int main(){
	
	int a[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	
	selectSort(a, 8);
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	} 
	
	return 0;
}
