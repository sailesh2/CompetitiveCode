#include <iostream>
using namespace std;

int main()
{
	int i,n,k,q,d,p=1;
	cin>>n>>k;
	long long int arr[10000]={0};
	for(i=1;i<10000;i++)
	{
		p=p*n;
		arr[i]=p;
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>d;
		cout<<(long long int)(((arr[d]*(n-1-k)+k)/(n-1))%1000000007)<<"\n";
	}
	return 0;
}
