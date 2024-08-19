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
 
// 三元组 快速转置
// 时间复杂度：O(矩阵 A 的列数 + 矩阵 A 的非零元的个数) 
void FastTransposeSMatrix(TSMatrix A, TSMatrix &B){
	
	int i, position, col;
	// 矩阵 A m行、n列  转置为 矩阵 B n行、m列 
	B.m = A.n;
	B.n = A.m;
	B.len = A.len;
	// 非零元个数 不为 0 
	if(A.len != 0){ 
		// num数组：记录 矩阵 A 中 每一列非零元个数 
		int num[Max];
		// cpot数组：记录 矩阵 B 中 每一列首非零元的下标 
		int cpot[Max];
		// num 数组 初始化 
		for(i = 1; i <= A.n; i++){
			num[i] = 0;
		}
		// num[2] = 5：表示 矩阵 A 中，第 2 列 有 5 个非零元 
		for(i = 1; i <= A.len; i++){
			++num[A.data[i].col]; 
		}
		
		// 第 1 个非零元 在 三元组数组中的下标为 1 
		cpot[1] = 1;
		for(col = 2; col <= A.n; col++){
			// cpot[5] = cpot[4] + num[4]; 
			// 第五列的第一个非零元的下标 = 第四列的第一个非零元下标 + 第四列非零元个数 
			cpot[col] = cpot[col - 1] + num[col - 1];	
		}
		
		// i 遍历的是 三元组个数 
		for(i = 1; i <= A.len; i++){
			// 获取 当前元素的列标 
			col = A.data[i].col;
			// 获取 当前列 首非零元的下标 
			position = cpot[col];
			
			//  当前列 首非零元 进行赋值 
			B.data[position].row = A.data[i].col;
			B.data[position].col = A.data[i].row;
			B.data[position].value = A.data[i].value;
			// 更改 当前列的 首非零元的 下标 
			++cpot[col]; 
		}
	} 
}

// 三元组输入 
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

// 打印三元组 
void printTSMatrix(TSMatrix T){
	for(int i = 1; i <= T.len; ++i ){
		printf("%d	%d	%d\n", T.data[i].row, T.data[i].col, T.data[i].value);
	}
}
 
int main(){

	TSMatrix A, B;
	inputTSMatrix(A);

	FastTransposeSMatrix(A, B);

	printf("\n原始三元组为:\n");
	printTSMatrix(A);
	
	printf("\n转置后:\n");
	printTSMatrix(B);
	
	return 0;
}
