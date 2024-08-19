#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50


struct SqList{
	int data[Max];
	int length;
};

bool merge(SqList a, SqList b, SqList &c){
	if(c.length < a.length + b.length){
		return false; 
	}
	int i = 0, j = 0, k = 0;
	while(i < a.length && j < b.length){
		if(a.data[i] <= b.data[j]){
			c.data[k] = a.data[i];
			k++, i++;
		}
		else{
			c.data[k] = b.data[j];
			k++, j++;
		}
	}
	
	while(i < a.length){
		c.data[k] = a.data[i];
		k++, i++;
	}
	
	while(j < b.length){
		c.data[k] = b.data[j];
		k++, j++; 
	}
	
	return true;
}

void show(SqList s){
	if(s.length == 0){
		printf("线性表为空");
		return;
	}
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.data[i]);
	}
	printf("\n"); 
}

int main(){
	
	SqList a = {{1, 3, 5, 7, 9}, 5};
	SqList b = {{2, 4, 10}, 3};
	SqList c;
	c.length = 8;
	
	show(a);
	show(b);
	
	if(!merge(a, b, c)){
		printf("error");
	}
	else{
		show(c);
	}
	
	return 0;
}
