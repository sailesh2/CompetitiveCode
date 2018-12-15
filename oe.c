//GAUSS ELIMINATION

#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,k,n;
	float sum=0;
	
	printf("enter the dimension of coefficient matrix\n",&n);
	scanf("%d",&n);
	float in[n][n+1];
	float x[n];
	
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	
	printf("enter augmented matrix row by row\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			scanf("%f",&in[i][j]);
		}
	}
	
	printf("AUGMENTED MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%f ",in[i][j]);
		}
		printf("\n");
    }
    printf("\n\n");
    
float c;
//FORWARD ELIMINATION
    for(i=0;i<n;i++)
    {
		for(j=i+1;j<n;j++)
		{
            c=(in[j][i]/in[i][i]);
			for(k=0;k<(n+1);k++)
			{
				in[j][k]=in[j][k]-(c*in[i][k]);
			}
		}
    }

	printf("UPPER TRIANGULAR MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%f ",in[i][j]);
		}
		printf("\n");
	}
//BACKWARD SUBSTITUTION
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			sum=sum+(in[i][j]*x[j]);
		}
		x[i]=(in[i][n]-sum)/in[i][i];
		sum=0;
	}

	printf("\n\n");
	printf("SOLUTION MATRIX\n");
	for(i=0;i<n;i++)
	{
		printf("%f ",x[i]);
	}
	printf("\n");
	
	getch();
	return 0;
}
