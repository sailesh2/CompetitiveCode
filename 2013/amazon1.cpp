#include<stdio.h>

int min=100000;
int max=-1;
int top=-1;
int ctr=0;
int m=-1;
int arr[10000]={0};
int stack[10000];
void push(int);
int pop();
int middle();
void delt();
int main()
{
	int c,d;
	while(1)
	{
        printf("1--push\n2--pop\n3--middle\n4--delete middle\n5--stop\n");
	scanf("%d",&c);

	switch(c)
	{
		case 1:printf("enter element\n");
		scanf("%d",&d);
		push(d);
		break;
		case 2:d=pop();
		printf("popped elememt--%d\n",d);
		break;
		case 3:
			d=middle();
			printf("middle element --%d\n",d);
			break;
	   case 4:
			delt();
			break;
	}
	if(c==5)
	break;
    }
    return 0;
}

void push(int val)
{
	if(top==9999)
	{
		printf("overflow\n");
		return;
	}
	if(ctr%2==0)
	{
		if(arr[stack[m+1]]==0)
		m++;
		else
		m=max+1;
	}
	ctr++;
	top++;
	stack[top]=val;
}

int pop()
{
	if(top==-1)
	{
		printf("underflow\n");
		return 0;
	}
	if(ctr%2!=0)
	{
		if(arr[stack[m-1]]==0)
		m--;
		else
		m=min-1;
	}
	ctr--;
	int a=stack[top];
	top--;
	return a;
}

int middle()
{
	if(m==-1)
	{
		printf("middle not found\n");
		return 0;
	}
	return stack[m];
}

void delt()
{
	if(m==-1)
	{
		return;
	}
   if(ctr%2==0)
   {
		if(arr[stack[m+1]]==0)
		{
			arr[stack[m]]=1;
			if(m<min)
			min=m;
			if(m>max)
			max=m;
			m++;
		}
		else
		{
			arr[stack[m]]=1;
			if(m<min)
			min=m;
			if(m>max)
			max=m;
			m=max+1;
		}
   }
   else
   {
		if(arr[stack[m-1]]==0)
		{
			arr[stack[m]]=1;
			if(m<min)
			min=m;
			if(m>max)
			max=m;
			m--;
		}
		else
		{
            arr[stack[m]]=1;
			if(m<min)
			min=m;
			if(m>max)
			max=m;
			m=min-1;
		}
   }
   ctr--;
}
