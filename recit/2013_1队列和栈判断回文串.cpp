#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define Max 20

typedef struct{
	char data[Max];
	int top;
}Stack;

void InitStack(Stack &s){
	s.top = -1;
}

bool isEmpty(Stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

bool isFull(Stack s){
	if(s.top == Max - 1){
		return true;
	}
	return false;
}

void Push(Stack &s, char value){
	if(isFull(s)){
		printf("Õ»Âú"); 
		return; 
	}
	s.data[++s.top] = value;
	return;
}

void Pop(Stack &s, char &value){
	if(isEmpty(s)){
		printf("Õ»¿Õ!");
		return;
	}
	value = s.data[s.top--];
	return;
}

typedef struct{
	char data[Max]; 
	int front;
	int rear;
	int tag;
}Queue;

void InitQueue(Queue &q){
	q.front = q.rear = 0;
}

bool isEmptyQueue(Queue q){
	if(q.front == q.rear && q.tag == 0){
		return true;
	}
	return false;
}

bool isFullQueue(Queue q){
	if(q.front == q.rear && q.tag == 1){
		return true;
	}
	return false;
} 

void EnQueue(Queue &q, char ch){
	if(isFullQueue(q)){
		return;
	}
	q.data[q.rear] = ch;
	q.rear = (q.rear + 1) % Max;
	q.tag = 1;
}

void DeQueue(Queue &q, char &ch){
	if(isEmptyQueue(q)){
		return;
	}
	ch = q.data[q.front];
	q.front = (q.front + 1) % Max;
	q.tag = 0;
}

bool Symmetry(){
	Stack s;
	Queue q;
	InitStack(s);
	InitQueue(q);
	
	char ch;
	ch = getchar();
	while(ch != '#'){
		Push(s, ch);
		EnQueue(q, ch);
		ch = getchar();
	}
	char ch1, ch2;
	// Õ» ·Ç¿Õ 
	while(!isEmpty(s)){
		Pop(s, ch1);
		DeQueue(q, ch2);
		printf("ch1 = %c, ch2 = %c\n", ch1, ch2);
		if(ch1 != ch2){
			return false;
		}
	}
	return true;
} 

int main(){
	
	// 	CHINAANIHC#
	if(Symmetry()){
		printf("yes");
	}
	else{
		printf("no");
	}
	return 0;
}
