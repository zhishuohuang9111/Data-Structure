#include<stdio.h>
#include <stdlib.h>

#define Max 10
typedef struct{
	int data[Max];
	int top; // 不能赋值 （Java可以，静态代码块） 
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

// 压栈 
bool pushStack(stack &s, int x){
	if(isFull(s)){
		return false;
	}
	s.data[++s.top] = x;
	// printf("%d \n", s.data[s.top]);
	return true;
}

// 出栈 
bool popStack(stack &s, int &x){
	if(isEmpty(s)){
		printf("栈为空！！！\n");
		return false;
	}
	x = s.data[s.top--];
	return 1;
}

// 输出栈 
void display(stack &s){
	int top1 = s.top;
	if(top1 != -1){
		while(top1 != -1){
		printf("%d	", s.data[top1--]);
		}
	}
	else{
		printf("栈为空！！！"); 
	}
	
}

// 入队 
int enterQueue(stack &s1, stack &s2, int x){
	if(!isFull(s1)){
		pushStack(s1, x);
		return 1;
	}
	else if(isFull(s1) && isEmpty(s2)){
		printf("队满，无法插入！！！");
		return 0; 
	}
    else if(isFull(s1) && !isEmpty(s2)){
    	while(!isEmpty(s1)){
    		popStack(s1, x);
    		pushStack(s2, x);
		}
		pushStack(s1, x);
	}
	
	return 1; 
}

// 出队 
int deleteQueue(stack &s1, stack &s2, int &x){
	if(!isEmpty(s2)){
		popStack(s2, x);
	}
	else if(isEmpty(s1)){
		printf("队列为空");
	}
	
	else{
		while(!isEmpty(s1)){
			popStack(s1, x);
			pushStack(s2, x);
		}
		
		popStack(s2, x);
	}
}

// 判断 队列是否为空 
bool isEmptyQueue(stack s1, stack s2){
	if(isEmpty(s1) && isEmpty(s2)){
		return true;
	}
	return false;
}

int main(void){
	
	stack s1, s2;
	s1.top = -1;
	s2.top = -1;
	
	for(int i = 0; i < Max; i++){
		pushStack(s1, i+1);
	}
	
	/*
	while(!isEmpty(s1)){
		printf("%d", s1.data[s1.top--]);
	}
	*/
	
	display(s1);
	printf("\n");
	// printf("%d", s1.top);
	int x = 0;
	int t = 100;
	while(!isEmptyQueue(s1, s2)){
		deleteQueue(s1, s2, x);
		printf("出队元素为：%d\n", x);
	}
	
	enterQueue(s1, s2, t);
	
	printf("输出栈 s1：");
	display(s1);
	
	deleteQueue(s1, s2, x);
	printf("出队元素为：%d\n", x);
	
	printf("输出栈 s2：");
	display(s2);
	
	
	return 0;
} 
