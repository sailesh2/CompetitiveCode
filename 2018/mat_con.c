#include<stdio.h>
#include<malloc.h>

void rev(int);
int *p,*q,*t;
int main()
{
	int n;
	printf("array is of NXN format\n enter d value of N\n");
	scanf("%d",&n);
	t=p=(int *)malloc(n*n*sizeof(int));
	printf("enter integer elements\n");
	int i,j,k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   scanf("%d",&(*(p+k+j)));
		}
		k=k+j;
	}
	k=0;
	rev(n);
	getch();
	return 0;
	
}


void rev(int m)
{
	int k=0,k1=0,sum=0,i,j;
	q=(int (*))malloc((m+1)*(m+1)*sizeof(int));
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
           (*(q+k1+j))=(*(p+k+j));
			sum+=(*(p+k+j));
		}
        (*(q+k1+j))=sum;
		   //printf("%d \n \n",sum);
		sum=0;
		k=k+j;
		k1=k1+j+1;
	}
	sum=0;
	for(j=0;j<m;j++)
	{
		t=p+j;
	for(i=0;i<m;i++)
	{
	  sum=sum+*(t);
	  t=t+m;
    }
    printf("%d",sum);
    *(q+((m+1)*m)+j)=sum;
    sum=0;
   }

sum=0;
k=0;
for(i=0;i<m;i++)
{
	for(j=0;j<m;j++)
	{
		if(i==j)
		sum=sum+*(p+k+j);
	}
k=k+j;
}
*(q+((m+1)*m+m))=sum;

k=0;
for(i=0;i<m+1;i++)
{
	for(j=0;j<m+1;j++)
	{
		printf("%d",*(q+k+j));
		}
		printf("\n");
		k=k+j;
	}

}


