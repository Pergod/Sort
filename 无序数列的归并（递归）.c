#include<stdio.h>
#include<stdlib.h>
#define M 20
void Merge_Sort(int *,int);//统一函数接口 
void Msort(int *,int *,int,int);//递归 
void Merge(int *,int *,int,int,int);//有序子列的归并
int main()
{
	int a[M]={4,54,3,523,6,8,98,45,76,54,53,74,26,456,16,8764,424,63,2,10};
	int i;
	for(i=0;i<M;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	Merge_Sort(a,M);
	for(i=0;i<M;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
//统一函数接口 
void Merge_Sort(int *A,int n)
{
	int *TmpA=(int *)malloc(n*sizeof(int));
	if(TmpA!=NULL)
	{
		Msort(A,TmpA,0,n-1);
		free(TmpA);
	}
	else
	{
		printf("No extra space");
	}
}
//递归 
void Msort(int *A,int *TmpA,int L,int RightEnd)
{
	int Center;
	if(L<RightEnd)
	{
		Center=(L+RightEnd)/2;
		Msort(A,TmpA,L,Center);/* 递归解决左边 */ 
		Msort(A,TmpA,Center+1,RightEnd);/* 递归解决右边 */ 
		Merge(A,TmpA,L,Center+1,RightEnd);/* 合并两段有序序列 */
	}
}
//有序子列的归并 
void Merge(int *a,int *b,int L,int R,int RightEnd)//L左边起始位置，R右边起始位置，RE右边终点位置 
{
	int i;
	int LE=R-1;
	int Tmp=L;//存放数组的起始位置 
	int NumE=RightEnd-L+1;
	while(L<=LE&&R<=RightEnd)
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
	while(R<=RightEnd)//直接复制右边剩下的 
	{
		b[Tmp++]=a[R++];
	}
	for(i=0;i<NumE;i++,RightEnd--)//从末尾导入 
	{
		a[RightEnd]=b[RightEnd];
	}
}
