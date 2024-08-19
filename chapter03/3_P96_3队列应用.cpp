#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 10

typedef struct{
	int data[Max];
	int front, rear, tag;
}Queue;

void InitQueue(Queue &q){
	q.front = 0;
	q.rear = 0;
	q.tag = 0;
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

bool EnQueue(Queue &q, int x){
	if(isFullQueue(q)){
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % Max;
	q.tag = 1;
	return true;
}

bool DeQueue(Queue &q, int &x){
	if(isEmptyQueue(q)){
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % Max;
	q.tag = 0;
	return true;
}

void printfQueue(Queue q){
	while(!isEmptyQueue(q)){
		printf("%d	", q.data[q.front]);
		q.front = (q.front + 1) % Max;
		q.tag = 0;
	}
	printf("\n");
}

void car(){
	Queue q, q1, q2;
	InitQueue(q);
	InitQueue(q1);
	InitQueue(q2);
	
	for(int i = 0; i < Max; i++){
		EnQueue(q1, 1);
		EnQueue(q2, 2);
	}
	// i：客车数，  j：总车数 
	int i = 0, j = 0, x;
	
	while(j < 10){
		if(!isEmptyQueue(q1) && i < 4){
			DeQueue(q1, x);
			EnQueue(q, x);
			i++;
			j++;
		}
		else if(i == 4 && !isEmptyQueue(q2)){
			DeQueue(q2, x);
			EnQueue(q, x);
			j++;
			i = 0;
		}
		else{
			while(j < 10 && i < 4 && !isEmptyQueue(q2)){
				DeQueue(q2, x);
				EnQueue(q, x);
				i++;
				j++;
			}
			i = 0; 
		}
		if(isEmptyQueue(q1) && isEmptyQueue(q2)){
			j = 11;
		}
	}
	printf("客车队列：\n"); 
	printfQueue(q1);
	printf("货车队列：\n");
	printfQueue(q2);
	
	printf("目标队列：\n");
	printfQueue(q);
}

int main(){
	car();
	return 0;
}
