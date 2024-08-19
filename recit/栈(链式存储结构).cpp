#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct{
	Node* top;
}Stack;

// 无头结点的链式栈 
void InitStack(Stack &s){
	s.top = NULL; 
}

void Push(Stack &s, int value){
	Node* x = (Node*) malloc(sizeof(Node));
	x->data = value;
	
	x->next = s.top;
	s.top = x;	
}

void Pop(Stack &s, int &value){
	if(s.top == NULL){
		printf("栈空！！！");
		return;
	}
	value = s.top->data;
	
	Node* p = s.top;
	s.top = s.top->next;
	free(p);
}

void dispStack(Stack s){
	while(s.top != NULL){
		printf("%d	", s.top->data);
		s.top = s.top->next;
	}
}

int main(){
	Stack s;
	InitStack(s);
	
	for(int i = 1; i <= 10; i++){
		Push(s, i);
	}
	dispStack(s);
	
	return 0;
}
