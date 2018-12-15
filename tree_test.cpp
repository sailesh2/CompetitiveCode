#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
	int status;
};
struct tree *root,*p,*q;
struct tree *stack[100];
void push(struct tree *);
struct tree *pop();
int top=-1;

void preorder(struct tree *);
void inorder(struct tree *);
void postorder(struct tree *);

int main()
{
	root=p=q=NULL;
	root=(struct tree *)malloc(sizeof(struct tree));
	root->left=root->right=NULL;
	printf("enter root\n");
	scanf("%d",&root->info);
	root->status=0;
	q=root;
	int ch1,ch2;
	while(q!=NULL)
	{
		printf("right child of %d\n1--yes\n2--no\n",q->info);
		scanf("%d",&ch1);
		if(ch1==1)
		{
			p=(struct tree*)malloc(sizeof(struct tree));
			p->left=p->right=NULL;
			p->status=0;
			printf("enter data\n");
			scanf("%d",&p->info);
			q->right=p;
			push(p);
		}
		printf("left child of %d\n1--yes\n2--no",q->info);
		scanf("%d",&ch2);
		if(ch2==1)
		{
			p=(struct tree*)malloc(sizeof(struct tree));
			p->left=p->right=NULL;
			p->status=0;
			printf("enter data\n");
			scanf("%d",&p->info);
			q->left=p;
			q=q->left;
		}
		else
		q=pop();
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	getch();
	return 0;
}

void preorder(struct tree *t)
{

	if(t==NULL)
	return;
	{
		printf("%d ",t->info);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(struct tree *t)
{
	if(t==NULL)
	return;

	{
		inorder(t->left);
		printf("%d ",t->info);
		inorder(t->right);
	}
}

void postorder(struct tree *t)
{
	if(t==NULL)
	return;

	{
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->info);
	}
}

void push(struct tree *t)
{
	if(top==99)
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
