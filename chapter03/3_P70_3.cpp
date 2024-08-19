#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int n;

bool isok(char s[]){
	
	int i = 0;
	int count = 0;
	
	// 未到 字符数组尾 
	while(s[i] != '\0'){
		if(s[i] == 'I'){
			count++;
		}else{
			count--;
		}
		
		printf("%d \n", count);
		
		if(count < 0){
			return false;
		}
		i++;
	}
	// 入栈数 == 出栈数 
	if(count == 0){
		return true;
	}else{
		return false;
	}
	
	
	/*
	int j = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'I'){
			j++;
		}else{
			j--;
		}
		
		if(j < 0){
			return false;
		}
	}
	
	if(j == 0){
		return true;
	}else{
		return false;
	}
	*/

}

int main(){
	char s[9] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O', '\0'};
	// char s[9] = {'I', 'O', 'O', 'I', 'O', 'I', 'I', 'O', '\0'};
	n = 8;
	if(isok(s)){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
}
