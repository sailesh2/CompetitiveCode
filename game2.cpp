#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *next;
};
void create(int);

int check();
void max(int *);
void min(int *);
int a[4];
int b[4];

struct node *q[4],*t[4];

int main()
{
	int i;
	for(i=0;i<4;i++)
	{
		q[i]=NULL;
		t[i]=NULL;
	}
	int n;
	printf("enter limit\n");
	scanf("%d",&n);
	int j=0;
	i=0;
	while(j<4)
	{
	printf("enter %d list\n",j+1);
	
	while(i<n)
	{
		create(j);
		i++;
	}
	i=0;
	j++;
    }
	i=0;
int k;
while(1)
{
k=check();
if(k==1)
break;
}
 for(i=0;i<4;i++)
 {
		if(t[i]==NULL)
		{
			printf("winner %d \n",i+1);
		}
 }
getch();
return 0;
}

void create(int m)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	printf("enter data\n");
	scanf("%d",&p->info);
	if(t[m]==NULL)
	t[m]=q[m]=p;
	else
	{
		q[m]->next=p;
		q[m]=p;
	}
}

int check()
{
	int arr[4];
	int i;
	for(i=0;i<4;i++)
	{
		arr[i]=t[i]->info;
	}
	struct node *m,*p;
	for(i=0;i<4;i++)
	{
		m=t[i];
		t[i]=t[i]->next;
		free(m);
	}

	if(t[0]==NULL||t[1]==NULL||t[2]==NULL||t[3]==NULL)
	return 1;
max(arr);
min(arr);
int l=0;
if(b[1]==4)
return 2;
	for(i=0;a[i]!=-1;i++)
	{
		 int k=a[i];
		while(l<b[1])
		{
            p=(struct node *)malloc(sizeof(struct node));
	        p->next=NULL;
	        p->info=b[0];
			q[k]->next=p;
			q[k]=p;
			l++;
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

	b[0]=m;
	b[1]=ctr;
}

void max(int *arr)
{
	int m=arr[0];

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
			a[j]=i;
			j++;
		}
	}

}
