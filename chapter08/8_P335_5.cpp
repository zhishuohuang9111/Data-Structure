#include<stdio.h>
#include<stdlib.h>

using namespace std;

// &：结果需要返回 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// low 从 1 开始 
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
	
	
	// 最后 基准位置 = k：基准就是 第 k 小
	// 递归出口条件 
	if(i == k){
		return a[i];
	} 
	// 最后 基准位置 > k：在基准左边递归去找 第 k 小
	else if(i > k){
		return min_k(a, low, i -1, k);
	}
	// 最后 基准位置 < k：在基准右边递归去找 第 k 小
	else{
		return min_k(a, i + 1, high, k);
	}
}

// low 从 1 开始
// 非递归快速排序 
int min_k1(int a[], int low, int high, int k){
	
	int i;
	bool flag = true;
	// 从第二个开始遍历到结束 
	while(flag){
		i = low;
		// 获取 基准值
		int p = a[low]; 
		
		for(int j = low + 1; j <= high; j++){
			if(a[j] < p){
				// i 的下标 先自增，再交换 
				swap(a[++i], a[j]); 
			}
		} 
		// 将基准值 插入到 最终位置
		swap(a[low], a[i]);
		
		if(i == k){
			flag = false;
		}
		// 最后 基准位置 > k
		else if(i > k){
			high = i - 1;
		}
		// 最后 基准位置 < k
		else{
			low = i + 1;
		}
	}
	return a[i];
}

int main(){
	
	int a[10] = {0, 7, 5, 17, 2, 6, 4, 3, 8, 1};
	
	int k = min_k(a, 1, 9, 9);
	
	printf("%d", k); 
	
	return 0;
}
