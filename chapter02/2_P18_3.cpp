#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	int a[Max] = {5, 3, 4, 3, 7, 3, 8, 3};
	int length = 8;
};

void delete_x(SqList &s, int x){
	int count = 0;
	
	for(int i = 0; i < s.length; i++){
		if(s.a[i] == x){
			count++;
		}
		else{
			s.a[i - count] = s.a[i];
		}
	}
	// 修改 线性表长度 
	s.length = s.length - count;
}

void show(SqList s){
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.a[i]);
	}
	printf("\n"); 
}

int main(){
	
	SqList s;
	
	show(s);
	
	delete_x(s, 3);
	
	show(s);
	
	return 0;
}
