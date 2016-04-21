#include<stdio.h>
#define M 8
void swap(int *,int *);
void ChoseSort(int *,int);
int main()
{
	int i;
	int min;
	int a[M]={6,3,5,7,0,4,1,2};
	ChoseSort(a,M);
	for(i=0;i<M;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}void ChoseSort(int *a,int m)
{
	int i,j;
	int min;
	int k=0;
	int flag;
	for(i=m-1;i>=0;i--)
	{
		min=a[k];
		for(j=k;j<m;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				flag=j;
			}
		}
		swap(&a[k],&a[flag]);
		k++;
	}
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
