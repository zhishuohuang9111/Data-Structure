#include<stdio.h>
#include<stdlib.h>

using namespace std;

void PreToPost(char pre[], int l1, int h1, char post[], int l2, int h2){
	int half; // 存左右子树临界值
	
	if(l1 <= h1){ // 递归条件：开端 <= 末尾 
		// 将 当前根结点 所在的前序位置 放入 后序最后位置 
		post[h2] = pre[l1];
		// 将序列分为 左、右序列 
		half = (h1 - l1) / 2; // 末尾 - 开端 
		// 左子树递归 
		PreToPost(pre, l1+1, l1+half, post, l2, l2+half-1);
		// 右子树递归
		PreToPost(pre, l1+half+1, h1, post, l2+half, h2-1); 
	} 
}

int main(){
	// 满二叉树 结点总个数为 奇数 
	char pre[7]= {'A', 'B', 'D', 'E', 'C', 'F', 'G'}; 
	char post[7];
	
	PreToPost(pre, 0, 6, post, 0, 6);
	
	for(int i = 0; i < 7; i++){
		printf("%c	", post[i]);
	}
	return 0;
} 
