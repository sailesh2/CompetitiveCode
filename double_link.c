#include<stdio.h>
#include<malloc.h>


struct node
{
	int info;
	struct node *next;
	struct node *prev;
};

void create(struct node **,struct node **);
void disp(struct node **);
void rev(struct node **);


int main()
{
	struct node *q,*t;
	q=t=NULL;
	int n,ch;
	while(1)
	{
		printf("1--create\n2--display\n3--reverse-display\n4--exit\nenter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create(&q,&t);
			break;
			case 2:disp(&t);
			break;
			case 3:rev(&q);
			break;
		}
		if(n==4)
		return 0;
		printf("1--continue\n2--discontinue\n");
		scanf("%d",&n);
		if(n==2)
		break;
	}
	getch();
	return 0;
}

void create(struct node **q,struct node **t)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->next=p->prev=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	//printf("%d",p->info);
	if(*t==NULL)
	{
	*t=*q=p;
    }
	else
    {

		(*q)->next=p;
		p->prev=(*q);
		(*q)=p;
	}
}

void disp(struct node **t1)
{
	struct node *p=(*t1);
	//printf("%d",(*t1)->info);
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
	printf("\n");
}

void rev(struct node **q)
{
	struct node *p=*q;
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->prev;
	}
	printf("\n");
}
