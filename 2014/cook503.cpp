#include<stdio.h>

int main()
{
    int t,i,n,temp,a,b,j,k,pro,gcd,lcm,maxi;
    scanf("%d",&t);
    while(t--)
    {
        maxi=-1;
        scanf("%d",&n);
        int arr[n];
        long long int p[n];
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            if(j==0)
                p[j]=arr[j];
            else
                p[j]=p[j-1]*arr[j];
        }
        pro=arr[0];
        j=0;
        k=1;
        while(k<n)
        {
            pro=pro*arr[k];
            a=arr[j];
            b=arr[k];
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
            lcm=pro/gcd;
            if(lcm==pro)
            {
                if(k-j+1>=maxi)
                    maxi=k-j+1;
            }
            else
            {
                while(j<k)
                {
                    a=arr[j];
                    b=arr[k];
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
                    if(gcd>1)
                        break;
                    j=j+1;

                }
                lcm=arr[k]/arr[j];
            }
            j=lcm;
            k=k+1;
        }
        printf("%d\n",maxi);
    }
    return 0;
}
