#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *next;
};
void create1();
void create2();
void create3();
void create4();
int check();
void max(int *);
void min(int *);
int a[4];
int b[4];

struct node *q1,*t1,*q2,*t2,*q3,*t3,*q4,*t4;

int main()
{
	q1=t1=q2=t2=q3=t3=q4=t4=NULL;
	int n;
	printf("enter limit\n");
	scanf("%d",&n);
	int i=0;
	printf("enter 1st list\n");
	while(i<n)
	{
		create1();
		i++;
	}
	i=0;
printf("enter 2nd list\n");
	while(i<n)
	{
		create2();
		i++;
	}
	i=0;
printf("enter 3rd list\n");
	while(i<n)
	{
		create3();
		i++;
	}
	i=0;
printf("enter 4th list\n");
	while(i<n)
	{
		create4();
		i++;
	}
	i=0;
int k;
while(1)
{
	//printf("hello\n");
k=check();
if(k==1)
break;
}
 if(t1==NULL)
	printf("ist winner\n");
if(t2==NULL)
	printf("2nd winner\n");
if(t3==NULL)
	printf("3rd winner\n");
if(t4==NULL)
	printf("4th winner\n");
getch();
return 0;
}

void create1()
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	if(t1==NULL)
	t1=q1=p;
	else
	{
		q1->next=p;
		q1=p;
	}
}

void create2()
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	if(t2==NULL)
	t2=q2=p;
	else
	{
		q2->next=p;
		q2=p;
	}
}
void create3()
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	if(t3==NULL)
	t3=q3=p;
	else
	{
		q3->next=p;
		q3=p;
	}

}
void create4()
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	if(t4==NULL)
	t4=q4=p;
	else
	{
		q4->next=p;
		q4=p;
	}

}
int check()
{
	int arr[4];
	arr[0]=t1->info;
	arr[1]=t2->info;
	arr[2]=t3->info;
	arr[3]=t4->info;

	struct node *m,*p;
	m=t1;
	t1=t1->next;
	free(m);
	m=t2;
	t2=t2->next;
	free(m);
	m=t3;
	t3=t3->next;
	free(m);
	m=t4;
	t4=t4->next;
	free(m);
	
//	printf("nye\n");
	if(t1==NULL||t2==NULL||t3==NULL||t4==NULL)
	return 1;
	
//	int *a,*b;
	//a=max(arr);
	//b=min(arr);
//	while(l<b[1])
max(arr);
min(arr);
int i,l=0;
	for(i=0;a[i]!=-1;i++)
	{
	if(a[i]==1)
	{
		while(l<b[1])
		{
            p=(struct node *)malloc(sizeof(struct node));
	        p->next=NULL;
	        p->info=b[0];
			q1->next=p;
			q1=p;
			//printf("hi\n");
			l++;
		}
	}
	if(a[i]==2)
	{
		while(l<b[1])
		{
            p=(struct node *)malloc(sizeof(struct node));
	        p->next=NULL;
	        p->info=b[0];
			q2->next=p;
			q2=p;
			//printf("hi\n");
			l++;
		}

    }
    if(a[i]==3)
	{
		while(l<b[1])
		{
            p=(struct node *)malloc(sizeof(struct node));
	        p->next=NULL;
	        p->info=b[0];
			q3->next=p;
			q3=p;
			//printf("hi\n");
			l++;
		}
   }
   if(a[i]==4)
	{
		while(l<b[1])
		{
            p=(struct node *)malloc(sizeof(struct node));
	        p->next=NULL;
	        p->info=b[0];
			q4->next=p;
			q4=p;
			//printf("hi\n");
			l++;
		}
   }
   l=0;
 }

return 0;
}


void min(int *arr)
{
	int m=arr[0];
	int i;
	for(i=0;i<4;i++)
	{
		if(arr[i]<m)
		m=arr[i];
	}
	int ctr=0;
	for(i=0;i<4;i++)
	{
		if(arr[i]==m)
		ctr++;
	}
	//int mn[2];
	//mn[0]=m;
	//mn[1]=ctr;
	b[0]=m;
	b[1]=ctr;
	//return mn;

}

void max(int *arr)
{
	int m=arr[0];
	//int mx[4];
	int i,j;
	for(i=0;i<4;i++)
	{
		if(arr[i]>m)
		m=arr[i];
	}
	for(j=0;j<4;j++)
	{
		a[j]=-1;
	}
	for(i=0,j=0;i<4;i++)
	{
		if(arr[i]==m)
		{
			a[j]=i+1;
			j++;
		}
	}
	//return &mx[0];
}
