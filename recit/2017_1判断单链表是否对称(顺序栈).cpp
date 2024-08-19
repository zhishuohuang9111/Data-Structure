#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 20

typedef struct lnode{
	char data;
	struct lnode* next;
}lnode, *linklist;

void buildlist(linklist &L, char a[], int n){
	L = (lnode*) malloc(sizeof(lnode));
	lnode *r = L, *p;
	for(int i = 0; i < n; i++){
		p = (lnode*) malloc(sizeof(lnode));
		p->data = a[i];
		
		r->next = p;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L){
	lnode* p = L->next;
	while(p){
		printf("%c	", p->data);
		p = p->next;
	}
	printf("\n");
}

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

bool Symmetry(linklist L, int n){
	Stack s;
	InitStack(s);
	lnode* p = L->next;
	char ch;
	for(int i = 0; i < n / 2; i++){
		Push(s, p->data);
		p = p->next;
	}
	// 结点个数为奇数，移过中心结点 
	if(n % 2 != 0){
		p = p->next;
	}
	printf("%c	", p->data);
	
	while(!isEmpty(s)){
		Pop(s, ch);
		printf("ch = %c, p->data = %c\n", ch, p->data);
		if(ch != p->data){
			return false;
		}
		p = p->next;
	}
	return true;
	
}

int main(){
	linklist L;
	char a[9] = {'A', 'B', 'C', 'E', 'D', 'D', 'C', 'B', 'A'};
	int n = 9;
	buildlist(L, a, n);
	disp(L);
	
	if(Symmetry(L, n)){
		printf("Yes!!!");
	}
	else{
		printf("No!!!");
	}
	
	return 0;
}
