#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

int n = 9;

int a[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10};

void find(int a[], int x){
	int left = 0, right = n - 1;
	int mid;
	while(left <= right){
		mid = (left + right) / 2;
		printf("mid = %d, a[%d] = %d\n", mid, mid, a[mid]);
		if(x == a[mid]){
			break;
		}
		else if(x < a[mid]){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	printf("left = %d, right = %d \n", left, right); 
	
	// 找到的元素不是最后一个元素，才可以和后一个进行交换 
	if(a[mid] == x && mid != n - 1){
		int temp = a[mid];
		a[mid] = a[mid + 1];
		a[mid + 1] = temp; 
	}
	// 没有找到 
	if(left > right){
		// 执行 后移操作 
		int i;
		for(i = n - 1; i > right; i--){
			a[i + 1] = a[i];
		}
		// 插入元素 插入在  right的后一个元素 
		a[i + 1] = x;
		n = n + 1;
	}
}

void show(int a[]){
	for(int i = 0; i < n; i++){
		printf("%d	", a[i]);
	}
	printf("\n"); 
}

int main(){
	
	show(a);
	find(a, 7);
	show(a);
	return 0;
} 
