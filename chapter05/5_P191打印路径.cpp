#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 20

typedef struct treenode{
	int weight;
	struct treenode* lchild, *rchild;
	int tag;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode*) malloc(sizeof(treenode));
		t->weight = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

typedef struct{
	treenode* data[Max];
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

bool Push(Stack &s, treenode* x){
	if(isFull(s)){
		printf("Õ»Âú£¡£¡£¡");
		return false;
	}
	s.data[++s.top] = x;
	return true;
}

bool Pop(Stack &s, treenode* &x){
	if(isEmpty(s)){
		printf("Õ»¿Õ£¡£¡£¡");
		return false;
	}
	x = s.data[s.top--];
	return true;
}

void show(tree t, int data){
	if(t == NULL){
		return;
	}
	Stack s;
	InitStack(s);
	treenode* p = t;
	int sum = 0;
	while(!isEmpty(s) || p != NULL){
		while(p){
			Push(s, p);
			p->tag = 0;
			sum += p->weight - '0';
			p = p->lchild;
		}
		
		if(sum == data && t->rchild == NULL){
			for(int i = 0; i <= s.top; i++){
				printf("%d	", s.data[i]->weight);
			}
		}
	}
}

void print(tree t, int data){
	if(t){
		if(t->weight - '0' == data && t->lchild == NULL && t->rchild == NULL){
			printf("%d	", t->weight);
		}
	}
}

int main(){
	
	return 0;
}
