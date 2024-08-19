#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void Swap(int a[], int n){
	int i = 0;
	for(int j = 0; j < n; j++){
		// 找到奇数结点，将其前移 
		if(a[j] % 2 != 0){
			swap(a[i], a[j]);
			i++;
		}
	}
}

int main(){
	
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// 1  3  5  7  9  6  4  8  2 10
 	
	Swap(a, 10);
	
	for(int i = 0; i < 10; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
