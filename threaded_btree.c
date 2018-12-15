#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
	int status;
	int lthread;
	int rthread;
};
struct tree *root,*p,*q;

void preorder();
void inorder();
void postorder();
struct tree* search(int);
void delt();
void thread();
void inpred();
void insucc();

struct tree *arr[100];
int i=0;
struct tree *stack[10000];
void push(struct tree *);
struct tree *pop();

int top=-1;

int main()
{
	root=p=q=NULL;
	root=(struct tree *)malloc(sizeof(struct tree));
	root->status=0;
	printf("enter root\n");
	scanf("%d",&root->info);
	root->left=root->right=NULL;
	root->lthread=root->rthread=0;
	int ch;
	while(1)
	{
		 printf("do u want 2 continue\n1--yes\n2--no\n");
		 scanf("%d",&ch);
		 if(ch==1)
		 {
				q=root;
				p=(struct tree *)malloc(sizeof(struct tree));
				p->left=p->right=NULL;
				p->lthread=p->rthread=0;
				p->status=0;
				printf("enter data\n");
				scanf("%d",&p->info);
				while(1)
				{
					if(p->info>q->info)
					{
						if(q->right==NULL)
						{
							q->right=p;
							break;
						}
						else
						q=q->right;
					}
					if(p->info<q->info)
					{
						if(q->left==NULL)
						{
							q->left=p;
							break;
						}
						else
						q=q->left;
					}
				}

		 }
		 else
		 break;
	}
	int j;
	for(j=0;j<100;j++)
	arr[j]=NULL;
	inorder(root);
	i=0;
	thread();
	inpred();
	insucc();
	getch();
	return 0;
}

void push(struct tree *t)
{
	if(top==9999)
	{
		printf("over-flow\n");
		return;
	}
	top++;
	stack[top]=t;
}

struct tree *pop()
{
	if(top==-1)
	{
		return NULL;
	}
	return(stack[top--]);
}

void inorder(struct tree *t)
{
	if(t==NULL)
	{
		return;
	}
    inorder(t->left);
	arr[i]=t;
	i++;
	inorder(t->right);
}

void thread()
{
	int j;
	for(j=0;arr[j]!=NULL;j++)
	{
		if(arr[j]->left==NULL)
		{
			if(j!=0)
			{
				arr[j]->lthread=1;
                arr[j]->left=arr[j-1];
			}
		}
		if(arr[j]->right==NULL)
		{
			if(arr[j+1]!=NULL)
			arr[j]->rthread=1;
			arr[j]->right=arr[j+1];
		}
	}
	
}
struct tree* search(int ser)
{
	int ctr=0;
	//printf("enter the search element\n");
	//scanf("%d",&ser);
	p=NULL;
	q=root;
	while(q!=NULL)
	{
	//	p=q;
		if(ser>q->info)
		{
			p=q;
			q=q->right;
		}
		else if(ser<q->info)
		{
			p=q;
			q=q->left;
		}
		else
		{
			printf("search found\n");
			ctr++;
			return q;
		}
	}
	if(ctr==0)
	{
		printf("element nt found\n");
		return NULL;
	}
}

void inpred()
{
	int ch;
	printf("enter d elment\n");
	scanf("%d",&ch);
	struct tree *k=search(ch);
	if(k->lthread!=0)
	printf("%d\n",k->left->info);
	else
	{
		p=k->left;
		while(p->rthread==0)
		p=p->right;
		printf("%d\n",p->info);
	}
}

void insucc()
{
	int ch;
	printf("enter d elment\n");
	scanf("%d",&ch);
	struct tree *k=search(ch);
	if(k->rthread!=0)
	printf("%d\n",k->right->info);
	else
	{
		p=k->right;
		while(p->lthread==0)
		p=p->left;
		printf("%d\n",p->info);
	}
}

