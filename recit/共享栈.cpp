#include<stdio.h>
#include<stdlib.h>

#define Max 20

using namespace std;

typedef struct{
	int data[Max];
	int top1, top2;
}Stack;

void InitStack(Stack &s){
	s.top1 = -1;
	s.top2 = Max;
}

bool isFull(Stack s){
	if(s.top1 + 1 == s.top2){
		return true;
	}
	return false;
}

bool isEmptyStack(Stack s, int num){
	if(num == 1 && s.top1 == -1){
		return true;
	}
	else if(num == 2 && s.top2 == Max){
		return true;
	}
	return false;
}

void Push(Stack &s, int num, int value){
	if(isFull(s)){
		printf("Õ»Âú£¡");
		return;
	}
	
	if(num == 1){
		s.data[++s.top1] = value;
	}
	else{
		s.data[--s.top2] = value;
	}
	return;
}

void Pop(Stack &s, int num, int &value){
	if(isEmptyStack(s, num)){
		printf("%d Õ»¿Õ£¡");
		return;
	}
	
	if(num == 1){
		value = s.data[s.top1--];
	}
	else{
		value = s.data[s.top2++];
	}
}

int main(){
	
	Stack s;
	InitStack(s);
	int num;
	
	for(int i = 0; i < 18; i++){
		if(i % 2 == 0){
			Push(s, 1, i);
		}
		else{
			Push(s, 2, i);
		}
	}
	
	for(int i = 0; i < Max; i++){
		printf("%d	", s.data[i]);
	}
	
	return 0;
} 
