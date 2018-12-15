#include<stdio.h>

int main()
{
    int i;
    long long int fact[100001];
    fact[0]=1;
    for(i=1;i<=100000;i++)
    {
        fact[i]=fact[i-1]*i;
    }



    int t,n,j,x;
    scanf("%d",&t);
    long long int p=1,sm=0;
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        sm=sm+n;
        p=p*fact[n];
        for(j=0;j<n;j++)
        {
            scanf("%d",&x);
        }
    }
    printf("%lld",(fact[sm]/p)%1000000007);
    return 0;
}
