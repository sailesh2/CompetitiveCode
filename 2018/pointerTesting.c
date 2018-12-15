#include<stdio.h>
#include<malloc.h>

int *p,*t,*q;
int main()
{
	int n,m;
	printf("enter d size of d array");
	scanf("%d%d",&n,&m);
	t=p=(int (*)[])malloc(n*m*sizeof(int));
	int i,j,k=0;
	for(i=0;i<n;i++)
	{
		q=(int *)(p+i);
		for(j=0;j<m;j++)
		{
		 scanf("%d",&*(q+j));
        }

    }
    k=0;
for(i=0;i<n;i++)
	{
		q=(int *)(p+i);
		for(j=0;j<m;j++)
		{
		printf("%d",(*(q+j)));
		//t++;
}
k=k+j;
printf("\n");
}
getch();
return 0;
}
