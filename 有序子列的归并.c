#include<stdio.h>
#define I 6
#define J 4
void Merge(int *a,int *b,int L,int R,int RE);
void MergeSort(int *,int *,int *,int ,int);//两个【有序】子列的合并
int main()
{
	int i,j;
	int A[I]={2,3,5,7,9,20};//两个【有序】数列！    
	int B[J]={1,4,6,8};
	int T[I+J];
	int R[I+J];
	MergeSort(A,B,T,I,J);//两个【有序】子列的合并
	for(i=0;i<I+J;i++)
	{
		printf("%d ",T[i]);
	}
	printf("\n");
	Merge(T,R,0,6,I+J-1);//归并排序 
	for(i=0;i<I+J;i++)
	{
		printf("%d ",T[i]);
	}
}
void MergeSort(int *a,int *b,int *T,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		T[i]=a[i];
	}
	for(j=0;j<n;j++,i++)
	{
		T[i]=b[j];
	}
}
void Merge(int *a,int *b,int L,int R,int RE)//L左边起始位置，R右边起始位置，RE右边终点位置 
{
	int i;
	int LE=R-1;
	int Tmp=L;//存放数组的起始位置 
	int NumE=RE-L+1;
	while(L<=LE&&R<=RE)
	{
		if(a[L]<=a[R])
		{
			b[Tmp++]=a[L++];
		}
		else
		{
			b[Tmp++]=a[R++];
		}
	}
	while(L<=LE)//直接复制左边剩下的 
	{
		b[Tmp++]=a[L++];
	}
	while(R<=RE)//直接复制右边剩下的 
	{
		b[Tmp++]=a[R++];
	}
	for(i=0;i<NumE;i++,RE--)//从末尾导入 
	{
		a[RE]=b[RE];
	}
}
