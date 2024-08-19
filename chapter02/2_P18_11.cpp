#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50


struct SqList{
	int data[Max];
	int length;
};

void find_mid(SqList s1, SqList s2){
	int j = 0, k = 0;
	for(int i = 0; i < (s1.length + s2.length) / 2; i++){
		if(s1.data[j] <= s2.data[k]){
			if(i == s1.length - 1){
				printf("中位数：%d", s1.data[j]);
			}
			j++;
		}
		else{
			if(i == s1.length - 1){
				printf("中位数：%d", s2.data[k]);
			}
			k++;
		}
	}
}

int main(){
	
	SqList a = {{8, 13, 15, 17, 19}, 5};
	SqList b = {{2, 4, 6, 7, 9, 10}, 6};
	
	find_mid(a, b);
	
	return 0;
}
