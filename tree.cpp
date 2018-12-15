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

void preorder();
void inorder();
void postorder();

int main()
{
	root=p=q=NULL;
	root=(struct tree*)malloc(sizeof(struct tree));
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
	
	preorder();
	inorder();
	postorder();
	
	getch();
	return 0;
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

void preorder()
{
	p=root;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		if(p->right!=NULL)
		push(p->right);
		if(p->left==NULL)
		{
			p=pop();
			if(p==NULL)
			{
				printf("\n");
				return;
			}
		}
		else
		p=p->left;

 }

}

void inorder()
{
	p=root;
	while(1)
	{
		while(p!=NULL)
		{
			push(p);
			p=p->left;
		}
		p=pop();
		while(p->right==NULL)
		{
			printf("%d ",p->info);
			p=pop();
			if(p==NULL)
			{
				printf("\n");
				return;
			}
		}
		printf("%d ",p->info);
		p=p->right;
	}

}

void postorder()
{
	p=root;
	while(1)
	{
		while(p!=NULL&&p->status==0)
		{
			if(p->right!=NULL)
			{
				p->status=1;
				push(p);
			}
			else
			push(p);
			p=p->left;
        }
        p=pop();
        while(p->status==0)
        {
			printf("%d ",p->info);
			p=pop();
			if(p==NULL)
			{
				printf("\n");
				return;
			}
	    }
	    p->status=0;
	    push(p);
	    p=p->right;
        
        
	}
}
