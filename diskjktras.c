                                   //SAILESH KUMAR UPADHYAYA//
                                     //ROLL--111CS0160//


//PROGRAM TO IMPLEMENT DIJIKSTRA SHORTEST PATH ALGORITHM//
#include<stdio.h>
#include<malloc.h>

struct node
{
	int wt;
	int no;
	int data;
	struct node *next;
};

struct node *p,*q,*t;

struct min
{
	int d;
	int no;
};



struct dj
{
	int d;
	int no;
};
struct dj dk[7];
struct node *head[7];
struct min m[7],m1[7];

int min1=0;
struct node *create(int);
void minimum();
int minimum1();
void dks();
void disp();
struct node *arr[6];

int main()
{
	int n,i=0;
	p=q=t=NULL;
	printf("enter no. of nodes\n");
	scanf("%d",&n);
	printf("enter \ndata--1--edge present\n0--no edge\n");
	while(i<n)
	{
	printf("%d array\n",i+1);
	arr[i]=create(n);
	t=q=NULL;
	i++;
    }

    
    dks();
    disp();
    getch();
    return 0;
}

struct node *create(int n)
{
	int k=0;
	while(k<n)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->next=NULL;
		p->no=k+1;
		printf("enter data\n");
		scanf("%d",&p->data);
		if(p->data==1)
		{
			printf("enter weight\n");
			scanf("%d",&p->wt);
		}
		else
		p->wt=100;
		
		if(t==NULL)
		t=q=p;
		else
		{
			q->next=p;
			q=p;
		}
		k++;
	}
	return t;
}

void dks()
{

	int ctr=0,sum=0;
	int i,j,k,l,r;
	for(i=0;i<7;i++)
	m[i].d=-1;
	for(i=0;i<7;i++)
	m1[i].d=-1;
	for(i=0;i<7;i++)
	dk[i].d=-1;
	for(i=0;i<7;i++)
	head[i]=NULL;
	l=0;
	int s=0;
	while(l<6)
	{
		if(ctr==0)
		{
			head[0]=arr[0];
			ctr++;
		}
		for(i=2;i<7;i++)
		{
			j=0;
			while(head[j]!=NULL)
			{
				p=head[j];
				while(p->no!=i)
				{
					p=p->next;
				}
				m[j].d=p->wt;
				m[j].no=j+1;
				j++;
			}
			sum=0;
			m1[0].d=m[0].d;
			m1[0].no=m[0].no;
			int p=1,q;
			for(k=0;m[k].d!=-1;k++)
			{
				sum=sum+m[k].d;

				for(r=k+1;m[r].d!=-1;r++)
				{
					q=(p*10)+m[r].no;
					m1[r].d=sum+m[r].d;
					m1[r].no=q;
				}
				p=(p*10)+m[k+1].no;
			}
			minimum();
			dk[i].d=m1[0].d;
			dk[i].no=m1[0].no;
		}
			l++;
			int a=minimum1();
			printf("%d ",a);
			head[l]=arr[a-1];

		}
		printf("\n\n");

		
		
}

void minimum()
{
	int i,temp,temp1;
	for(i=0;m1[i].d!=-1;i++)
	{
		if(m1[0].d>m1[i].d)
		{
			temp=m1[i].d;
			temp1=m1[i].no;
			m1[i].d=m1[0].d;
			m1[i].no=m1[0].no;
			m1[0].d=temp;
			m1[0].no=temp;
		}
	}
}

int minimum1()
{

    int i,j=0,temp,temp1;
    int ara[7];

    
    

	for(i=2;i<7;i++)
	{
		if(dk[i].d>min1)
		{
			ara[j]=dk[i].d;
			j++;
		}

	}
int min=ara[0];
	for(i=0;i<j;i++)
	{
		if(ara[i]<min)
		{
			min=ara[i];
		}
	}

	for(i=2;i<7;i++)
	{
		if(dk[i].d==min)
		break;
	}
	min1=min;

	return i;
}



void disp()
{
	int i;
	for(i=2;i<7;i++)
	{
		printf("%d--%d  ",dk[i].d,dk[i].no);
	}
	printf("\n");
}
