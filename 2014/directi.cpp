#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include<string.h>
using namespace std;

struct tree
{
	char info;
	struct tree *left;
	struct tree * right;
};
struct tree *p,*q,*m,*root;
int k=0;
char s[50];
void post(struct tree *);

int main()
{
	struct tree *que[100];
	int rear=0;
	int front=0;
	int i=0;
	char t[50]="11001010100";
	root=(struct tree*)malloc(sizeof(struct tree));
	root->left=NULL;
	root->right=NULL;
	que[rear]=root;
	while(i<strlen(t))
	{
		if(t[i]=='1')
		{
			que[front]->info='1';
		p=(struct tree *)malloc(sizeof(struct tree));
		p->left=NULL;
		p->right=NULL;
		que[front]->left=p;
		rear++;
		que[rear]=p;
        p=(struct tree *)malloc(sizeof(struct tree));
		p->left=NULL;
		p->right=NULL;
		que[front]->right=p;
		rear++;
		que[rear]=p;
		front++;
		}
		else
		{
			que[front]->info='0';
			front++;
		}
		i++;
	}
	post(root);
	for(i=0;i<k;i++)
	cout<<s[i];
	getch();
	return 0;
}
void post(struct tree *p)
{
	if(p==NULL)
	return;
	post(p->left);
	post(p->right);
	s[k++]=p->info;
}
