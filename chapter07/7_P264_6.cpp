#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

//   数组   数组元素个数   待查值 
int Search(int a[], int n, int k){
	int i;
	for(i = 0; i < n; i++){
		if(a[i] == k){
			break;
		}
	}
	// i > 0：不是第一个元素  i < n：数组中有待查元素 
	if(i > 0 && i < n){
		int temp = a[i];
		a[i] = a[i-1];
		a[i-1] = temp;
		
		// 返回交换后的位置 
		return i-1;
	}
	else{
		// 交换失败 
		return -1;
	} 
	
} 

int main(){
	
	int a[6] = {1, 3, 5, 7, 9, 11};
	
	int locate = Search(a, 6, 7);
	printf("%d	", locate);
	
	return 0;
} 
