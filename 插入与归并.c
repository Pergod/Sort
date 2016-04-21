#include<stdio.h>
#include<stdlib.h>
#define LOCAL
void InsertSort(int *,int ,int);
void Merge_Pass(int *,int *,int,int);//�ǵݹ� 
void Merge1(int *,int *,int,int,int);//�������еĹ鲢  !ʡȥ���һ����TMPA����A 
int check(int *,int );
int GetLength(int *,int);
int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int N;
	scanf("%d",&N);
	int O[N];
	int R[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&O[i]);
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&R[i]);
	}
	int Loc=check(R,N);
	int tag=0;
	for(i=Loc;i<N;i++)
	{
		if(R[i]!=O[i])
		{
			tag=1;
			break;
		}
	}
	if(tag==0)
	{
		printf("Insertion Sort\n");
		InsertSort(R,N,Loc);
	}
	else
	{
		printf("Merge Sort\n");
		int L=GetLength(R,N);//�жϹ鲢���еĳ��� 
		int *TmpA=(int *)malloc(N*sizeof(int));
	    Merge_Pass(R,TmpA,N,L);
	    L*=2;
	    Merge_Pass(TmpA,R,N,L);
	    L*=2;
	    for(i=0;i<N;i++)
	    {
	    	printf("%d",R[i]);
	    	if(i<N-1)
	    	{
	    		printf(" ");
			}
		}
	}
}
int GetLength(int *R,int N)//key
{
	int L;
	int i;
	for(L=2;L<=N;L*=2)
	{
		for(i=L;i<=N;i+=2*L)
	    {
	        if(R[i-1]>R[i])
	        {
	        	L/=2;
	            return L;
			}
		} 
	}
}
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
void InsertSort(int *a,int n,int L)
{
	int i,p;
	int temp;
	int flag=0;
	for(p=L;p<n;p++)
	{
		temp=a[p];
		for(i=p;i>0&&a[i-1]>temp;i--)
		{
			a[i]=a[i-1];
			flag=1;
		}
		a[i]=temp;
		if(flag)
		{
			for(i=0;i<n;i++)
			{
				printf("%d",a[i]);
				if(i<n-1)
		    	{
		    		printf(" ");
				}
			}
			break;
		}
	}
}
int check(int *a,int n)
{
	int i;
	int flag;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			flag=i+1;
			return flag;
		}
	}
}
