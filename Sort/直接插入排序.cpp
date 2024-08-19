#include<stdlib.h>
#include<stdio.h>

using namespace std;

// n：元素个数    数组空间：n + 1 个 
void insertSort(int a[], int n){
	int i, j; 
	for(i = 2; i <= n; i++){
		if(a[i] < a[i - 1]){
			// a[0] 哨兵，起监视作用 
			a[0] = a[i];
			// j 指向 有序序列的最后一个位置 
			j = i - 1;
			while(a[0] < a[j]){
				a[j + 1] = a[j];
				j--;
			}
			// 将 待插入元素 放入目标位置 
			a[j + 1] = a[0]; 
		}
	}
}

void insertSort2(int a[], int n){
	int i, j, low, high, mid; 
	for(i = 2; i <= n; i++){
		if(a[i] < a[i - 1]){
			// a[0] 哨兵，起监视作用 
			a[0] = a[i];
			// j 指向 有序序列的最后一个位置 
			j = i - 1;
			low = 1;
			high = i - 1;
			// 二分查找 查找插入位置 
			while(low <= high){
				mid = (low + high) / 2;
				if(a[0] < a[mid]){
					high = mid - 1;
				}
				else{
					low = mid + 1;
				}
			}
			
			for(j = i - 1; j >= high + 1; j--){
				a[j + 1] = a[j];
			}
			// 将 待插入元素 放入目标位置 
			a[high + 1] = a[0]; 
		}
	}
}

int main(){
	
	int a[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	insertSort(a, 8);
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
