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
		if(a[j] < 0){
			swap(a[i], a[j]);
			i++;
			j++;
		}
		else if(a[j] == 0){
			j++;
		}
		else{
			swap(a[j], a[k]);
			k--;
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
