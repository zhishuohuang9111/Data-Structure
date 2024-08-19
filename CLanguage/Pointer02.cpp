#include<stdio.h>

// 注意 swap 的写法 
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void process(int *arr, int num){
	int temp;
	int *p, *min, *max;
	p = max = min = arr;
	
	for(; p < arr + num; p++){
		if(*p < *min){
			min = p;
		}
		if(*p > *max){
			max = p;
		}
		// 最小数不是第一个数，交换 
		if(min != arr){
			swap(arr, min);
		}
		
		if(max != arr + num - 1){
			swap(arr + num - 1, max);
		}
	}
}

int main(){
	
	int a[9] = {19, 2, 3, 4, 5, 6, 7, 8, 14};
	
	process(a, 9);
	
	for(int i = 0; i < 9; i++){
		printf("%d	", a[i]);
	} 
	
	return 0;
} 
