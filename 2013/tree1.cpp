#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<ctype.h>
#include<iostream>

using namespace std;

struct tree
{
	int info;
	struct tree *left;
	struct tree * right;
};
int rear=-1;
int front=-1;
void levelwise(struct tree *);
void insert(struct tree *);
struct tree * delt();
struct tree *que[100];
int main()
{
    struct tree *root,*p,*q;
    cout<<"enter root\n";
    root=(struct tree *)malloc(sizeof(struct tree));
    root->left=root->right=NULL;
    cin>>(root->info);
    insert(root);
	int k=1,ctr,i;
	char ch;
	while(k!=0)
	{
		ctr=k;
		k=0;
		i=0;
		while(i<ctr)
		{
			q=delt();
     		cout<<"want a"<<q->info<<" 's left child\n enter y--yes  n--no\n";
			cin>>ch;
			if(tolower(ch)=='y')
			{
				cout<<"enter data\n";
			    p=(struct tree *)malloc(sizeof(struct tree));
			    p->left=p->right=NULL;
			    cin>>(p->info);
			    q->left=p;
			    insert(p);
			    k++;
		    }
			cout<<"want a"<<q->info<<" 's right child\n enter y--yes  n--no\n";
	    	cin>>ch;
			if(tolower(ch)=='y')
			{
				cout<<"enter data\n";
			    p=(struct tree *)malloc(sizeof(struct tree));
				p->left=p->right=NULL;
				cin>>(p->info);
				q->right=p;
				insert(p);
				k++;
			}
			i++;
	    }

	}
	cout<<"LEVELWISE--TRAVERSAL\n";
	levelwise(root);
	getch();
	return 0;
}
void levelwise(struct tree *root)
{
	struct tree *q,*p;
	insert(root);
	int k=1,ctr,i=0;
	while(k!=0)
	{
		ctr=k;
		k=0;
		i=0;
		while(i<ctr)
		{
			q=delt();
			if(q!=NULL)
			{
			cout<<q->info<<" ";
			if(q->left!=NULL)
			{
				insert(q->left);
				k++;
			}
			if(q->right!=NULL)
			{
				insert(q->right);
				k++;
			}
		    }
			i++;
		}
		cout<<"\n";
	}
}
void insert(struct tree *p)
{
	if(rear==100)
	{
		cout<<"queue full\n";
		return;
	}
	if(rear==-1)
	{
		rear=0;
		front=0;
	}
	else
	rear++;
	que[rear]=p;
}
struct tree *delt()
{
	struct tree *p;
	if(front==-1)
	return NULL;
	p=que[front];
	if(rear==front)
		rear=front=-1;
	else
	front++;
	return p;
}
