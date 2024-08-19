#include<stdio.h>
#include<stdlib.h>
// 队列最大容量 
#define Max 10

using namespace std;

typedef struct{
	int data[Max];
	// 头指针 
	int front;
	// 队列中 元素个数 
	int count;
}Qu;

void InitQueue(Qu &q){
	q.front = 0;
	q.count = 0;
} 

void EnQueue(Qu &q, int value){
	if(q.count == Max){
		printf("队满");
		return;
	}
	// 入队 
	q.data[(q.front + q.count) % Max] = value;
	// 队中元素 + 1 
	q.count++;
	return;	
}

void DeQueue(Qu &q, int &value){
	if(q.count == 0){
		printf("队空");
		return;
	}
	// 出队 
	value = q.data[q.front];
	// 队中元素 - 1 
	q.count--;
	// 头指针后移 
	q.front = (q.front + 1) % Max;
}

int main(){
	
	Qu q;
	InitQueue(q);
	
	return 0;
} 
