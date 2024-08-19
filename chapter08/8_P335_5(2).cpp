#include<stdio.h>
#include<stdlib.h>

using namespace std;

// &：结果需要返回 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// low 从 0 开始 
int min_k(int a[], int low, int high, int k){
	// 快速排序 划分算法 
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
	
	// 数组下标 从 0 开始 
	// 最后 基准位置 == k - 1：基准就是 第 k 小
	if(i == k - 1){
		return a[i];
	} 
	// 最后 基准位置 > k - 1：在基准左边递归去找 第 k 小
	else if(i > k - 1){
		return min_k(a, low, i -1, k);
	}
	// 最后 基准位置 < k - 1：在基准右边递归去找 第 k 小
	else{
		return min_k(a, i + 1, high, k);
	}
}

int main(){
	
	int a[10] = {0, 7, 5, 9, 2, 6, 4, 3, 8, 1};
	
	int k = min_k(a, 0, 9, 1);
	
	printf("%d", k); 
	
	return 0;
}
