//Ronak kumar Meher
//Roll no : 111CS0138

//program to implement EULER PATH...

#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
};

struct node *p=NULL,*q=NULL,*t=NULL;
struct node *arr[10];
struct node * create(int);
void check();
int main()
{
    int n,i;
	printf("enter number of nodes(max 10): \n");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	arr[i]=NULL;
	i=0;
	while(i<n)
	{
	printf("enter %d array\n",i+1);
	printf("----------------------\n");
	arr[i]=create(n);
	t=q=NULL;
    i++;
    }
    check();
    getch();
    return 0;


}


struct node *create(int n)
{
	int k=0;
	while(k<n)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->link=NULL;
		printf("enter 1.edge  0.no node\n");
		scanf("%d",&p->info);
		if(t==NULL)
		t=q=p;
		else
		{
			q->link=p;
			q=p;
		}
		k++;
    }
	return t;
}


void check()
{
	int i;
	int c=0,cnt=0;
	for(i=0;i<6;i++)
	{
		p=arr[i];
		while(p!=NULL)
		{
			if(p->info==1)
			c++;
			p=p->link;
		}
		if(c%2!=0)
		cnt++;
		c=0;
	}
	if(cnt==2)
	printf("euler path...\n");
	else
	printf("not euler path...\n");
}
