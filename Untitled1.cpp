#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>
long long int factorial(long long int);
int main()
{
    long long int x,y,n,ctr=0;
    scanf("%lld",&n);
    long long int fact=1,i;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    y=fact+1;
    printf("%lld\n",y);
    while(1)
    {
        x=(fact*y)/(y-fact);
        if(ceil(x)==fact)
            break;
        if((fact*y)%(y-fact)==0)
            ctr++;
        y++;
    }
    printf("%lld",ctr);
    getch();
    return 0;
}
