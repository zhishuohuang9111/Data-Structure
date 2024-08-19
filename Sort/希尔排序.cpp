#include<stdio.h>
#include<stdlib.h>

using namespace std;

// n：元素个数    数组空间：n + 1 个 
// 采用 分治法 的思想 
void shellSort(int a[], int n){
	int d;
	for(d = n / 2; d >= 1; d = d / 2){
		// 以 d 为增量，进行组内直接插入排序 
		for(int i = d + 1; i <= n; i++){
			a[0] = a[i]; // a[0] 暂存 a[i] 的值 
			int j = i - d;  // j 指向 所属子序列的最后一个记录 
			// j > 0：防止下标越界 
			while(j > 0 && a[0] < a[j]){
				a[j + d] = a[j]; // 记录后移 d 个位置 
				j = j - d; // 比较 同一子序列的前一个记录 
			}
			a[j + d] = a[0];
		}
	}
}

int main(){
	
	int a[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	shellSort(a, 8);
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
} 
