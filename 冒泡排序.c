#include<stdio.h>
void swap(int *,int *);
void BubbleSort(int *,int );
int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	BubbleSort(num,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
}
void BubbleSort(int *num,int N)
{
	int i=0;
	int p;
	for(p=N-1;p>=0;p--)//n����ֻ����� n-1������ ÿ����һ������ ��һ������һ���� 
	{
		int flag=0;
		for(i=0;i<p;i++)//�����ĳ���ײ� һ��ð�� 
		{
			if(num[i]>num[i+1])
			{
				swap(&num[i],&num[i+1]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
