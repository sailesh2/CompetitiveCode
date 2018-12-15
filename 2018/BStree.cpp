#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
	int status;
};
struct tree *root,*p,*q;

void preorder();
void inorder();
void postorder();
struct tree* search(int);
void delt();

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
	int s;
	struct tree *k1;
	while(1)
	{
		printf("enter choice\n1--pre\n2--in\n3--post\n4--search\n6--delt\n5--exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:preorder();
				  break;
			case 2:inorder();
				  break;
			case 3:postorder();
				  break;
			case 4:
				   printf("enter the search element\n");
				   scanf("%d",&s);
				   k1=search(s);
			
				  break;
			case 6:delt();
				  break;
		}
		if(ch==5)
		break;
	}
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
			return p;
		}
	}
	if(ctr==0)
	{
		printf("element nt found\n");
		return NULL;
	}
}

void delt()
{
	int d;
	printf("enter delete elemnt\n");
	scanf("%d",&d);
	struct tree *s,*k=search(d);
if(k==NULL&&root->left==NULL&&root->right==NULL)
{
	root=NULL;
	return;
}
//printf("%d\n",k->info);
if(k!=NULL)
{
	if(k->left!=NULL&&k->left->info==d)
	s=k->left;
	else
	s=k->right;
	if(s->left==NULL&&s->right==NULL)
	{
		if(k->left==s)
		k->left=NULL;
		else
		k->right=NULL;
		free(s);
	}
	else if(s->left==NULL||s->right==NULL)
	{
		if(k->left==s)
		{
			if(s->left!=NULL)
			k->left=s->left;
			else
			k->left=s->right;
		}
		else
		{
            if(s->left!=NULL)
			k->right=s->left;
			else
			k->right=s->right;
		}
		free(s);
	}
	else
	{
		struct tree *m1=s->right,*m2;
		while(m1->left!=NULL)
		{
			m2=m1;
			m1=m1->left;
		}
		s->info=m1->info;
		if(m1->right==NULL)
		{
			printf("hr\n");
			m2->left=NULL;
			free(m1);
		}
		else
		{
            printf("hr\n");
			m2->left=m1->right;
			free(m1);
		}
	}
}
else
{
	int ctr=0;
		s=root;
    	struct tree *m1=s->right,*m2;
		while(m1->left!=NULL)
		{
			m2=m1;
			m1=m1->left;
			ctr++;
		}
		s->info=m1->info;
		if(m1->right==NULL)
		{
			printf("hr\n");
			if(ctr>0)
			m2->left=NULL;
			free(m1);
		}
		else
		{
            printf("hr2\n");
			if(ctr>0)
			m2->left=m1->right;
			else
			s->right=m1->right;
			free(m1);
		}
}
}
