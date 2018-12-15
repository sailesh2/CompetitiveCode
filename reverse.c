#include<stdio.h>
#include<malloc.h>

//REVERSE OF AN ARRAY WITHOUT USING 2ND ARRAY
int *p;
void rev(int);
int main()
{
	int n;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("-ve input not accepted\n");

		return 0;
	}
	p=(int *)malloc(n*sizeof(int));
	printf("enter integer elemnts\n");
	int i;
	for(i=0;i<n;i++)
	{
			scanf("%d",&p[i]);
    }
    printf("INPUT--\n");
    for(i=0;i<n;i++)
	{
			printf("%d ",p[i]);
	}
	printf("\n");
    rev(n);

    return 0;
    
}

void rev(int m)
{
	int i,temp;
	for(i=0;i<=((m/2)-1);i++)
	{
		temp=p[i];
		p[i]=p[m-i-1];
		p[m-i-1]=temp;
	}
	printf("OUTPUT--\n");
	for(i=0;i<m;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}
