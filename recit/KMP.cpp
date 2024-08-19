#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define Max 10

using namespace std;

/*
			S[0]、T[0]：0号单元存储字符串长度 
*/ 

// 字符串下标从 1 开始
void Next(char T[], int next[]){
    // next数组 第一个 默认置为 0 
    next[1] = 0;
	// j：代表前缀 
    int j = 0;
    // i：代表后缀 
    int i = 1;
    
    while(i < T[0]){
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            // next[i] 存放的是 i-1的 最大前后 
            next[i] = j;
            // next[++i] = ++j; // 三条语句写为一条 
        }
		else{
			// 当前字符不相等，回溯到已经找到的最大长度前后子串 
            j = next[j];
        }
    }
}

void NextVel(char T[],int nextvel[]){
	nextvel[1] = 0;
	
    int i = 1;
    int j = 0;
    while(i < T[0]){
        if(j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if(T[i] != T[j]){
            	nextvel[i] = j;
			}
			else{
				nextvel[i] = nextvel[j];
			}
        }
		else{
            j = nextvel[j];
        }
    }
}

void printNext(int next[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d	", next[i]);
	}
	printf("\n");
}

void printNextval(int nextval[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d	", nextval[i]);
	}
	printf("\n");
}

int KMP(char S[], char T[], int pos){
	int i = pos;
	int j = 1;
	
	int next[Max];
	Next(T, next);
	// printNext(next, 8); 
	while(i <= S[0] && j <= T[0]){
		// j == 0：模式串 回溯到最开始
		// S[i] == T[j]：当前匹配的字符相等 
		if(j == 0 || S[i] == T[j]){
			i++;
			j++;
		}
		// 当前匹配的字符不相等，j 进行回溯，找到最大已经匹配的子串  
		else{
			j = next[j];
		}
	}
	if(j > T[0]){
		// 匹配成功 
		printf("匹配成功，匹配下标为：%d\n", i - T[0]);
		return i - T[0];
	}
	else{
		printf("匹配失败！！！"); 
		return 0;
	}
}

// 求当前字符 前后子串最大长度 
void MaxL(int T[], int maxl[]){}

int main(){
	char S[18] = {17, 'a', 'c', 'a', 'b', 'a', 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'c', 'a', 'a', 'b', 'c'};
	char T[9] = {8, 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'c'}; 
	
	KMP(S, T, 1);
	
	int next[Max];
	int nextval[Max];
	
	Next(T, next);
	NextVel(T, nextval);
	printNext(next, 8);
	printNextval(nextval, 8);
	/*
		j		1	2	3	4	5	6	7	8    
	 模式串     a   b   a   a   b   c   a   c
	  maxl		0   0   1   1   2   0   1   0
	  next      0   1   1   2   2   3   1   2
	  nextval   0   1   0   2   1   3   0   2 
	  
	  next[1] = 0；(初始化） 
	  next[i] = maxl[i-1] + 1	(i > 1)
	  next[i]：当 i 失效时，T串从next[i]开始比较
	  
	  若 maxl[i] != next[i]：nextval[i] = next[i]
	  若 maxl[i] == next[i]：nextval[i] = next[ next[i] ] 
	   
	*/
	
	
	return 0;
}
