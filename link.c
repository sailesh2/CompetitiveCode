#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node* next;
};
struct node *p,*q,*t;

void create();
void disp();
void ins();
void delt();
int ctr=0;

int main()
{
	int ch;
	t=q=NULL;
	while(1)
	{
	   printf("1--create\n2--disp\n3--delelte\n4--exit\n5--insert\nenter \n");
       scanf("%d",&ch);
	   switch(ch)
	   {
			case 1:create();
				   break;
			case 2:disp();
				   break;
			case 3:delt();
				   break;
			case 5:ins();
				   break;

	   }
	   if(ch==4)
	   {
			getch();
			return 0;
	   }
   }
   getch();
   return 0;
}

void create()
{
	p=(struct node*)malloc(sizeof(struct node));
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	if(t==NULL)
	t=q=p;
	else
	{
		q->next=p;
		q=p;
	}
	ctr++;
}

void disp()
{
	p=t;
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
	printf("\n");
}

void delt()
{
	struct node *s;
	int pos,i;
	printf("enter position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		p=t;
		t=t->next;
		free(p);
		ctr--;
	}
	if(pos==ctr)
	{
		p=t;
		for(i=1;i<(ctr-1);i++)
		{
			p=p->next;
		}
		q=p;
		p=q->next;
		q->next=NULL;
		free(p);
		ctr--;
	}
	if(pos>1&&pos<ctr)
	{
		p=t;
		for(i=1;i<(pos-1);i++)
		{
			p=p->next;
		}
		s=p->next;
		p->next=s->next;
		free(s);
		ctr--;
	}
	if(t==NULL)
	{
		printf("UNDERFLOW \n");
		getch();
		exit(0);
	}
}

	
void ins()
{
	int i,pos;
	struct node *s,*m;
	s=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&s->info);
	printf("enter positon\n");
	scanf("%d",&pos);
	s->next=NULL;
	p=t;
	if(s==NULL)
	{
		printf("overflow\n");
		getch();
		exit(0);
	}
	if(pos==1)
	{
		s->next=t;
		t=s;

	}
	if(pos==(ctr+1))
	{
		//printf("%d\n",q->info);
	//	s->next=NULL;
	//if(q->next==NULL)
	//{:
		q->next=s;
		q=s;
	//	printf("%d\n",s->info);
		//q=q->next;
		//q->next=NULL;

	}
	if(pos>1&&pos<(ctr+1))
	{
		for(i=1;i<(pos-1);i++)
		{
			p=p->next;
		}
		s->next=p->next;
		p->next=s;

	}
	ctr++;
}
