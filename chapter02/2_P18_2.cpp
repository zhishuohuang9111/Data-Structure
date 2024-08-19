#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	int a[Max] = {5, 3, 4, 1, 7, 2, 8, 9};
	int length = 8;
};

void reverse(SqList &s){
	int temp;
	// i < s.lenth / 2
	for(int i = 0; i < s.length / 2; i++){
		temp = s.a[i];
		s.a[i] = s.a[s.length - 1 - i];
		s.a[s.length - 1 - i] = temp;	 
	}
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
	reverse(s);
	show(s);
	
	return 0;
} 
