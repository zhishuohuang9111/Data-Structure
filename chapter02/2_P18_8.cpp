#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50


struct SqList{
	int data[Max] = {1, 2, 3, 4, 5, 6, 7};
	int length = 7;
};

void show(SqList s){
	if(s.length == 0){
		printf("线性表为空");
		return;
	}
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.data[i]);
	}
	printf("\n"); 
}

void reverse(SqList &s, int m, int n){
	int temp;
	for(int i = m; i < (m + n)/2; i++){
		temp = s.data[i];
		s.data[i] = s.data[m + n - i - 1];
		s.data[m + n - i - 1] = temp;
	}
	show(s);
}

// 注意传递的参数 
void change(SqList &s, int m, int n){
	printf("整个逆置：\n");
	reverse(s, 0, m + n);
	printf("前 %d 个逆置：\n", n);
	reverse(s, 0, n);
	printf("后 %d 个逆置：\n", m);
	reverse(s, n, n + m);
}


int main(){
	
	SqList s;
	
	change(s, 3, 4);
	
	return 0;
} 
