#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,j,n;
    cin>>n;
    int max1,max2,max3,min1,min2,min3;
    cin>>min1>>max1;
    cin>>min2>>max2;
    cin>>min3>>max3;

    int ans1,ans2,ans3;
    ans2=min2;
    ans3=min3;
    int cnt=0;
    for(i=min1;i<=max1;i++)
    {
        if(i+ans2+ans3==n)
        {
            cnt=1;
            ans1=i;
            break;
        }
    }
    if(cnt==0)
    {
        ans1=max1;
        for(i=min2;i<=max2;i++)
        {
            if(ans1+i+ans3==n)
            {
                cnt=1;
                ans2=i;
                break;
            }
        }
    }
    if(cnt==0)
    {
        ans2=max2;
        for(i=min3;i<=max3;i++)
        {
            if(ans1+ans2+i==n)
            {
                cnt=1;
                ans3=i;
                break;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3;
    return 0;
}
