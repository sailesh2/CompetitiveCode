#include<stdio.h>
#include<malloc.h>

//MATRIX CONVERSION
int n;
int *p,*p1;
void conv();
int main()
{
	int i,j;
	printf("the array is of size NXN\nenter N\n");
    scanf("%d",&n);
	if(n<0)
	{
		printf("-ve elemnt not acceptdd \n");

		return 0;
	}
	p=(int *)malloc(n*n*sizeof(int));
    printf("enter integer elemnts\n");
    int (*q)[n]=p;
   for(i=0;i<n;i++)
   {
		for(j=0;j<n;j++)
		{
			scanf("%d",&q[i][j]);
		}
   }
   conv();
   getch();
   return 0;
}

void conv()
{
	int i,j,sum=0;
	p1=(int *)malloc((n+1)*(n+1)*sizeof(int));
	int (*q1)[n+1]=p1;
	

	int (*q)[n]=p;
	for(i=0;i<n;i++)
	{

		for(j=0;j<n;j++)
		{
			q1[i][j]=q[i][j];
			sum=sum+q[i][j];
		}
		q1[i][j]=sum;
		sum=0;
	}

    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=sum+q[j][i];
		}
		q1[j][i]=sum;
		sum=0;
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			sum=sum+q[i][j];
		}
	}
	q1[n][n]=sum;
	printf("INPUT--\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
        {

			printf("%d ",q[i][j]);
		}
	    printf("\n");
    }
	printf("OUTPUT--\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==n)
			printf("%d",q1[i][j]);
			else
			printf("%d ",q1[i][j]);
		}
		printf("\n");
	}

}
