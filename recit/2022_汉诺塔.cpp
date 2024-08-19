#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*
			时间复杂度：2的 n 次方 - 1 
*/
// count：全局变量，对搬动次数计数 
int count = 0;

void move(char c1, int n, char c2){
	printf("第 %d 次，将 %d 号盘子从 %c 移动到 %c\n", ++count, n, c1, c2);
} 

// 最终目的：n 个盘子，从 x 通过 y 移动到 z 
void Hanoi(int n, char x, char y, char z){
	if(n == 1){
		move(x, 1, z);
	}
	else{
		// n-1 个盘子，从 x 通过 z 暂时 移动到 y 
		Hanoi(n-1, x, z, y);
		// 将 第 n 个盘子 从 x 移动到最终目的 z 
		move(x, n, z);
		// n-1 个盘子，从 y 通过 x 移动到 z
		Hanoi(n-1, y, x, z);
	}
}

int main(){
	
	int n;
	printf("Please input n:");
	scanf("%d", &n);
	
	Hanoi(n, 'X', 'Y', 'Z');
	
	return 0;
} 
