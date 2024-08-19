#include<stdio.h>
#include <stdlib.h>

using namespace std;
/*
			一维数组下标从 a[1] 开始
			二维数组下标 从 b[1][1] 开始 
*/ 

// 通过下标 计算 a[i][j]在一维数组的位置 
int value(int a[], int i, int j){
	// 下三角区域（包括主对角线） 
	if(i >= j){
		return a[(i*(i-1))/2 + j];
	}
	// 上三角区域（不包括主对角线）
	else{
		return a[(j*(j-1))/2 + i];
	}
}

//    难点 
void Mult(int a[], int b[], int c[4][4], int n){
	int i, j, k,sum;
	// i = 0 表示 a矩阵 第一行相乘 
	for(i = 1; i <= n; i++){
		// j = 3 表示 b矩阵 第三列相乘 
		for(j = 1 ; j <= n; j++){
			sum = 0;
			for(k = 1; k <= n; k++){
				sum = sum + value(a, i, k) * value(b, k, j);
			}
			// 将 每一行 乘 每一列 的 和 赋值 
			c[i][j] = sum;
		}
		
	}
}

void Add(int a[], int b[], int c[4][4], int n){
	int i, j;
	// i = 0 表示 矩阵 第一行 
	for(i = 1; i <= n; i++){
		// j = 3 表示 矩阵 第三列
		for(j = 1 ; j <= n; j++){
			c[i][j] = value(a, i, j) + value(b, i, j);
		}
	}
}

int main(){
	// 一维数组存储 对称矩阵下三角元素 
	int a[7] = {0, 1, 2, 3, 1, 2, 3};
	int b[7] = {0, 1, 1, 2, 2, 3, 3};
	
	int c[4][4];
	int d[4][4]; 
	
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			c[i][j] = 0;
			d[i][j] = 0;
		}
	}
	
	Add(a, b, c, 3);
	
	Mult(a, b, d, 3);
	
	printf("稀疏矩阵加法：\n"); 
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			printf("%d	", c[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("稀疏矩阵乘法：\n"); 
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			printf("%d	", d[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
