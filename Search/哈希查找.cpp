#include <stdio.h>
#include <stdlib.h>

#define dataType int
#define HashSize 12
#define Empty -32767

typedef struct
{
	dataType *value;
	int hashsize;
}HashMap; 

void IntiHashMap(HashMap *H)
{
	int i;
	
	H->hashsize=HashSize; //初始化哈希表长度 
	H->value=(dataType *)malloc(HashSize*sizeof(dataType)); //创建哈希表数组 
	for(i=0;i<HashSize;i++) //初始化哈希表为空 
	{
		H->value[i]=Empty;
	} 
}

//散列函数 (除留余数法) 
int Hash(dataType value) 
{
	return value%HashSize; //除数也可换成其他更合适的值，如小于HashSize的最大质数 
}

void Insert(HashMap *H,int data)
{
	int InsertAddress;
	
	InsertAddress=Hash(data);
	
	//发生冲突 
	while(H->value[InsertAddress]!=Empty)//线性探测 
	{
		InsertAddress=(InsertAddress+1)%HashSize;
	}
	H->value[InsertAddress]=data;
} 

int Search(HashMap *H,int SeartData)
{
	int HashAddress;
	
	HashAddress=Hash(SeartData);
	
	while(H->value[HashAddress]!=SeartData)
	{
		HashAddress=(HashAddress+1)%HashSize;
		
		if(H->value[HashAddress]==Empty||HashAddress==Hash(SeartData))
		{
			return -1;
		}
	}
	
	return HashAddress;
}


int main() 
{
	HashMap H;
	int i;
	int a[12]={12,67,56,16,25,37,22,29,15,47,48,34};

	IntiHashMap(&H); 
	
	for(i=0;i<HashSize;i++)
	{
		Insert(&H,a[i]);
	}
	
	printf("address   ");
	for(i=0;i<HashSize;i++)
	printf("%d\t",i);
	printf("\n\n");
	
	printf("a[i]     ");
	for(i=0;i<HashSize;i++)
	printf("%d\t",a[i]);
	printf("\n\n");
	
	printf("Hash[i]  ");
	for(i=0;i<HashSize;i++)
	printf("%d\t",H.value[i]);
	printf("\n\n");
	
	printf("a[6]的地址是:");
	printf(" %d",Search(&H,a[6]));
	
	return 0;
}

