#include<stdio.h>
#include<malloc.h>

void ins(int *,int *,int *,int);
void delt(int *,int *,int *,int);
void disp(int *,int *,int *,int);

int main()
{
	int n,ch;
	printf("enter limit\n");
	scanf("%d",&n);
	int *que=(int *)malloc(n*sizeof(int));
	int rear=-1,front=-1;
	while(1)
	{
		printf("1--insert\n2--delete\n3--display\n4--exit\nenter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins(que,&rear,&front,n);
				   break;
			case 2:delt(que,&rear,&front,n);
	     		   break;
		    case 3:disp(que,&rear,&front,n);
				   break;
		}
		if(ch==4)
		return 0;
	}
	getch();
	return 0;
}

void ins(int *q,int *r,int *f,int m)
{
	int item;
	if((*r==(m-1)&&*f==0)||(*f==*r+1))
	{
		printf("overflow\n");
	    return;
	}
	printf("enter data\n");
	scanf("%d",&item);
	if(*f==-1)
    {
		*f=0;
		*r=0;
	
	}
   	else if(*r==(m-1))
	*r=0;
	else
	*r=*r+1;
	q[*r]=item;
}

void delt(int *q,int *r,int *f,int m)
{
	if(*f==-1)
	{
		printf("underflow\n");
		return;
	}
	if(*f==*r)
	{
		printf("deleted item --\%d\n",q[*f]);
		*f=*r=-1;
	}
	else if(*f==(m-1))
	{
		printf("deleted item --\%d\n",q[*f]);
		*f=0;
	}
	else
	{
		printf("deleted item --\%d\n",q[*f]);
		*f=*f+1;
	}
}

void disp(int *q,int *r,int *f,int m)
{
	int i;
	if(*r>=*f)
    {
		for(i=*f;i<=*r;i++)
	    {
			printf("%d ",q[i]);
	    }
	}
	else
	{
        	for(i=0;i<=*r;i++)
     	    {
				printf("%d ",q[i]);
     	    }
     	    for(i=*r;i<(*f-1);i++)
     	    {
				printf(" ");
     	    }
     	    for(i=*f;i<m;i++)
     	    {
	     		printf("%d ",q[i]);
            }

	}
}






