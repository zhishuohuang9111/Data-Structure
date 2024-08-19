#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	int a[Max] = {5, 3, 4, 3, 7, 3, 8, 3};
	int length = 8;
};

bool delete_range(SqList &L, int s, int t){
	if(L.length == 0 || s >= t){
		return false;
	}
	
	int count = 0;

	for(int i = 0; i < L.length; i++){
		if(L.a[i] >= s && L.a[i] <= t){
			count++;
		}
		else{
			L.a[i - count] = L.a[i]; 
		}
	}
	
	if(count == 0){
		return false;
	}
	
	L.length = L.length - count;
}

void show(SqList s){
	if(s.length == 0){
		printf("线性表为空");
		return;
	}
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.a[i]);
	}
	printf("\n"); 
}

int main(){
	
	SqList L;
	
	show(L);
	if(!delete_range(L, 10, 14)){
		printf("error");
	}
	else{
		show(L);
	}
	
	return 0;
}
