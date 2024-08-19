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
		printf("栈满"); 
		return; 
	}
	s.data[++s.top] = value;
	return;
}

void Pop(Stack &s, char &value){
	if(isEmpty(s)){
		printf("栈空!");
		return;
	}
	value = s.data[s.top--];
	return;
}

typedef struct QuNode{
	int data;
	QuNode *next;
}QuNode, *QueuePtr;

typedef struct{
	// 头、尾指针类型 为 QuNOde 结构体类型 
	QueuePtr front;
	QueuePtr rear;
	int length; // 记录 队列长度 
}LinkQueue;

void InitQueue(LinkQueue &q){
	// 初始化就是构造一个只有一个头结点的空队
	// 将 头指针、尾指针 指向创建的头节点 
	q.front = q.rear = (QuNode*) malloc(sizeof(QuNode));
	// 将 头指针的后继 置为 NULL，不是 q.front = NULL（错误写法） 
	q.front->next = NULL;
	q.length = 0;
}

bool isEmptyQueue(LinkQueue q){
	if(q.length == 0){
		return true;
	}
	return false;
}

void EnQueue(LinkQueue &q, char ch){
	QueuePtr s = (QuNode*) malloc(sizeof(QuNode));
	s->data = ch;
	s->next = NULL;
	// 队尾指针 所指向节点的 后继 指向 s节点 
	q.rear->next = s;
	// 尾指针 后移 
	q.rear = q.rear->next;
	q.length++;
}

void DeQueue(LinkQueue &q, char &ch){
	if(isEmptyQueue(q)){ // q.front == q.rear
		printf("队空！");
		return;
	}
	// 不需要为 s 分配存储空间，s只是一个指针 
	QueuePtr s = q.front->next;
	ch = s->data;
	// 将 链表 链接起来（q.front 始终指向 队头节点） 
	q.front->next = s->next; 
	// 删除的是队列中的最后一个元素 
	if(q.rear == s){
		// 将 尾指针 指向 头节点（头指针 指向的位置） 
		q.rear = q.front;
	}
	free(s);
	q.length--;	
}

bool Symmetry(){
	Stack s;
	LinkQueue q;
	InitStack(s);
	InitQueue(q);
	
	char ch;
	ch = getchar();
	while(ch != '#'){
		Push(s, ch);
		EnQueue(q, ch);
		ch = getchar();
	}
	printf("队列长度：%d\n", q.length);
	char ch1, ch2;
	// isEmpty(s)：栈为空，返回true；栈非空：返回false 
	while(!isEmpty(s)){
		Pop(s, ch1);
		DeQueue(q, ch2);
		printf("ch1 = %c, ch2 = %c，队列长度：%d\n", ch1, ch2, q.length);
		if(ch1 != ch2){
			return false;
		}
	}
	return true;
} 

int main(){

	// 	CHINABANIHC#
	// ABCDEFGHI#
	if(Symmetry()){
		printf("	yes		");
	}
	else{
		printf("	no		");
	}
	return 0;
}
