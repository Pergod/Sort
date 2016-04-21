#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	scanf("%d",&N);
	int num[N];
	int no[N];
	memset(no,-1,sizeof(no));
	int i,j,k;
	int f=0;
	int cnt=N;
	for(i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(num[i]<num[j])
			{
				no[f++]=num[i];
				no[f++]=num[j];
				cnt--;
				break;
			}
		}
		for(k=i+1;k<N;k++)
		{
			if(num[i]>num[k])
			{
				no[f++]=num[i];
				no[f++]=num[k];
				cnt--;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	for(i=0;i<N;i++)
	{
		int tag=0;
		for(j=0;no[j]!=-1;j++)
		{
			if(num[i]==no[j])
			{
				tag=1;
			}
		}
		if(tag==0)
		{
			printf("%d",num[i]);
			if(i<N-1)
			{
				printf(" ");
			}
		}
	}
	return 0;
}
    #include<stdio.h>  
    #include<stdlib.h>  
    typedef struct node  
    {  
        int date;  
        int flag;  
    }aNode;  
    int cmp(const void *a,const void *b);  
    int main()  
    {  
        int N,i,n=0;  
        int max,min;  
        scanf("%d",&N);  
        aNode *A=malloc(N*sizeof(aNode));  
        int *B=malloc(N*sizeof(int));  
        for(i=0;i<N;i++)  
        {  
            scanf("%d",&A[i].date);  
            A[i].flag=1;  
        }  
        max=A[0].date;  
        min=A[N-1].date;  
        for(i=0;i<N;i++)  
        {  
            if(A[i].date>=max)  
            {  
                max=A[i].date;  
            }else  
            {  
                A[i].flag=0;  
            }  
        }  
        for(i=N-1;i>=0;i--)  
        {  
            if(A[i].date<=min)  
            {  
                min=A[i].date;  
            }else  
            {  
                A[i].flag=0;  
            }  
        }  
        for(i=0;i<N;i++)  
        {  
            if(A[i].flag==1)  
            {  
                B[n++]=A[i].date;  
            }  
        }  
        qsort(B,n,sizeof(B[0]),cmp);  
        printf("%d\n",n);  
        for(i=0;i<n;i++)  
        {  
            if(i!=0)  
            {  
                printf(" ");  
            }  
            printf("%d",B[i]);  
        }  
        printf("\n");  
        return 0;  
    }  
    int cmp(const void *a,const void *b)  
    {  
        return *(int*)a-*(int*)b;  
    }  
