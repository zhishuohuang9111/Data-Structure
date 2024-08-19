#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define Max 50 

typedef struct {
	int data[Max];
	// 注意写法：两个栈顶指针 
	int top[2];
}stack1;

stack1 s; 
// 参数 i：表示要入栈号 x：表示待压入元素 
bool push(int i, int x){
	if(i != 0 && i != 1){
		printf("无栈！");
		return false;
	}
	
	if(s.top[1] - s.top[0] == 1){
		printf("栈满！");
		return false;
	}
	
	if(i == 0){
		// 0号栈：先 top指针自增，再赋值 
		s.data[++s.top[0]] = x;
	}
	else{
		// 1号栈：先 top指针自减，再赋值 
		s.data[--s.top[1]] = x;
	}
	
	return true;
}

bool pop(int i, int &x){
	if(i != 0 && i != 1){
		printf("无栈！");
		return false;
	}
	
	if(i == 0){
		if(s.top[0] == -1){
			printf("0号栈空！");
			return false;
		}
		else{
			// 先赋值，再 栈顶指针自减 
			x = s.data[s.top[0]--];
			return true;
		}
	}
	else{
		if(s.top[1] == Max){
			printf("1号栈空！");
			return false;
		}
		else{
			// 先赋值，再 栈顶指针自减 
			x = s.data[s.top[0]++];
			return true;
		}
	}
}

int main(){
	s.top[0] = -1;
	s.top[1] = Max;
	
	if(push(0, 5)){
		printf("0号栈入栈成功！");
	}
	
	int x;
	
	if(pop(0, x)){
		printf("%d\n", x);
	}
	
	if(pop(0, x)){
		printf("%d", x);
	}
	
	return 0;
}
