#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main()
{
	int n;
	printf("enter dimension\n");
	scanf("%d",&n);
	char *p=(char *)malloc(n*sizeof(char));
	int i;
	int j=0;
/*	p[0]='a';
	p[1]='v';
	printf("%c",p[0]);
	printf("%c",p[1]);
	printf("%c",p[2]);
	printf("%c",p[3]);
	printf("%c",p[4]);
*/

	/*for(i=0;i<n;i++)
	{
		scanf("%c",&p[i]);
		if(p[i]=='\0')
		break;
	}*/
	scanf("%s",p);
	while(p[j]!='\0')
	{
		j++;
	}
	p[j]='e';
	j++;
	p[j]='\0';
	/*for(;j<n;j++)
	{
		p[j]='\0';
	}*/
	for(i=0;p[i]!='\0';i++)
	{
		printf("%c",p[i]);
	}
	getch();
	return 0;
	
	
}
