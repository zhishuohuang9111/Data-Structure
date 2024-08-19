#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
	// C 语言 不能进行 静态初始化 
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int length = 8;
}ST;

int Bin(ST s, int ans, int low, int high){
	// 递归条件
	if(low > high){
		return 0;
	} 
	// 求 中间下标 
	int mid = (low + high) / 2;
	// 待查值 >  中间值 
	if(ans > s.a[mid]){
		return Bin(s, ans, mid + 1, high);
	}
	// 待查值 <  中间值 
	else if( ans < s.a[mid]){
		return Bin(s, ans, low, mid - 1);
	}
	// 相等 直接返回该值的下标 
	else{
		return mid;
	}
	
	return mid;
}

int main(){
	ST s;
	// 初始化结构体 
	
	
	int ans = Bin(s, 3, 1, 8);
	printf("%d	", ans); 
	return 0;
}
