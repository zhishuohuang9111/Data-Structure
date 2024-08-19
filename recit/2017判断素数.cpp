
#include<stdio.h>
#include<stdlib.h> 
#include <math.h>

using namespace std;

void Prime(){
	int i, j, n;
    printf("Please input numbers: ");
    scanf("%d",&n);
    j = (int) sqrt(n);
    printf("j = %d\n", j);
    for(i = 2; i <= j; i++){
        if(n %i == 0){
            break;
        }
    }
    if(j < i){
        printf("%d is prime!\n",n);
    }
    else{
    	printf("%d is not prime!\n",n);
    }
}

int main(){
	
	Prime();
	
	return 0;
}
