#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;


long long int fun(vector<int> a,vector<int> b);

int main()
{
	int i,n,x;
	cin>>n;
	vector<int> a,b;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}

	for(i=0;i<n;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	cout<<fun(b,a);
	return 0;
}
long long int fun(vector<int> a,vector<int> b)
{
      int i,j,n,ctr;
      n = a.size();
      vector<int> tot;

      for (i=0;i< n;i++)
        tot.push_back(a[i]);

      for (i=0;i< n;i++)
        tot.push_back(b[i]);
      sort(tot.begin(), tot.end());
      vector<int> has;
      vector<int>::iterator it1,it2;
      for(i=0;i<=2*n;i++)
        has.push_back(0);
      long long int ans = 0;
      for (i=n-1;i>=0;i--)
      {
            it1=lower_bound(tot.begin(), tot.end(), b[i]);
            it2= tot.begin();
            ctr=it1-it2;
            for (j=ctr;j;j=j-(j & -j))
            {
                  ans = ans+has[j];
            }

            it1=lower_bound(tot.begin(), tot.end(), a[i]);
            it2= tot.begin();
            ctr=it1-it2+1;
            for (j =ctr;j<=2*n;j=j+(j & -j))
            {
                  has[j]++;
            }
      }
      return ans;
}

