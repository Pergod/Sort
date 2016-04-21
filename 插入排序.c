#include<stdio.h>
#define N 12
void InsertSort(int *,int );
int main()
{
	int num[N]={42,53,3,5,1,94,2,0,51,54,90,22}; 
	int i;
//	for(i=0;i<N;i++)
//	{
//		printf("%d ",num[i]);
//	}
//	printf("\n");
	InsertSort(num,N);
//	for(i=0;i<N;i++)
//	{
//		printf("%d ",num[i]);
//	}
}
void InsertSort(int *num,int n)
{
	int p,i;
	int temp;
	for(p=1;p<N;p++)
	{
		temp=num[p];//摸下一张牌 
		for(i=p;i>0&&num[i-1]>temp;i--)
		{
			num[i]=num[i-1];//移出空位 
		}
		num[i]=temp;//新牌落位 
		for(i=0;i<N;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
	}
}
