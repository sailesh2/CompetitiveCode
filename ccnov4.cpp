#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

long long int power(int,int,int);
int main()
{
    int i,t,j,n,q,k,m,l,num,h,ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int var=0;
        cin>>n>>m>>q;
        int pf[1000]={0};
        int st[1000]={0};
        for(j=2;j<=n;j++)
        {
            num=j;
            ctr=0;
            while (num%2 == 0)
            {
               if(pf[2]==0)
                    st[var++]=2;
               ctr++;
               num = num/2;
            }
            pf[2]=pf[2]+ctr*j;
            ctr=0;
            for (l = 3; l <= sqrt(num); l = l+2)
            {
                ctr=0;
                while (num%l == 0)
                {
                    if(pf[l]==0)
                        st[var++]=l;
                    ctr++;
                    num = num/l;
                }
                pf[l]=pf[l]+ctr*j;
            }
            if (num > 2)
            {
                if(pf[num]==0)
                    st[var++]=num;
                pf[num]=pf[num]+j;
            }
        }
        for(j=0;j<q;j++)
        {
            int st1[1000]={0};
            int st2[1000]={0};
            cin>>k;
            for(h=2;h<=k;h++)
            {
                num=h;
                ctr=0;
                while (num%2 == 0)
                {
                   ctr++;
                   num = num/2;
                }
                st1[2]=st1[2]*h;
                for (l = 3; l <= sqrt(num); l = l+2)
                {
                    ctr=0;
                    while (num%l == 0)
                    {
                        ctr++;
                        num = num/l;
                    }
                    st1[l]=st1[l]+ctr*h;
                }
                if (num > 2)
                {
                    st1[num]=st1[num]+h;
                }
            }
            for(h=2;h<=n-k;h++)
            {
                num=h;
                ctr=0;
                while (num%2 == 0)
                {
                   ctr++;
                   num = num/2;
                }
                st2[2]=st2[2]+ctr*h;
                for (l = 3; l <= sqrt(num); l = l+2)
                {
                    ctr=0;
                    while (num%l == 0)
                    {
                        ctr++;
                        num = num/l;
                    }
                    st2[l]=st2[l]+ctr*h;
                }
                if (num > 2)
                {
                    st2[num]=st2[num]+h;
                }
            }
            long long int p=1,rt;
            for(l=0;l<=sqrt(n);l++)
            {
                //cout<<st[l]<<" "<<st2[st[l]]<<" \n";
                if(pf[st[l]]>0)
                {
                    rt=power(st[l],pf[st[l]]-st1[st[l]]-st2[st[l]],m);
                    //cout<<l<<" "<<rt<<"\n";
                    p=((p%m)*(rt%m))%m;
                }
            }
            cout<<p<<"\n";
        }
    }
    return 0;
}

long long int power(int a,int b,int m)
{
    int num=b,k=0,l;
    int bin[1000];
    while(num!=0)
    {
        bin[k++]=num%2;
        num=num/2;
    }
    long long int p=1;
    if(bin[0]==1)
        p=a;
    l=1;
    while(l<=k)
    {
        a=((a%m)*(a%m))%m;
        if(bin[l]==1)
            p=((p%m)*(a%m))%m;
        l++;
    }
    return p;
}
