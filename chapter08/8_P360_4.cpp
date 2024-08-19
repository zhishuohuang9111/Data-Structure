#include<stdio.h>
#include<stdlib.h>

using namespace std;

// 将 最后一个元素 放在 排序后的 正确位置 

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

int QuickSort(int a[], int low, int high){
	int i = high;
	int pivot = a[high];
	
	for(int j = high - 1; j >= 0; j--){
		// 大于 基准值 
		if(a[j] > pivot){
			// i 先自减，再进行交换 
			swap(a[--i], a[j]);
		}
	}
	// for 循环结束时，i 所指的元素 大于 基准值 
	// 将 最后一个元素 放置到 真确位置 
	swap(a[high], a[i]);
	// 返回基准值下标 
	return i;
} 

int main(){
	
	int a[5] = {3, 6, 7, 4, 5};
	// 3  6  7  4  5
	// 3   6   4   7   5
	//  3   4    6    7    5   此时 i 指向 6，将 a[i] 与 a[high] 进行交换
	//  3   4    5    7    6 
	int i = QuickSort(a, 0, 4);
	printf("%d", i);
	printf("\n");
	
	for(int i = 0; i < 5; i++){
		printf("%d	", a[i]);
	} 
	return 0;
} 
