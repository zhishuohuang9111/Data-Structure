#include<stdio.h>
#include<stdlib.h>

using namespace std;

void PreToIn(char pre[], int l1, int h1, char in[], int l2, int h2){
	int half; // 存左右子树临界值
	
	if(l1 <= h1){ // 递归条件：开端 <= 末尾 
		// 将 当前根结点 所在的前序位置 放入 后序最后位置 
		half = (h1 - l1) / 2; // 末尾 - 开端 
		printf("l1 = %d, h1 = %d, l2 = %d, h2 = %d, half = %d\n", l1, h1, l2, h2, half);
		// l2 + half：当前根节点 在中序序列中的下标 
		in[l2 + half] = pre[l1];
		printf("l2 + half = %d, in[l2 + half]= %c \n",l2 + half, in[l2 + half]);
		
		// 将序列分为 左、右序列 
		// 左子树递归 
		PreToIn(pre, l1+1, l1+half, in, l2, l2+half-1);
		printf("\n");
		// 右子树递归
		PreToIn(pre, l1+half+1, h1, in, l2+half+1, h2); 
	} 
}

int main(){
	// 满二叉树 结点总个数为 奇数            
	char pre[7]= {'A', 'B', 'D', 'E', 'C', 'F', 'G'}; 
	//       0    1    2    3    4    5    6
	// 中序：D    B    E    A    F    C    G 
	char in[7];
	
	PreToIn(pre, 0, 6, in, 0, 6);
	
	for(int i = 0; i < 7; i++){
		printf("%c	", in[i]);
	}
	return 0;
} 
