#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<malloc.h>

using namespace std;
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
void preorder(struct node *);
struct node * fun();
struct node *root;
char c[50];
int i=0;
int main()
{
	cin>>c;
	root=(struct node *)malloc(sizeof(struct node));
	root->left=NULL;
	root->right=NULL;
	root->info=c[i];
	i++;
	if(c[i]=='(')
	{
		i++;
		root->left=fun();
		root->right=fun();
	}
	preorder(root);
	getch();
	return 0;
}
void preorder(struct node *p)
{
	if(p==NULL)
	return;
	cout<<p->info;
	preorder(p->left);
	preorder(p->right);
}
struct node * fun()
{
	if(c[i]=='.')
	{
		i++;
		return NULL;
	}
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->left=NULL;
	p->right=NULL;
	p->info=c[i];
	i++;
	if(c[i]=='(')
	{
		i++;
		p->left=fun();
		p->right=fun();
		i++;
	}
	return p;
}
