#include<stdio.h>

#define N 6

int main(){
	
	int a[N] = {2, 3, 4, 5, 6, 7};
	// p指针 指向 数组首地址 
	int *p = a;
	int key = 5;
	int index = 0;
	
	for(; p < a + N; p++){
		if(*p == key){
			index = p - a;
			break;
		}
	} 
	
	if(p == a + N){
		index = -1;
	}
	
	printf("%d	", index);
	
	for(int i = 0; i < N; i++){
		// *(a + i)；通过地址访问数组元素 
		printf("%d	", *(a + i));
	}
	
	return 0;
} 
