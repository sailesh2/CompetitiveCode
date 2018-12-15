#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

class ThePalindrome
{
	public:
	int dp[100][100];
	int find(string s)
	{
		int i,j;
		for(i=0;i<100;i++)
		{
			for(j=0;j<100;j++)
			{
				if(i==j)
					dp[i][j]=0;
				else if(j==i+1)
				{
					if(s[i]==s[j])
						dp[i][j]=0;
					else
						dp[i][j]=1;
				}
				else
					dp[i][j]=-1;
			}
		}
		return s.length()+fun(0,s.length()-1,s.length(),s);
	}
	int fun(int i,int j,int lt,string s)
	{
		if(dp[i][j]!=-1)
			return dp[i][j];
		int val=1000000;
		if(s[i]==s[j])
		{
			if(i+1<=j-1)
			{
				if(dp[i+1][j-1]==-1)
				val=fun(i+1,j-1,lt,s);
				else
				val=dp[i+1][j-1];
			}
		}
		else
		{
			if(i+1<=j)
			{
			if(dp[i+1][j]==-1)
			val=fun(i+1,j,lt,s);
			else
			val=dp[i+1][j];
			}
			if(i<=j-1)
			{
			if(dp[i][j-1]==-1)
			val=min(val,fun(i,j-1,lt,s))+1;
			else
			val=min(val,dp[i][j-1])+1;
			}
		}
		dp[i][j]=val;
		return val;
	}

};
