#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>

long long int fun(long long int,long long int);

int main()
{
	long long int t,i,n,ans,r;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld%lld",&n,&r);
        ans=fun(n,r);
        printf("%lld\n",ans);
    }
    getch();
    return 0;
}
long long int fun(long long int n,long long int r)
{
    if(n==r)
        return 1;
    if(r==1)
        return n;
    if(r==0)
        return 1;
    long long int ans= fun(n-1,r)+fun(n-1,r-1);
    return ans;
}
