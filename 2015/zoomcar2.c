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


    int n,p1;
    scanf("%d%d",&n,&p1);
    double p=(double)p1/100;
    int two=n/2-n%2;
    int three=n%2;
    double sm=(fact[two+three]/fact[two])*(pow(p,two)*pow(1-p,three));

    for(i=0;i<two/3;i++)
    {
        three=three+2;
        two=two-3;
        sm=sm+(fact[two+three]/fact[two])*(pow(p,two)*pow(1-p,three));
    }
    printf("%.6lf",sm);
    return 0;
}
