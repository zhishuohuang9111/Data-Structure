#include<stdio.h>
#include<stdlib.h>

using namespace std;

void countSort(int a[], int b[], int n){
	// 遍历每一趟
	int count;
	for(int i = 0; i < n; i++){
		// 找 比每个元素小的个数 
		count = 0;
		for(int j = 0; j < n; j++){
			if(a[j] < a[i]){
				count++;
			}
		}
		b[count] = a[i];  
	} 
}

int main(){
	
	int a[6] = {3, 5, 7, 2, 4, 9};
	
	int b[6];
	
	countSort(a, b, 6);
	
	for(int i = 0; i < 6; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i < 6; i++){
		// b[5] = 9：表示 比 元素 9 小的个数有 5 个  
		printf("比 %d 小的个数有：%d\n", b[i], i);
	}
	
	return 0;
}
