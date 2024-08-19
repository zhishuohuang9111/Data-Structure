#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	int a[Max] = {5, 3, 4, 1, 7, 2, 8, 9};
	int length = 8;
};

bool delete_ele(SqList &s, int &ele){
	if(s.length == 0){
		return false;
	}
	
	int min = 0;
	for(int i = i; i < s.length; i++){
		if(s.a[min] > s.a[i]){
			min = i;
		}
	}
	ele = s.a[min];
	s.a[min] = s.a[s.length - 1];
}

void show(SqList s){
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.a[i]);
	}
	printf("\n"); 
}

int main(){
	
	SqList s;
	int ele;
	
	printf("原先数组：");
	show(s);
	delete_ele(s, ele);
	printf("删后数组：");
	show(s);
	
	printf("min = %d", ele);
	
	return 0;
} 
