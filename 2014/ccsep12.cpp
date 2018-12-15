#include<stdio.h>
#include<iostream>

using namespace std;

long long int s;
int six[7]={1,6,15,20,15,6,1};
int ans[7]={0};

int main()
{
    int n;
    cin>>n;
    n=n-13;
    if(n<0)
        cout<<"0";
    else if(n==0)
        cout<<"1";
    else
    {
        s=1;
        ans[0]=s;
        //cout<<s<<" ";
        s=s+six[1]*1;
        ans[1]=s;

        //cout<<s<<" ";
        s=s+six[1]*1+six[2]*1;
        ans[2]=s;


        //cout<<s<<" ";
        s=s+six[1]*1+six[2]*2+six[3]*1;
        ans[3]=s;


        //cout<<s<<" ";
        s=s+six[1]*1+six[2]*3+six[3]*3+six[4]*1;
        ans[4]=s;


        //cout<<s<<" ";
        s=s+six[1]*1+six[2]*4+six[3]*6+six[4]*4+six[5]*1;
        ans[5]=s;


        //cout<<s<<" ";
        s=s+six[1]*1+six[2]*5+six[3]*10+six[4]*10+six[5]*5+six[6]*1;
        ans[6]=s;

        //cout<<s<<" ";
        if(n%2!=0)
            n--;
        n=n/2;
        if(n<=6)
            cout<<ans[n];
        else
        {
            int ans2[7]={0,1,5,10,10,5,1};
            int ans3[7]={0};
            int i=7,j,cnt=0;
            while(i<=n)
            {
                for(j=1;j<=6;j++)
                {
                    if(cnt==0)
                    {
                        ans3[j]=ans2[j]+ans2[j-1];
                        s=s+(six[j]*ans3[j])%1000000007;
                    }
                    else
                    {
                        ans2[j]=ans3[j]+ans3[j-1];
                        s=s+(six[j]*ans2[j])%1000000007;
                    }
                }
                cnt=1-cnt;
                i++;
            }
            cout<<s%1000000007;
        }
    }
    return 0;
}
