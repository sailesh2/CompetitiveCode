#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	int priority;
	struct node *next;
};
struct node *p,*q,*t;

void ins();
void delt();
void disp();

int main()
{
	p=q=t=NULL;
	int n,ch;
	while(1)
	{
		printf("1--insert\n2--delete\n3--display\n4--exit\nenter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins();
				   break;
			case 2:delt();
     			   break;
			case 3:disp();
				   break;
				   
		}
		if(ch==4)
		return 0;
		
	}
	getch();
	return 0;
}

void ins()
{
	int cnt=0;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("overflow\n");
		return;
	}
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	printf("enter priority\n");
	scanf("%d",&p->priority);
	
	if(t==NULL)
	t=q=p;
	else
	{
		if(t->priority<p->priority)
		{
			p->next=t;
			t=p;
		}
		else
		{
			struct node *s=t,*m;
		while(s->priority>p->priority)
		{
			m=s;
			if(s->next==NULL)
			{
				cnt++;
				break;
			}
			s=s->next;
		}
		if(cnt==1)
		{
			s->next=p;
			p->next=NULL;
		}
		else
		{
			m->next=p;
		    p->next=s;
		}
	  }
    }
}


void delt()
{
	if(t==NULL)
	{
		printf("underflow\n");
		return;
	}
	p=t;
	t=t->next;
	free(p);
}


void disp()
{
	p=t;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");

}
