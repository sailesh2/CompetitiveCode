#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,n,ctr=1,save;
    string s;
    cin>>n>>s;
    save=s[0];
    //cout<<s<<"\n";
    for(i=1;i<n;i++)
    {
        if(s[i]!=save)
        {
            ctr++;
      //      cout<<i<<" "<<s[i]<<"\n";
            save=s[i];
        }
    }
    //cout<<ctr;
    save=s[0];
    int cnt=0,cnt2=0,cnt3=0,cnt4=0;
    for(i=1;i<n;i++)
    {
        if(s[i]==save)
        {
            cnt=1;
            if(cnt2==1)
            {
                cnt4=1;
                break;
            }
        }
        else
        {
            if(cnt==1)
            {
                cnt=0;
                cnt2=1;
            }
            else
            {
                if(cnt2==1)
                {
                    if(i+1<n && s[i+1]==s[i])
                        cnt3=2;
                    else
                        cnt3=max(1,cnt);
                }
                cnt2=0;
            }
            save=s[i];
        }
    }

    int ctr2=1,cnt5=0;
    save=s[0];
    for(i=1;i<n;i++)
    {
        if(s[i]==save)
        {
            ctr2++;
            if(ctr2==2)
                cnt5=max(cnt5,1);
            if(ctr2==3)
                cnt5=max(cnt5,2);
        }
        else
        {
            ctr2=1;
            save=s[i];
        }
    }
    if(cnt4==1 || cnt5==2)
    {
        ctr=ctr+2;
    }
    else
    {
        if(cnt2==1)
            cnt3=max(1,cnt3);
        cnt3=max(cnt3,cnt5);
        ctr=ctr+cnt3;
    }
    cout<<ctr;
    return 0;
}
