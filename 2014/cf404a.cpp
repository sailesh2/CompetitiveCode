#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int i,n,j,ctr1=0,ctr2=0,cnt=0;
	cin>>n;
	char ch[n][n],chk,chk1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>ch[i][j];
			if(i==j || (i+j)==n-1)
			{
				if(ctr1==0)
				{
					ctr1++;
					chk=ch[i][j];
				}
				else
				{
					if(chk!=ch[i][j] || chk==chk1)
					cnt=1;
				}
			}
			else
			{
				if(ctr2==0)
				{
					ctr2++;
					chk1=ch[i][j];
				}
				else
				{
					if(chk1!=ch[i][j] || chk1==chk)
					cnt=1;
				}
			}
		}
	}
	if(cnt==1)
	cout<<"NO";
	else
	cout<<"YES";
	return 0;
}
