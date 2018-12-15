//..Ronak Kumar Meher
//Roll no: 111CS0138
//program to find the shortest distance using dijkstra's algorithm..

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void path(int,int);
void dij(int);
int min();
void creat();
int n;
int adj[MAX][MAX];
int pre[MAX];
int pl[MAX];
int st[MAX];
int main()
{
	int s,v;
	creat();
	printf("enter the source : ");
	scanf("%d",&s);
	dij(s);
	while(1)
	{
		printf("enter the destination : (0 to exit)");
		scanf("%d",&v);
		if(v==0)
		  break;
		else
		    path(s,v);

	}
}
void dij(int s)
{
	int i,c;
	for(i=0;i<n;i++)
	{
		pre[i]=-1;
		pl[i]=100;
		st[i]=0;
	}
	pl[s]=0;
	while(1)
	{
		c=min();
		if(c==-1)
		    return;
		st[c]=1;
		for(i=0;i<n;i++)
		{
			if(adj[c]!=0 && st[i]==0)
			{
				if(pl[c]+adj[c][i]<pl[i])
				{
					pre[i]=c;
					pl[i]=pl[c]+adj[c][i];
				}
			}
		}
	}
}
int min()
{
	int i;
	int min=100;
	int k=0;
	for(i=0;i<n;i++)
	{
		if(st[i]=0 && pl[i]<min)
		{
			min=pl[i];
			k=i;
		}
	}
	return k;
	
}
void path(int s,int v)
{
	int i,u;
	int p[MAX];
	int sd=0,c=0;
	while(v!=s)
	{
		c++;
		pl[c]=v;
		sd=sd+adj[u][v];
		v=u;
	}
	c++;
	pl[c]=s;
	printf("shortest path is : ");
	for(i=c;i>=0;i--)
	{
		printf("%3d",pl[i]);
	}
	printf("shortest distance is : ",sd);
	
}
void creat()
{
	int i,max,s,d,wt;
	printf("enter the number of vertices : ");
	scanf("%d",&n);
	max=n*(n-1);
	for(i=0;i<max;i++)
	{
		printf("enter the edge %d :(source and destination):",i);
		scanf("%d %d",&s,&d);
		if(s==-1 && d==-1)
			break;
		printf("enter the weight : ");
		scanf("%d",wt);
		if(s>n || d>n || s<0 || d<0)
		{
			printf("invalid edge..\n");
			i--;
			
		}
		else
		adj[s][d]=wt;
	}
}
