#include<stdio.h>
#include<conio.h>

void call1(int,int);
void call();
int arr[8][2];
int a,b;
int ctr=0,ctr1=0;
int n;
int top=-1;
int stack[100][2];
void push(int,int);

int main()
{

	printf("enter knight's pos\n");
	scanf("%d%d",&a,&b);
	printf("enter no.of moves\n");
	scanf("%d",&n);

	int i,j;

	call1(a,b);
	call();

getch();
return 0;
}


void call()
{
	int i;
	int k,l;
int cnt=0;
	while(cnt<1000)
	{

	if(ctr<n-1)
	{

        k=stack[top][0];
     	l=stack[top][1];
	    top--;
	    if(top==-1)
		return;
	    if(k<8&&k>=0&&l<8&&l>=0)
	    printf("%d%d ",k,l);


		ctr++;
		call1(k,l);

	}
	else
	{
		
        k=stack[top][0];
	    l=stack[top][1];
	    if(k<8&&k>=0&&l<8&&l>=0)
	    printf("%d%d ",k,l);
	    top--;
if(top==-1)
return;
	    ctr1++;
	    if(ctr1==7)
	    {
			ctr1=0;
			ctr--;
	    }
	}
cnt++;
  }
}



void push(int x,int y)
{
	top++;
	stack[top][0]=x;

	stack[top][1]=y;

}

void call1(int a1,int b1)
{
	int i;

	arr[0][0]=a1+2;
	arr[0][1]=b1+1;
	arr[1][0]=a1-2;
	arr[1][1]=b1+1;
	arr[2][0]=a1+2;
	arr[2][1]=b1-1;
	arr[3][0]=a1-2;
	arr[3][1]=b1-1;
	arr[4][0]=a1+1;
	arr[4][1]=b1+2;
	arr[5][0]=a1-1;
	arr[5][1]=b1+2;
	arr[6][0]=a1+1;
	arr[6][1]=b1-2;
	arr[7][0]=a1-1;
	arr[7][1]=b1-2;

	for(i=0;i<8;i++)
	{

			push(arr[i][0],arr[i][1]);

	}
}
