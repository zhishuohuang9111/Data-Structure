#include<stdio.h>
#include<stdlib.h>

using namespace std;

// 数组下标从 1 开始 
int is_min(int a[], int len){
	// 偶数个，含有 单支结点 
	if(len % 2 == 0){
		// 判断 单支结点 
		if(a[len / 2] > a[len]){
			// 单支结点不满足 直接结束 
			return 0;
		}
		// 判断 双支结点 
		for(int  i = len / 2 - 1; i >= 1; i--){
			if(a[i] > a[2*i] || a[i] > a[2*i + 1]){
				return 0;
			}
		}
	}
	// 奇数个
	else{
		for(int i = len / 2; i >= 1; i--){
			if(a[i] > a[2*i] || a[i] > a[2*i + 1]){
				return 0;
			}
		}
	}
	
	return 1; 
}

int main(){
	
	int a[8] = {0, 1, 3, 2, 5, 4, 0};
	
	int i = is_min(a, 6);
	
	printf("%d	", i);
	
	return 0;
} 
