#include<stdio.h>
#include<stdlib.h>

/*
			堆调整：在一颗完全二叉树中，根节点的左右子树均是堆 
			堆调整之前，首先要 保证其左、右子树都是堆 
*/	 

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// k：要筛选结点的编号
// end：堆中最后一个结点的编号 
void sift(int r[], int k, int end){
	int i = k; // 根节点 
	int j = 2 * k; // 左孩子节点 
	while(j <= end){ // j <= end：防止数组下标越界 
		if(j < end && r[j] < r[j + 1]){
			// j < end：说明 当前该节点 有右孩子
			// r[j] < r[j + 1]：左子树值 < 右子树值 
			j++; // j 指向 左右子树值较大者：右子树 
		}
		// 根结点值 < 孩子结点值 
		if(r[i] < r[j]){
			swap(r[i], r[j]);
		}
		// 向下进行调整 
		i = j;
		j = 2 * i;
	}
}

void Find(int a[], int n, int b[], int m){
	int k;
	// 建立 大根堆：从下往上进行调整 
	for(k = n / 2; k >= 1; k--){
		sift(a, k, n);
	}
	
	// 调整 （向下调整） 
	for(k = 1; k <= m; k++){
		// 将 每次寻找到的最大值 存储在 b[i] 中 
		b[k] = a[1];  
		// 将 当前的堆顶 与 当前无序区的最后一个 进行交换
		swap(a[1], a[n - k + 1]);
		// 1：需要调整的根结点
		// n - k：需要调整的元素个数 
		sift(a, 1, n - k);
	}
} 

int main(){
	// a[0] 未使用 
	int a[8001];
	
	for(int i = 1; i <= 8000; i++){
		a[i] = 8001 - i;
	}
	
	int b[11]; 

	Find(a, 8000, b, 10);
	
	printf("最大的前 10 个数为：");
	for(int i = 1; i <= 10; i++){
		printf("%d	", b[i]);
	}
	
	return 0;
}
