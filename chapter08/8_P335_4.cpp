#include<stdio.h>
#include<stdlib.h>

using namespace std;

// &：结果需要返回 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int a[], int low, int high){
	// 获取随机下标 (high - low + 1：长度)
	int root = low + rand() %(high - low + 1); 
	printf("a[root] = %d", a[root]);
	// 交换到第一个
	swap(a[low], a[root]); 
	// i 一开始指向 low 位置
	int i = low;
	// 获取 基准值
	int p = a[low]; 
	// 从第二个开始遍历到结束 
	for(int j = low + 1; j <= high; j++){
		if(a[j] < p){
			// i 的下标 先自增，再交换 
			swap(a[++i], a[j]); 
		}
	} 
	// 将基准值 插入到 最终位置
	swap(a[low], a[i]);
	printf("a[i] = %d	", a[i]);
	// 返回 基准值 下标 
	return i; 
}

int main(){
	
	int a[10] = {7, 5, 2, 9, 6, 30, 3, 8, 1};
	// int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = Partition(a, 0, 8); 
	
	for(int i = 0; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	printf("i = %d", i);
	
	return 0;
} 
