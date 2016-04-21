#include<stdio.h>
#include<stdlib.h>
#define M 20
void Merge_Sort(int *,int);//统一函数接口 
void Merge_Pass(int *,int *,int,int);//非递归 
void Merge1(int *,int *,int,int,int);//有序子列的归并  !省去最后一步将TMPA导入A 
int main()
{
	int a[M]={4,54,3,523,6,8,98,45,76,54,53,74,26,456,16,8764,424,63,2,10,};
	int i;
//	for(i=0;i<M;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	printf("\n");
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
	int length=1;
	int i;
	int *TmpA=(int *)malloc(n*sizeof(int));
	if(TmpA!=NULL)
	{
		while(length<n)
		{
			Merge_Pass(A,TmpA,n,length);//有序数列存入TmpA 
			length*=2;
//			for(i=0;i<M;i++)
//			{
//				printf("%d ",A[i]);
//			}
//			printf("\n");
			Merge_Pass(TmpA,A,n,length);//将有序数列TmpA导入A 
			length*=2;
		}
		free(TmpA);
	}
	else
	{
		printf("No extra space");
	}
}
//非递归 
void Merge_Pass(int *A,int *TmpA,int n,int length)
{
	//length当前子序列的长度 
	int i,j;
	for(i=0;i<=n-2*length;i+=2*length) 
	{
		Merge1(A,TmpA,i,i+length,i+2*length-1);
	}
	if(i+length<n)//归并最后两个数列 
	{
		Merge1(A,TmpA,i,i+length,n-1);
	}
	else//归并最后一个数列 
	{
		for(j=i;j<n;j++)
		{
			TmpA[j]=A[j];
		}
	}
}
//有序子列的归并 
void Merge1(int *a,int *b,int L,int R,int RightEnd)//L左边起始位置，R右边起始位置，RE右边终点位置 
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
//	for(i=0;i<NumE;i++,RightEnd--)//从末尾导入   原始Merge 
//	{
//		a[RightEnd]=b[RightEnd];
//	}
}
