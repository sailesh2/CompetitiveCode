#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	struct node *prev;
	char info;
	struct node *next;
};
struct node *s=NULL,*t=NULL;
void creat(char);
void check(int);
int main()
{
	int n,i;
	char str[10];
	printf("enter the string : ");
	scanf("%s",str);
	int l=strlen(str);
	for(i=0;i<l;i++)
	{
		creat(str[i]);
	}
	check(l);
	getch();
	return 0;
}
void creat(char c)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=c;
	if(s==NULL)
	{
		tmp->next=NULL;
		tmp->prev=NULL;
		s=tmp;
		t=tmp;
	}
	else
	{
		p=s;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		tmp->next=NULL;
		tmp->prev=p;
		p->next=tmp;
		t=tmp;
	}
}
void check(int l)
{
	int c=0;
	while(s!=NULL)
	{
		if(s->info==t->info)
			c++;
		s=s->next;
		t=t->prev;
	}
	if(c==l)
		printf("\npallindram");
	else
		printf("\nnot pallindram");
}
