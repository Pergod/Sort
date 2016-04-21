#include<stdio.h>
#include<stdlib.h>
#define M 20
void Merge_Sort(int *,int);//ͳһ�����ӿ� 
void Msort(int *,int *,int,int);//�ݹ� 
void Merge(int *,int *,int,int,int);//�������еĹ鲢
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
//ͳһ�����ӿ� 
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
//�ݹ� 
void Msort(int *A,int *TmpA,int L,int RightEnd)
{
	int Center;
	if(L<RightEnd)
	{
		Center=(L+RightEnd)/2;
		Msort(A,TmpA,L,Center);/* �ݹ������ */ 
		Msort(A,TmpA,Center+1,RightEnd);/* �ݹ����ұ� */ 
		Merge(A,TmpA,L,Center+1,RightEnd);/* �ϲ������������� */
	}
}
//�������еĹ鲢 
void Merge(int *a,int *b,int L,int R,int RightEnd)//L�����ʼλ�ã�R�ұ���ʼλ�ã�RE�ұ��յ�λ�� 
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
	for(i=0;i<NumE;i++,RightEnd--)//��ĩβ���� 
	{
		a[RightEnd]=b[RightEnd];
	}
}
