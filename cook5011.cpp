#include<stdio.h>
int main()
{
    int t,cnt;
    int n,i,k,gcd,temp,a,b;

    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    cnt=0;
    gcd=x[0];
    k=1;
    while(k<n)
    {
        a=gcd;
        b=x[k];
        if(a>=b)
        {
            while(1)
            {
                if(a%b==0)
                {
                    gcd=b;
                    break;
                }
                temp=a;
                a=b;
                b=temp%b;
            }
        }
        else
        {
            while(1)
            {
                if(b%a==0)
                {
                    gcd=a;
                    break;
                }
                temp=b;
                b=a;
                a=temp%a;
            }
        }
        if(gcd==1)
        {
            cnt=1;
            break;
        }
        k++;
    }
    if(cnt==1)
        printf("%d\n",n);
    else
        printf("-1\n");
    }
    return 0;
}
