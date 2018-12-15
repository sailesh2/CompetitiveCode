#include<stdio.h>
#include<stdlib.h>
struct node
{
	float co;
	int exp;
	struct node *link;
};
void display(struct node *);
struct node *creat(struct node *,int);
struct node *insert(struct node *,float,int);
struct node *multp(struct node *,struct node *,struct node *,int);
//struct node *add(struct node *,struct node *,struct node *);

int main()
{   struct node *s1=NULL,*s2=NULL,*s3=NULL;
	int n1,n2,max;
	printf("enter the terms of p1 : ");
	scanf("%d",&n1);
	s1=creat(s1,n1);
	display(s1);
	printf("\nenter the terms of p2 : ");
	scanf("%d",&n2);
	s2=creat(s2,n2);
	display(s2);
	printf("\nresult is : ");
  	max=s1->exp+s2->exp;
	//printf("max=%d",max);
	s3=multp(s3,s1,s2,max);
	display(s3);
	//s3=add(s3,s1,s2);
	//display(s3);
	getch();
	return 0;
}
void display(struct node *s)
{
	struct node *ptr;
	ptr=s;
	while(ptr!=NULL)
	{
		printf("(%.1fx^%d)+",ptr->co,ptr->exp);
		ptr=ptr->link;
	}
}
struct node *creat(struct node *s,int n)
{   struct node *p;
	int e,i;
	float c;
	for(i=0;i<n;i++)
	{
    	struct node *tmp;
		tmp=(struct node *)malloc(sizeof(struct node));
		printf("enter the coeficient : ");
		scanf("%f",&c);
		tmp->co=c;
		printf("enter the exp : ");
		scanf("%d",&e);
		tmp->exp=e;
		p=s;
		if(s==NULL || tmp->exp>s->exp)
		{
			tmp->link=s;
			s=tmp;
		}

		else
		{
		while(p->link!=NULL)
			p=p->link;
		tmp->link=NULL;
		p->link=tmp;
		}
	}
	return s;
}
struct node *multp(struct node *s3,struct node *s1,struct node *s2,int max)
{
    struct node *p,*q;
	int i;
	for(i=max;i>=0;i--)
	{   float f=0;
		for(p=s1;p!=NULL;p=p->link)
		{
			for(q=s2;q!=NULL;q=q->link)
			{
				if(p->exp+q->exp==i)
				{
					f=f+(p->co*q->co);
				}
			}
		}
		s3=insert(s3,f,i);
	}
	return s3;
}
struct node *insert(struct node *s,float f,int i)
{
        struct node *tmp,*p;
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->co=f;
		tmp->exp=i;
		p=s;
		if(s==NULL)
		{
			tmp->link=s;
			s=tmp;
		}

		else
		{
		while(p->link!=NULL)
			p=p->link;
		tmp->link=NULL;
		p->link=tmp;
		}
		
 return s;
}
/*struct node *add(struct node *s3,struct node *s1,struct node *s2)
{
    struct node *p,*q;
    int i,max;
    if(s1->exp>s2->exp)
        max=s1->exp;
	else
	    max=s2->exp;
    for(i=max;i>=0;i--)
	{   float f=0;
	
		for(p=s1;p!=NULL;p=p->link)
		{
			for(q=s2;q!=NULL;q=q->link)
			    {
					if(p->exp==q->exp==i)
					{
						f=f+p->co+q->co;
					}
				}
		}
		s3=insert(s3,f,i);
	}
	return s3;
}
*/
