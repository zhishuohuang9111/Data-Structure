#include<stdio.h>
#include <stdlib.h>

using namespace std;

void bubblesort(int a[], int n){
	
	int low = 0, high = n-1;
	bool flag = true;
	// 循环条件：左端 < 右端 并且 一趟有交换 
	while(low < high && flag){
		// 排序前 默认一趟没有交换 
		flag = false;
		// 从前 向后 排：冒最大值 
		for(int i = low; i < high; i++){
			if(a[i] > a[i+1]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				// 有交换 flag 置为 true 
				flag = true;
			}
		} 
		// 右端 左移 
		high--; 
		// 从后 向前 排：冒最小者 
		for(int j = high; j > low; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				flag = true;
			}
		} 
		low++;
	}
	
}

int main(){
	
	int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1, 10};
	
	bubblesort(a, 10);
	
	for(int i = 0; i < 10; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
