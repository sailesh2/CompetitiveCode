#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

char *inf;
char *stack;
int *stack1;
char *post;
void inf_post();
void push(char);
void push1(int);
int pop1();
char pop();
void eval_post();
int top=-1;
int j=-1;
int n;
int priority(char);

int main()
{
	int i=0;
	printf("enter limit\n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("-ve no. not accepted\n");
		return 0;
	}
	printf("enter expression\n");
	
	inf=(char *)malloc((n+1)*sizeof(char));
	stack=(char *)malloc((n+1)*sizeof(char));
    post=(char *)malloc(n*sizeof(char));
    stack1=(int *)malloc(n*sizeof(int));
	scanf("%s",inf);
	while(inf[i]!='\0')
	{
		i++;
	}
	inf[i]=')';
	i++;
	inf[i]='\0';
	/*for(;i<n+1;i++)
	{
        inf[i]='\0';
	}*/
	

	stack[++top]='(';
	/*for(i=1;i<n+1;i++)
	{
		stack[i]='\0';
	}*/
	
	
	/*for(i=0;inf[i]!='\0';i++)
	{
		printf("%c",inf[i]);
	}*/
	printf("\n");
	
	int k;
	for(k=0;k<n;k++)
	{
		post[k]='\0';
	}
	inf_post();
	for(k=0;post[k]!='\0';k++)
	{
		printf("%c",post[k]);
	}
		printf("\n");
		top=-1;
	eval_post();
	getch();
	return 0;
	
	
}

void inf_post()
{

	int i,k;
	for(i=0;inf[i]!='\0';i++)
	{
		switch(inf[i])
		{
			case '(':
						push(inf[i]);
						break;
			case ')':
						while(stack[top]!='(')
						{
							post[++j]=pop();
							//for(k=j+1;k<n;k++)
							//post[k]='\0';
						}
						top--;
						break;
			case '^':
			case '/':
			case '*':
		    case '+':
			case '-':
					   if(priority(stack[top])<priority(inf[i]))
					   push(inf[i]);
					   else
					   {
							while((priority(stack[top])>=priority(inf[i])))
							{
								post[++j]=pop();
							//	for(k=j+1;k<n;k++)
							//post[k]='\0';
							}
							push(inf[i]);
					    }
	    }
	    if((int)inf[i]<=57&&(int)inf[i]>=48)
		//if(inf[i]=='2'||inf[i]=='3'||inf[i]=='4')
	    {
			post[++j]=inf[i];
			//for(k=j+1;k<n;k++)
		    //post[k]='\0';
	    }
   }
}

int priority(char c)
{
	switch(c)
	{
		case '^':return 3;
		case '/':
		case '*':
				  return 2;
		case '+':
		case '-':
				  return 1;
		case '(':return 0;

	}
}

void push(char c)
{
	int k;
	if(top==n)
	{
		printf("OverFlow\n");
		return;
	}
	stack[++top]=c;
	/*for(k=(top+1);k<n;k++)
	{stack[k]='\0';
	}*/
}

char pop()
{

	if(top==-1)
	{
		printf("UnderFlow\n");
		/*for(k=0;post[k]!='\0';k++)
		{
			printf("%c",post[k]);
		}*/

		getch();
		exit(0);
	}
	return(stack[top--]);
}

void eval_post()
{
	int i,a,b,temp;
	for(i=0;post[i]!='\0';i++)
	{
		if((int)post[i]<=57&&(int)post[i]>=48)
		 //if(isalpha(post[i]))
		{
			push1((int)post[i]-48);
		}
		else
		{
			a=pop1();
			b=pop1();
			switch(post[i])
			{
				case '^':
					  temp=pow(b,a);
					  push1(temp);
					  break;
				case '/':
					  temp=b/a;
					  push1(temp);
					  break;
                case '*':
					  temp=b*a;
					  push1(temp);
					  break;
                case '+':
					  temp=b+a;
					  push1(temp);
					  break;
			    case '-':
					  temp=b-a;
					  push1(temp);
					  break;


			}
			

		}

    }
    printf("%d\n",stack1[top]);
}

void push1(int c)
{
	int k;
	if(top==n)
	{
		printf("OverFlow\n");
		return;
	}
	stack1[++top]=c;

}

int pop1()
{

	if(top==-1)
	{
		printf("UnderFlow\n");
		/*for(k=0;post[k]!='\0';k++)
		{
			printf("%c",post[k]);
		}*/

		getch();
		exit(0);
	}
	return(stack1[top--]);
}
