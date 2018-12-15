#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;

int main()
{
	long long int i,j,t,ctr,cnt,l,sm,k,save;
	cin>>t;
	for(i=0;i<t;i++)
	{
		ctr=0;
		cnt=0;
		sm=0;
		save=0;
		long long int brr[10000]={0};
		string x,y;
		cin>>x>>y;
		long long int crr[300]={0},err[300]={0};
		for(j=0;j<x.length();j++)
		crr[(int)x[j]]++;
		for(j=0;j<y.length();j++)
		{
			if(crr[(int)y[j]]>0)
			{
				if(cnt==0)
				{
					cnt=1;
					ctr=1;
					save=0;
					k=0;
					brr[k++]=int(y[j]);
					err[brr[k-1]]++;
				}
				else
				{
					if(err[(int)y[j]]>0)
					{
						if(err[(int)y[j]]<crr[(int)y[j]])
						{
							ctr++;
						}
						else
						{
							for(l=save;l<k;l++)
							{
								if(brr[l]==(int)y[j])
								{
									save=l+1;
									break;
								}
							}
							for(l=0;l<300;l++)
							err[l]=0;
							for(l=save;l<k;l++)
							err[brr[l]]++;
							ctr=k-save+1;
						}
						brr[k++]=(int)y[j];
						err[brr[k-1]]++;
					}
					else
					{
						brr[k++]=(int)y[j];
						err[brr[k-1]]++;
						ctr++;
					}
				}
			    if(ctr==x.length())
			    {	sm=1;
					cout<<"YES\n";
					break;
			    }
			}
			else
			cnt=0;
		}
		if(sm==0)
		cout<<"NO\n";
	}
	getch();
	return 0;
}
