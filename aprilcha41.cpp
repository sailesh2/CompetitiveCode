#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>
#include<map>
#include<iterator>

using namespace std;

int main()
{
	long long int i,t,n,j,k,prod,tot,s,rem,sum,root,save[3000]={0};
	map<long long int,long long int> mapk;
	map<long long int,long long int>::iterator it;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		tot=0;
		if(save[n]!=0)
		cout<<save[n]<<"\n";
		else
		{
			for(j=1;j<=n/2;j++)
			{
	            sum=0;
				rem=n-j;
				prod=rem*j;
				if(mapk.count(prod)!=0)
				{
                    it=mapk.find(prod);
					root=(long long int)ceil(sqrt(prod))-1;
					if(j!=rem)
					tot=tot+(it->second-root)*4+root*2;
					else
					tot=tot+(it->second-root)*2+root;
				}
				else
				{
					k=1;
					while(1)
					{
						if(k*k>=prod)
						break;
						s=(long long int)ceil((float)prod/k)-1-(k-1);
						sum=sum+s;
						if(j!=rem)
						tot=tot+4*(s-1)+2;
						else
						tot=tot+2*(s-1)+1;
						k=k+1;
						//cout<<tot<<"\n";
					}
						//cout<<tot<<"\n";
						mapk.insert(make_pair(prod,sum));
				}
			}
			save[n]=tot;
			cout<<tot<<"\n";
		}
	}
getch();
return 0;
}
