#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// 非递归快速排序算法 
void setPartition(int a[], int low, int high, int n){
	// 取中间值下标 
	int k = (low + high) / 2; 
	bool flag = true; 
	
	while(flag){
		
		int i = low;
		int pivot = a[low];
		for(int j = low + 1; j <= high; j++){
			// 将 比基准值小的值 放到前面 
			if(a[j] < pivot){
				swap(a[++i], a[j]);
			}
		}
		
		// 将 基准值 插入到最终位置 
		swap(a[low], a[i]);
		
		// 基准值下标 刚好等于 s1 的右端 结束 
		if(i == k-1){
			flag = false; 
		}
		// 基准值下标 小于 则在右端进行快排 继续找到中间值
		else if(i < k-1){
			low = i + 1;
		} 
		// 基准值下标 大于 则在左端进行快排 继续找到中间值
		else{
			high = i - 1;
		}
	}
	
	int s1 = 0, s2 = 0;
	for(int i = 0; i < k; i++){
		s1 += a[i];
		printf("%d	", a[i]);
	}
	printf("s1 = %d\n", s1);
	
	for(int i = k; i < n; i++){
		s2 += a[i];
		printf("%d	", a[i]);
	}
	printf("s2 = %d\n", s2);
	
	printf("%d	", s2 - s1);
}

int main(){
	
	int a[9] = {0, -1, -2, 0, -10, 3, -4, 1};
	
	setPartition(a, 0, 8, 8);
	return 0;
} 
