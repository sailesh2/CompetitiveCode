#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int fun(long long int,long long int);

int main()
{
	printf("dljhg");
    /*long long int t,i,n,ans,r;
    scanf("%lld",&t);
    printf("%ldjkhv");
    for(i=0;i<t;i++)
    {
        scanf("%lld%lld",&n,&r);
        printf("%lld",r);
        printf("jdshvg");
        ans=fun(n,r);
        printf("%lld\n",ans);
    }*/
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
