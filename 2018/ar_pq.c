#include<stdio.h>
#include<malloc.h>

struct pq
{
	int info;
	int priority;
};
int ctr=-1;
void ins(struct pq *,int);
void delt(struct pq *,int);
void disp(struct pq *,int);

int main()
{
	int n,ch;
	printf("enter limit\n");
	scanf("%d",&n);
	struct pq *arr=(struct pq *)malloc(n*sizeof(struct pq));
	while(1)
	
	{
		printf("1--insert\n2--delete\n3--display\n4--exit\nenter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins(arr,n);
			break;
			case 2:delt(arr,n);
			break;
			case 3:disp(arr,n);
			break;
		}
		if(ch==4)
		return 0;
	}
	return 0;
}

void ins(struct pq *a,int m)
{
	int cnt=0;
	int item,prior,i,j;
	printf("enter item\n");
	scanf("%d",&item);
	printf("enter priority\n");
	scanf("%d",&prior);
	ctr++;

	if(ctr==0)
	{
    	a[ctr].info=item;
	    a[ctr].priority=prior;
	}
	else
	{
		if(prior>a[0].priority)
		{
		//	ctr++;
			i=ctr;
			while(i!=0)
			{
				a[i].info=a[i-1].info;
                a[i].priority=a[i-1].priority;
				i--;
			}
			a[0].info=item;
			a[0].priority=prior;
		}
		else
		{
			i=0;
			while(a[i].priority>prior)
			{

				if(i==(ctr-1))
				{
					cnt++;
					break;
				}
				i++;
			}
			if(cnt==1)
			{
				a[ctr].info=item;
				a[ctr].priority=prior;
			}
			else
			{
			j=ctr;
			while(j!=i)
			{
                	a[j].info=a[j-1].info;
                a[j].priority=a[j-1].priority;

			}
            	a[i].info=item;
                a[i].priority=prior;

			}
			}
}
}












