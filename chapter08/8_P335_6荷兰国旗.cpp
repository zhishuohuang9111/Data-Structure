#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void Move(int a[], int n){
	// 三个指针的指向 初始化 
	int i = 0, j = 0, k = n-1;
	
	while(j <= k){
		int temp;
		
		if(a[j] > 0){
			temp = 1;
		}
		else if(a[j] == 0){
			temp = 0;
		}
		else {
			temp = -1;
		}
		// switch 判断 a[j] 的值 
		switch(temp){
			// 负数：和 a[i] 交换
			case -1: swap(a[i], a[j]); i++;j++;break;
			// 零：遍历指针 + 1
			case 0: j++; break;
			// 正数：和 a[k] 交换
			// 注意：j 不能 + 1,因为可能交换过来的值为 负值 
			case 1:swap(a[j], a[k]); k--; break; 
		}
	}
}

int main(){
	
	int a[9] = {8, -1, -2, 0, 0, 5, -6, -10};
	
	Move(a, 8);
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
} 
