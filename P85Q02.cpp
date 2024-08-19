#include<stdio.h>
#include <stdlib.h>

#define Max 10

typedef struct{
	int data[Max];
	int top;
}stack;

typedef struct{
	int data[Max];
	int r,f,tag;
}queue;

bool enterqueue(queue &s, int x){
	if(s.f == s.r && s.tag == 1){
		printf("队满，进队失败！！！");
		return false;
	}
	s.data[s.r] = x;
	s.r = (s.r + 1) % Max;
	
	s.tag = 1; // 入队，令tag值 1 
	return true;
	
}

int outqueue(queue &s, int &x){
	if(s.f == s.r && s.tag == 0){
		printf("队空，出队失败！！！");
		return 0;
	}
	
	x = s.data[s.f];
	s.f = (s.f + 1) % Max;
	s.tag = 0; // 出队，令tag值 0
	return 1; 
}

bool push(stack &s, int x){
	if(s.top == Max - 1){
		printf("栈满！！！");
		return false;
	}
	s.data[++s.top] = x;
	return true;
}

int pop(stack &s, int &x){
	if(s.top == -1){
		printf("栈空！！！");
		return 0;
	}
	x = s.data[s.top--];
	return 1;
}

void displayQueue(queue s){
	for(int i = 0; i < Max; i++){
		printf("%d	", s.data[s.f]);
		s.f = (s.f + 1) % Max;
	}
}

int main(){
	
	queue s1;
	stack s2;
	s1.f = 0;
	s1.r = 0;
	s1.tag = 0;
	
	s2.top = -1;
	
	for(int i = 0; i < Max; i++){
		enterqueue(s1, i + 1);
	}
	
	displayQueue(s1);
	
	int x = 0; 
	
	while(!(s1.f == s1.r && s1.tag == 0)){ // 判断队非空
		outqueue(s1, x);
		push(s2, x);
	}
	
	while(s2.top != -1){
		pop(s2, x);
		enterqueue(s1, x);
	}
	printf("\n");
	displayQueue(s1);
	
}
