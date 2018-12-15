#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *next;
};

void create(struct node **,struct node **);
void disp(struct node **);

int main()
{
	int n,ch;
	struct node *q,*t;
	q=t=NULL;
	do
	{
		create(&q,&t);
		printf("1--continue\n2--discontinue\n");
		scanf("%d",&n);
	}
	while(n==1);

	//while(1)
	//{
	//	printf("1--insert\n2--delete\n3--search\n4--exit\n");
	//}
	disp(&t);
	getch();
	return 0;
}

void create(struct node **q1,struct node **t)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&p->info);
	p->next=NULL;
	//struct node *s;
	//s=*q1;
	if(*t==NULL)
	*t=*q1=p;
	else
	{
		(*q1)->next=p;
		(*q1)=p;
	}
}

void disp(struct node **t)
{
	struct node *p=*t;
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
}
