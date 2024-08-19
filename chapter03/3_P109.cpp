#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define Max 50 

typedef struct {
	int data[Max];
	int top;
}stack;

// 判断栈空 
bool isEmpty(stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

// 判断栈满 
bool isFull(stack s){
	if(s.top == Max-1){
		return true;
	}
	return false;
}

bool PushStack(stack &s1, stack &s2, int x){
	if(isFull(s1)){
		return false;
	}
	s1.data[++s1.top] = x;
	printf("%d	", s1.data[s1.top]);
	
	// 第一个元素 需要特殊处理 
	if(s2.top == -1){
		s2.data[++s2.top] = x;
		printf("%d	", s2.data[s2.top]);
		printf("\n");
		return true;
	}
	
	int temp = s2.data[s2.top];
	s2.data[++s2.top] = x > temp ? temp : x;
	printf("%d	", s2.data[s2.top]);
	
	printf("\n");
	return true;
}

// 出栈 
bool PopStack(stack &s1, stack &s2, int &x1, int &x2){
	if(isEmpty(s1)){
		printf("栈为空！！！\n");
		return false;
	}
	x1 = s1.data[s1.top--];
	x2 = s2.data[s2.top--];
	return true;
}

int show(stack s1, stack s2){
	int top1 = s1.top;
	if(top1 != -1){
		while(top1 != -1){
			printf("%d	%d", s1.data[top1], s2.data[top1]);
			printf("\n");
			top1--;
		}
	}
	else{
		printf("栈为空！！！"); 
	}
	
}

int a[6] = {4, 6, 3, 6, 1, 9};

int main(){
	
	stack s1, s2;
	s1.top = -1;
	s2.top = -1;
	
	for(int i = 0; i < 6; i++){
		PushStack(s1, s2, a[i]);
	}
	
	printf("\n");
	
	show(s1, s2);
	
	printf("\n");
	
	int x1, x2;
	
	for(int i = s1.top; i > -1; i--){
		PopStack(s1, s2, x1, x2);
		printf("%d	%d", x1, x2);
		printf("\n");
	}
	
	return 0;
}
