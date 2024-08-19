#include <stdio.h>
#include <stdlib.h>
#define Max 100

//三元组结构体的定义 
typedef struct{
	// 非零元所在行、所在列 
	int row, col;
	// 非零元的值 
	int value;		
}Triple;
 
//三元组容器的定义 
typedef struct{
	// data[0] 未使用 
	Triple data[Max];
	// 矩阵为 m行、n列  
	int m, n;
	// 矩阵非零元个数
	int len; 
}TSMatrix;
 
//实现转置 
void TransposeSMatrix(TSMatrix A, TSMatrix &B){
	
	int i, col;
	// 矩阵 A m行、n列  转置为 矩阵 B n行、m列 
	B.m = A.n;
	B.n = A.m;
	B.len = A.len;
	// q 表示Triple数组下标，从 1 开始，data[0] 未使用  
	int q = 1;
	
	// col <= A矩阵的列数，控制的是 当前遍历的是 A矩阵的列  
	for(col = 1; col <= A.n; ++col){	
		// 每一次 遍历一遍 Triple数组 
		for(i = 1; i <= A.len; ++i){
			// 若 当前元素的列标 == col（矩阵 A 的第 col 列） 
			if(A.data[i].col == col){
				// A的列 转换为 B的行 
				B.data[q].row = A.data[i].col;
				// A的行 转换为 B的列 
				B.data[q].col = A.data[i].row;
				// 赋 非零元 的值 
				B.data[q].value = A.data[i].value;
				// 数组下标后移一位 
				++q;
			}
		}
	} 
}

void inputTSMatrix(TSMatrix &T){
	int i, j, value, k; 
	printf("请输入矩阵行数、列数：");
	scanf("%d %d", &T.m, &T.n);
	printf("请输入三元组 非零元个数：");
	scanf("%d", &T.len);
	for(k = 1; k <= T.len; k++){
		printf("请输入第 %d 个非零元：行 列 值：", k);
		scanf("%d %d %d", &i, &j, &value);
		T.data[k].row = i;
		T.data[k].col = j;
		T.data[k].value = value;
	}
}

void printTSMatrix(TSMatrix T){
	for(int i = 1; i <= T.len; ++i ){
		printf("%d	%d	%d\n", T.data[i].row, T.data[i].col, T.data[i].value);
	}
}

int main(){

	TSMatrix A,B;
	inputTSMatrix(A);

	TransposeSMatrix(A, B);

	printf("\n原始三元组为:\n");
	printTSMatrix(A);
	
	printf("\n转置后:\n");
	printTSMatrix(B);
	
	return 0;
}
