#include<stdio.h>

int main()
{
  int i,j,k;
  for(k=0;k<5;k++)
  {
	 for(i=1;i<=5;i++)
	 {
			for(j=1;j<=i;j++)
			{
				printf("* ");
			}
		  printf("\n");
	 }
	 printf("\n");
	}
	getch();
	return 0;
}
