#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int i,t,g,f,x,y,el,div;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        long long int arr[2][2];
        scanf("%lld",&el);
        scanf("%lld%lld%lld%lld",&arr[0][0],&arr[0][1],&arr[1][0],&arr[1][1]);
        scanf("%lld%lld",&x,&y);
        if(y>x)
        {
            div=pow(2,ceil(log2(y)))/2;
        }
        else
        {
            div=pow(2,ceil(log2(x)))/2;
        }
        long long int p=1;
        while(div>=1)
        {
            g=ceil(float(x)/div);
            f=ceil(float(y)/div);
            p=p*arr[g-1][f-1];
           x=(x-1)%div+1;
           y=(y-1)%div+1;
           div=div/2;
        }
        printf("%lld\n",p*el);
    }
    return 0;
}
