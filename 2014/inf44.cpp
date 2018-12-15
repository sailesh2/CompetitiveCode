#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	int dig;
	dig=(int)floor(log10(n));
	long long int p2=1,prod=2;
	while(dig!=0)
	{
		if(dig%2==1)
		{
			p2=p2*prod;
		}
		prod=prod*prod
		dig=dig/2
	}
	long long int p11=1,s=0;
	while(n!=0)
	{
        s=s+(n%10)*(p11%(pow(10,9)+7))*(p2%(pow(10,9)+7));
	    p2=p2/2;
    	p11=(p11*11);
    	n=n/10;
	}
	cout<<s%(pow(10,9)+7);
	return 0;
}
