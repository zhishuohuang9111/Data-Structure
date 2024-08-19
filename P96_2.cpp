#include<stdio.h>
#include <stdlib.h>

#define Max 10

struct stack{
	char data[Max];
	int top;
};

bool isEmpty(stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

bool isFull(stack s){
	if(s.top == Max - 1){
		return true;
	}
	return false;
}

bool Push(stack &s, char x){
	if(isFull(s)){
		printf("栈满！！！");
		return false;
	}
	s.data[s.top++] = x;
	return true;
}

bool Pop(stack &s, char &x){
	if(isEmpty(s)){
		printf("栈空！！！");
		return false;
	}
	else{
		x = s.data[s.top--]; 
	}
}

void Sort(char str[]){
	stack s;
	s.top = -1;
	char ans[Max + 1];
	int j = 0;
	for(int i = 0; i < Max; i++){
		if(str[i] == 'H'){
			Push(s, str[i]);
		}
		else{
			ans[j++] = str[i];
		}
	}
	
	char c; // 用来接收返回值 
	while(!isEmpty(s)){
		Pop(s, c);
		ans[j++] = c; 
	}
	
	for(int i = 0; i < Max; i++){
		printf("%c", ans[i]);
	}
}


int main(){
	char str[Max] = "HSHSSSHH";
	Sort(str);
	return 0;
}



