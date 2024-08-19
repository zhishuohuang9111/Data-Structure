#include<stdio.h>
#include<stdlib.h>

using namespace std;

// 插入排序 的思想 
void InsertSort(int a[], int m, int n){
	int i, j;
	for(i = m+1; i <= m+n; i++){
		// a[0] 作为哨兵，每一趟都需要更新 a[0] = a[i]（当前待插入元素） 
		a[0] = a[i];
		// 条件 a[j] > a[0]：元素后移 
		for(j = i-1; a[j] > a[0]; j--){
			a[j + 1] = a[j];
		}
		// 跳出循环：a[j] < a[0]，哨兵插入位置为 j + 1 
		a[j + 1] = a[0]; 
	}
}

int main(){
	
	int a[8] = {0, 1, 3, 5, 7, 2, 4, 9};
	
	InsertSort(a, 4, 3);
	
	for(int i = 1; i <= 7; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
