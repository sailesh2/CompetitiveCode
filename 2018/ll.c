#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
//#include<malloc.h>
struct node
{
	int info;
	struct node *link;
};
struct node *head;
void create();
void addbeg(int);
void addend(int);
void addpos(int,int);
void search(int);
void delt();
void disp();
int main()
{
    int ch,item,n;
    while(1)
    {
		printf("1.create\n2.addbeg\n3.addend\n4.addpos\n5.del\n6.disp\n7.search\n");
		printf("enter ur choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				disp();
				break;
			case 2:
				printf("enter the element");
				scanf("%d",&item);
				addbeg(item);
				disp();
				break;
			case 3:
                printf("enter the element : ");
				scanf("%d",&item);
				addend(item);
				disp();
				break;
			case 4:
                printf("enter the element : ");
				scanf("%d",&item);
				printf("enter the position : ");
				scanf("%d",&n);
				addpos(item,n);
				disp();
				break;
			case 5:
				delt();
				disp();
				break;
			case 6:
				disp();
				break;
			case 7:
                printf("enter the element : ");
				scanf("%d",&item);
				search(item);
				break;
			default:
				printf("enter a valid choice\n");
				break;
		}
}
getch();
return 0;
}
void create()
{
	int n,i,item;
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	printf("enter the no of element : ");
	scanf("%d",&n);
	printf("enter the 1st element : ");
	scanf("%d",&item);
	tmp->info=item;
	tmp->link=NULL;
	head=tmp;
	for(i=2;i<=n;i++)
	{
		printf("enter the element : ");
		scanf("%d",&item);
		addend(item);
	}
	//return head;
}
void addbeg(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->link=head;
	head=tmp;
}
void addend(int item)
{
    struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	p=head;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	tmp->link=NULL;
	p->link=tmp;
//	return head;
}
void addpos(int item,int pos)
{
	int i;
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	if(pos==1)
	{
	tmp->link=head;
	head=tmp;
	}
	else
	{
	p=head;
	for(i=1;i<pos-1 && p!=NULL;i++)
		p=p->link;
    if(p==NULL)
	{
		printf("no sufficient element");
	}
	else
	{
	tmp->link=p->link;
	p->link=tmp;
	}
	}
}
void delt()
{
	struct node *tmp,*p;
	int n,pos,i;
	printf("1.first\t2.last\t3.at a position\n");
	printf("enter a number : ");
	scanf("%d",&n);
	if (n==1)
	{
		tmp=head;
		head=tmp->link;
		free(tmp);
	}
	else if(n==2)
	{
		p=head;
		while(p->link->link!=NULL)
		    p=p->link;
		tmp=p->link;
		p->link=NULL;
		free(tmp);
	}
	else if(n==3)
	{
		printf("enter a position : ");
		scanf("%d",&pos);
		p=head;
		for(i=1;i<pos-1 && p!=NULL;i++)
		    p=p->link;
		if(p==NULL)
		{
			printf("no sufficient element");
		}
		else
		{
			tmp=p->link;
			p->link=tmp->link;
			free (tmp);
		}

	}
}
void disp()
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
		printf("%d  ",p->info);
		p=p->link;
    }
    printf("\n");
}
void search(int item)
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
		if(p->info==item)
		{printf("%d is found..\n",item);
		return;
		}
		else
		p=p->link;
    }
    printf("%d is not found..\n",item);
    
}

