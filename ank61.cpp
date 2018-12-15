#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,t,j,cnt,ctr;
    long long int n;
    cin>>t;
    for(j=0;j<t;j++)
    {
        cin>>n;
        int crr[1000]={0};
        cnt=0;
        ctr=0;
        while (n%2 == 0)
        {
            if(ctr>2)
            {
                cnt=1;
                break;
            }
           // printf("%d ", 2);
           if(crr[2]==1)
           {
               cnt=1;
               break;
           }
           if(crr[2]==0)
           {
               ctr++;
               crr[2]=1;
           }

            n = n/2;
        }

        for (i = 3; i <= sqrt(n); i = i+2)
        {
            while (n%i == 0)
            {
                //printf("%d ", i);
                if(crr[i]==1)
                {
                    cnt=1;
                    break;
                }
                if(crr[i]==0)
                {
                    ctr++;
                    crr[i]=1;
                }
                n = n/i;
            }
            if(ctr>2)
            {
                cnt=1;
                break;
            }
        }
        if (n > 2)
            //printf ("%d ", n);
        if(cnt==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

