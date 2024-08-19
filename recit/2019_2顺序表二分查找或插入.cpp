#include<stdio.h>
#include<stdlib.h>

#define Max 50

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// n 需要带引用符号，因为未查到元素需要改变数组长度 
int Find(int a[], int &n, int x){
	int low = 0, high = n - 1;
	int mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(x == a[mid]){
			return mid; 
		}
		else if(x > a[mid]){
			// 往右边找 
			low = mid + 1;
		}
		else{
			// 往左边找 
			high = mid - 1;
		}
	}
	// 未找到，进行插入 
	for(int i = n - 1; i > high; i--){
		a[i + 1] = a[i];
	}
	// 插入元素 插入在 high 的后一个元素 
	a[high + 1] = x;
	n = n + 1;
}

void disp(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d	", a[i]);
	}
	printf("\n"); 
}

int main(){
	
	int a[Max] = {1, 2, 3, 6, 7, 8, 9, 10, 15};
	int n = 9;
	disp(a, n);
	Find(a, n, 5);
	disp(a, n);
	
	return 0;
} 
