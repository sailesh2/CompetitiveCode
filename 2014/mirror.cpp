#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<iostream>

using namespace std;

struct node
{
	int info;
	struct node *left;
	struct node *right;
};
struct node *root,*p,*q;
struct node * stack[100];
void push(struct node *);
struct node * pop();
void pre(struct node *);
int top=-1;
void mirror(struct node *);
struct node * mirrorimage(struct node *);
int main()
{
	root=(struct node *)malloc(sizeof(struct node));
	root->left=root->right=NULL;
	cout<<"enter root\n";
	cin>>root->info;
	p=root;
	int ch;
	while(p!=NULL)
	{
		ch=0;
		cout<<"left child of"<<p->info<<"\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter\n";
			q=(struct node *)malloc(sizeof(struct node));
			q->left=q->right=NULL;
			cin>>q->info;
			p->left=q;
		}
		ch=0;
		cout<<"right child of"<<p->info<<"\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter\n";
			q=(struct node *)malloc(sizeof(struct node));
			q->left=q->right=NULL;
			cin>>q->info;
			p->right=q;
			push(q);
		}
		p=p->left;
		if(p==NULL)
		p=pop();
	}
	pre(root);
	cout<<"\n";
	//mirror(root);
	q=mirrorimage(root);
	pre(q);
	//cout<<q<<q->left<<q->right<<"\n";
	getch();
	return 0;
}
void push(struct node *p)
{
	stack[++top]=p;
}
struct node *pop()
{
	return (stack[top--]);
}
void pre(struct node *p)
{
	if(p==NULL)
	return;
	cout<<p->info;
	pre(p->left);
	pre(p->right);
}
void mirror(struct node *p)
{
	if(p==NULL)
	return;
	struct node *temp;
	temp=p->left;
	p->left=p->right;
	p->right=temp;
	mirror(p->right);
	mirror(p->left);
}
struct node * mirrorimage(struct node *p)
{
	if(p==NULL)
	return NULL;
	struct node *q1=(struct node *)malloc(sizeof(struct node));
	q1->info=p->info;
	q1->right=mirrorimage(p->left);
	q1->left=mirrorimage(p->right);
	return q1;
}
