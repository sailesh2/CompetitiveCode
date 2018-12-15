#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
	int balance;
};

struct tree *insert(struct tree *,int);
struct tree *left_check(struct tree *,int *);
struct tree *left_balance(struct tree *);
struct tree *right_check(struct tree *,int *);
struct tree *right_balance(struct tree *);
struct tree *rotate_left(struct tree *);
struct tree *rotate_right(struct tree *);
struct tree *delt(struct tree *,int);
struct tree *left_check_delt(struct tree *,int *);
struct tree *left_balance_delt(struct tree *,int *);
struct tree *right_check_delt(struct tree *,int *);
struct tree *right_balance_delt(struct tree *,int *);

struct tree *create(struct tree *);
void disp(struct tree *);

int main()
{
	struct tree *root;
	root=(struct tree *)malloc(sizeof(struct tree));
	printf("enter root\n");
	scanf("%d",&root->info);
	root->left=root->right=NULL;
	root->balance=0;

	int ch,c;
	while(1)
	{
		printf("1--create\n2--insert\n3--disp\n4--delete\n5--exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			break;
			case 2:printf("enter data\n");
			scanf("%d",&c);
			root=insert(root,c);
			break;
			case 3:disp(root);
			printf("\n");
			break;
			case 4:printf("enter data\n");
			scanf("%d",&c);
			root=delt(root,c);
			break;
			
		}
		if(ch==5)
		break;
		
	}
	getch();
	return 0;
}

struct tree *create(struct tree *pptr)
{
	int c,d;
	while(1)
	{
		printf("enter data\n");
	    scanf("%d",&d);
	    pptr=insert(pptr,d);
	    printf("1--continue\n2--discontinue\n");
	    scanf("%d",&c);
	    if(c==2)
	    break;
	}
	return pptr;
	
}

struct tree *insert(struct tree *pptr,int key)
{
	static int taller;
	if(pptr==NULL)
	{
		pptr=(struct tree *)malloc(sizeof(struct tree));
		pptr->left=pptr->right=NULL;
		pptr->info=key;
		pptr->balance=0;
		taller=0;
	}
	else if(key<pptr->info)
	{
		pptr->left=insert(pptr->left,key);
		if(taller==0)
		pptr=left_check(pptr,&taller);
	}
	else if(key>pptr->info)
	{
		pptr->right=insert(pptr->right,key);
		if(taller==0)
		pptr=right_check(pptr,&taller);
	}
	else
	{
		printf("DUPLICATE ELEMENT\n");
		taller=1;
	}
	return pptr;
}

struct tree *left_check(struct tree *pptr,int *taller)
{
	switch(pptr->balance)
	{
		case 0:pptr->balance=1;
		break;
		case -1:pptr->balance=0;
		*taller=1;
		break;
		case 1:pptr=left_balance(pptr);
		*taller=1;
		break;
	}
	return pptr;
}

struct tree *left_balance(struct tree *pptr)
{
	struct tree *aptr,*bptr;
	aptr=pptr->left;
	if(aptr->balance==1)
	{
		aptr->balance=0;
		pptr->balance=0;
		pptr=rotate_right(pptr);
	}
	else
	{
		bptr=aptr->right;
		switch(bptr->balance)
		{
			case -1:pptr->balance=0;
			aptr->balance=1;
			break;
			case 1:pptr->balance=-1;
			aptr->balance=0;
			break;
			case 0:pptr->balance=0;
			aptr->balance=0;
			break;
		}
		bptr->balance=0;
		pptr->left=rotate_left(aptr);
		pptr=rotate_right(pptr);
	}
	return pptr;
}

struct tree *rotate_right(struct tree *pptr)
{
	struct tree *aptr=pptr->left;
	pptr->left=aptr->right;
	aptr->right=pptr;
	return aptr;
}

struct tree *rotate_left(struct tree *pptr)
{
	struct tree *bptr=pptr->right;
	pptr->right=bptr->left;
	bptr->left=pptr;
	return bptr;
}

struct tree *right_check(struct tree *pptr,int *taller)
{
	switch(pptr->balance)
	{
		case 0:pptr->balance=-1;
		break;
		case 1:pptr->balance=0;
		*taller=1;
		break;
		case -1:pptr=right_balance(pptr);
		*taller=1;
		break;
	}
	return pptr;
}

struct tree *right_balance(struct tree *pptr)
{
	struct tree *aptr,*bptr;
	bptr=pptr->right;
	if(bptr->balance==-1)
	{
		bptr->balance=0;
		pptr->balance=0;
		pptr=rotate_left(pptr);
	}
	else
	{
		aptr=bptr->left;
		switch(aptr->balance)
		{
			case -1:pptr->balance=1;
			bptr->balance=0;
			break;
			case 1:pptr->balance=0;
			bptr->balance=-1;
			break;
			case 0:pptr->balance=0;
			bptr->balance=0;
			break;
		}
		aptr->balance=0;
		pptr->right=rotate_right(bptr);
		pptr=rotate_left(pptr);
	}
	return pptr;
}


void disp(struct tree *pptr)
{
	if(pptr==NULL)
	return;
	disp(pptr->left);
	printf("%d balance-- %d  ",pptr->info,pptr->balance);
	disp(pptr->right);
}

struct tree *delt(struct tree *pptr,int key)
{
	int shorter=0;
	if(pptr==NULL)
	{
		printf("not found\n");
		shorter=1;
	}
	else if(key<pptr->info)
	{
		pptr->left=delt(pptr->left,key);
		if(shorter==0)
		pptr=left_check_delt(pptr,&shorter);
	}
	else if(key>pptr->info)
	{
		pptr->right=delt(pptr->right,key);
		if(shorter==0)
		pptr=right_check_delt(pptr,&shorter);
		
	}
	else
	{
		if(pptr->left!=NULL&&pptr->right!=NULL)
		{
			struct tree *succ,*par;
			succ=pptr->right;
			par=pptr;
			while(succ->left!=NULL)
			{
				par=succ;
				succ=succ->left;
			}
			pptr->info=succ->info;
			pptr->right=delt(pptr->right,succ->info);
			
		}
		else
		{
			struct tree *tmp=pptr;
			if(pptr->left==NULL&&pptr->right==NULL)
			{
				pptr=NULL;
			}
			else
			{
				if(pptr->left!=NULL)
				pptr=pptr->left;
				else
				pptr=pptr->right;
			}
			free(tmp);
		}

	}
	return pptr;
}

struct tree *left_check_delt(struct tree *pptr,int *shorter)
{
	switch(pptr->balance)
	{
		case 0:pptr->balance=-1;
		*shorter=1;
		break;
		case 1:pptr->balance=0;
		break;
		case -1:pptr=left_balance_delt(pptr,shorter);
		break;
		
	}
	return pptr;
}

struct tree *left_balance_delt(struct tree *pptr,int *shorter)
{
	struct tree *aptr,*bptr;
	bptr=pptr->right;
	if(bptr->balance==0)
	{
		pptr->balance=-1;
		bptr->balance=1;
		pptr=rotate_left(pptr);
		*shorter=1;
	}
	else if(bptr->balance==-1)
	{
		pptr->balance=0;
		bptr->balance=0;
		pptr=rotate_left(pptr);
	}
	else
	{
		aptr=bptr->left;
		switch(aptr->balance)
		{
			case 0:pptr->balance=0;
			bptr->balance=0;
			break;
			case 1:pptr->balance=0;
			bptr->balance=-1;
			break;
			case -1:pptr->balance=1;
			bptr->balance=0;
			break;
			
		}
		aptr->balance=0;
		pptr->right=rotate_right(bptr);
		pptr=rotate_left(pptr);
	}
	return pptr;
}



struct tree *right_check_delt(struct tree *pptr,int *shorter)
{
	switch(pptr->balance)
	{
		case 0:pptr->balance=1;
		*shorter=1;
		break;
		case -1:pptr->balance=0;
		break;
		case 1:pptr=right_balance_delt(pptr,shorter);
		break;

	}
	return pptr;
}

struct tree *right_balance_delt(struct tree *pptr,int *shorter)
{
	struct tree *aptr,*bptr;
	aptr=pptr->left;
	if(aptr->balance==0)
	{
		pptr->balance=1;
		aptr->balance=-1;
		pptr=rotate_right(pptr);
		*shorter=1;
	}
	else if(aptr->balance==1)
	{
		pptr->balance=0;
		aptr->balance=0;
		pptr=rotate_right(pptr);
	}
	else
	{
		bptr=aptr->right;
		switch(bptr->balance)
		{
			case 0:pptr->balance=0;
			aptr->balance=0;
			break;
			case 1:pptr->balance=-1;
			aptr->balance=0;
			break;
			case -1:pptr->balance=0;
			aptr->balance=1;
			break;

		}
		bptr->balance=0;
		pptr->left=rotate_left(aptr);
		pptr=rotate_right(pptr);
	}
	return pptr;
}
