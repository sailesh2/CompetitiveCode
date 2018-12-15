                                     //SAILESH KUMAR UPADHYAYA//
                                        //ROLL--111CS0160//

//PROGRAM TO IMPLEMENT EULER PATH//

#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *next;
};

struct node *p,*q,*t;
struct node *arr[6];
struct node * create(int);
void check();
int main()
{
    int n,i=0;
	p=q=t=NULL;
	printf("max--6\nenter no. of nodes\n");
	scanf("%d",&n);
	for(;i<6;i++)
	arr[i]=NULL;
	i=0;
	while(i<n)
	{
	printf("enter %d array\n",i+1);
	arr[i]=create(n);
	t=q=NULL;
    i++;
    }
    check();
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
		printf("enetr 1--edge  0--no node\n");
		scanf("%d",&p->info);
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


void check()
{
	int i;
	int ctr=0,cnt=0;
	for(i=0;i<6;i++)
	{
		p=arr[i];
		while(p!=NULL)
		{
			if(p->info==1)
			ctr++;
			p=p->next;
		}
		if(ctr%2!=0)
		cnt++;
		ctr=0;
	}
	if(cnt==2)
	printf("euler path\n");
	else
	printf("not euler path\n");
}
