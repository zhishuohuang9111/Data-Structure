#include<stdio.h>

int main(){
	
	// *(a + i) + j       等价于 a[i][j] 的地址 
	// *(*(a + i) + j)   等价于 a[i][j]
	
	int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	
	int (*p)[4];
	p = a;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			// 两种访问方式都可以 
			printf("%d	", *( *(p + i) + j ) );
			// printf("%d	", p[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}
