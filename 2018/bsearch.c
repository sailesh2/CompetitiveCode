#include<stdio.h>
#include<malloc.h>

//BINARY SEARCH
void binsearch(int,int);
int *p;
int main()
{
	int i,n,j,ser;
	printf("enter the size of the array \n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("-ve element not accepted \n");

		return 0;
	}
	p=(int *)malloc(n*sizeof(int));
    printf("enter the integer elements in sorted order \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		for(j=0;j<i;j++)
		{
			if(p[j]==p[i])
			{
				printf("element repeated\n");

				return 0;
			}
		}
	}
	 printf("your array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d",p[i]);
	}
	printf("\n");
	printf("enter the search element \n");
	scanf("%d",&ser);
	binsearch(ser,n);

	return 0;
}
void binsearch(int ser1,int m)
{
	int ctr=0,ub=m-1,lb=0,mid;
	while(ctr!=2)
    {
	   mid=(ub+lb)/2;
	   if(ser1>p[mid])
	   {
			lb=mid;

	   }
	   if(ser1<p[mid])
	   {
			ub=mid;
			
	   }
	   if(ser1==p[mid])
	   {
            printf("found at %d position \n",(mid+1));
			break;
	   }
	   if((ub-lb)==1)
	   ctr++;

}
if(ctr==2&&ser1!=p[m-1])
printf("element not found \n");
if(ctr==2&&ser1==p[m-1])
printf("element found at %d position \n",m);
}
