#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50


struct SqList{
	int data[Max];
	int length;
};

int find_middle(SqList L1, SqList L2){
	int s1 = 0, d1 = L1.length - 1, m1;
	int s2 = 0, d2 = L2.length - 1, m2;
	
	while(s1 != d1 || s2 != d2){
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if(L1.data[m1] == L2.data[m2]){
			return L1.data[m1];
		} 
		
		if(L1.data[m1] < L2.data[m2]){
			if((s1 + d1) % 2 == 0){
				s1 = m1;
				d2 = m2;
			}
			else{
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else{
			if((s2 + d2) % 2 == 0){
				d1 = m1;
				s2 = m2;
			}
			else{
				d1 = m1;
				s2 = m2 + 1;
			}
			
		}
	}
	
	return L1.data[s1] < L2.data[s2] ? L1.data[s1] : L2.data[s2];
}

int main(){
	
	SqList a = {{11, 13, 15, 17, 19}, 5};
	SqList b = {{2, 4, 6, 8, 20}, 5};
	
	int mid = find_middle(a, b);
	printf("mid = %d", mid);
	
	return 0;
}
