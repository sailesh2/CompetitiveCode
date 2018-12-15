#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,t,cnt,j;
    long long int n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n==1 || n==0)
            cout<<"NO\n";
        else
        {
            cnt=0;
            j=2;
            while(j<=(int)(ceil(sqrt(n))))
            {
                if(n%j==0)
                {
                    cnt=1;
                    break;
                }
                j++;
            }
            if(cnt==0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
