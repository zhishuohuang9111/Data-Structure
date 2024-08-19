#include<stdio.h>
#include<stdlib.h>

#define Max 20 

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// end：元素个数 
void HeapAdjust(int r[], int k, int end){
	int i = k; // 根节点 
	int j = 2 * k; // 左孩子节点 
	while(j <= end){
		// j < end：当前该节点 有右孩子
		// r[j] > r[j + 1]：左子树值 > 右子树值 
		if(j < end && r[j] > r[j + 1]){
			// j 指向 左右子树值较小者：右子树 
			j++; 
		}
		// 根结点值 > 孩子结点值 
		if(r[i] > r[j]){
			swap(r[i], r[j]);
		}
		// 向下进行调整 
		i = j;
		j = 2 * i;
	}
}

void HeapSort(int a[], int n, int b[], int num){
	int k;
	// 建立 大根堆 
	for(k = n / 2; k >= 1; k--){
		HeapAdjust(a, k, n);
	}
	// 调整 （向下调整） 
	for(k = 1; k <= num; k++){
		b[k] = a[1];
		// 将 当前的堆顶 与 当前无序区的最后一个 进行交换 
		swap(a[1], a[n - k + 1]);
		
		// 1：需要调整的根结点
		// n - k：需要调整的元素个数 	
		HeapAdjust(a, 1, n - k);
	}
} 

int main(){
	// a[0] 未使用 
	int a[7] = {0, 28, 25, 16, 36, 18, 32};
	int b[Max];
	int num;
	printf("请输入要找的最小数的个数：");
	scanf("%d", &num);
	
	for(int i = 1; i < 7; i++){
		printf("%d	", a[i]);
	}
	printf("\n");
	
	HeapSort(a, 6, b, num);
	
	for(int i = 1; i <= num; i++){
		printf("%d	", b[i]);
	}
	
	return 0;
}
