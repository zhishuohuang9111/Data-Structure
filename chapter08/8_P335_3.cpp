#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// 快速排序 思想 
void Move(int a[], int n){
	int i = 0, j = n-1;
	// 循环遍历条件 
	while(i < j){
		// 从前往后 找 偶数位置 
		while(i < j && a[i] % 2 == 1){
			i++;
		} 
		// 从后往前 找 奇数位置 
		while(i < j && a[j] % 2 == 0){
			j--;
		}
		// 偶数位置 在 奇数位置 前面 
		if(i < j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp; 
			// 向 中间 靠拢
			i++;
			j--; 
		}	
	}
} 

void Move_two(int a[], int n){
	int i = 0;
	for(int j = 0; j < n; j++){
		if(a[j] % 2 == 1){
			swap(a[j], a[i]);
			i++;
		}
	}
}

int main(){
	
	int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1};
	
	Move(a, 9);
	
	for(int i = 0; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
} 
