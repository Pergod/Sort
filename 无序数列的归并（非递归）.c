#include<stdio.h>
#include<stdlib.h>
#define M 20
void Merge_Sort(int *,int);//ͳһ�����ӿ� 
void Merge_Pass(int *,int *,int,int);//�ǵݹ� 
void Merge1(int *,int *,int,int,int);//�������еĹ鲢  !ʡȥ���һ����TMPA����A 
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
//ͳһ�����ӿ� 
void Merge_Sort(int *A,int n)
{
	int length=1;
	int i;
	int *TmpA=(int *)malloc(n*sizeof(int));
	if(TmpA!=NULL)
	{
		while(length<n)
		{
			Merge_Pass(A,TmpA,n,length);//�������д���TmpA 
			length*=2;
//			for(i=0;i<M;i++)
//			{
//				printf("%d ",A[i]);
//			}
//			printf("\n");
			Merge_Pass(TmpA,A,n,length);//����������TmpA����A 
			length*=2;
		}
		free(TmpA);
	}
	else
	{
		printf("No extra space");
	}
}
//�ǵݹ� 
void Merge_Pass(int *A,int *TmpA,int n,int length)
{
	//length��ǰ�����еĳ��� 
	int i,j;
	for(i=0;i<=n-2*length;i+=2*length) 
	{
		Merge1(A,TmpA,i,i+length,i+2*length-1);
	}
	if(i+length<n)//�鲢����������� 
	{
		Merge1(A,TmpA,i,i+length,n-1);
	}
	else//�鲢���һ������ 
	{
		for(j=i;j<n;j++)
		{
			TmpA[j]=A[j];
		}
	}
}
//�������еĹ鲢 
void Merge1(int *a,int *b,int L,int R,int RightEnd)//L�����ʼλ�ã�R�ұ���ʼλ�ã�RE�ұ��յ�λ�� 
{
	int i;
	int LE=R-1;
	int Tmp=L;//����������ʼλ�� 
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
	while(L<=LE)//ֱ�Ӹ������ʣ�µ� 
	{
		b[Tmp++]=a[L++];
	}
	while(R<=RightEnd)//ֱ�Ӹ����ұ�ʣ�µ� 
	{
		b[Tmp++]=a[R++];
	}
//	for(i=0;i<NumE;i++,RightEnd--)//��ĩβ����   ԭʼMerge 
//	{
//		a[RightEnd]=b[RightEnd];
//	}
}
