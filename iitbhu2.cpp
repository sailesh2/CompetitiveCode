#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,n,cnt,j,val,dif;
    string s1,s2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s1>>s2;
        dif=((int)s1[0]-(int)s2[0])%26;
        if(dif<0)
            dif=dif+26;
        cnt=0;
        for(j=1;j<s1.length();j++)
        {
      //      cout<<((int)s1[j]-(int)s2[j])<<" ";
            val=((int)s1[j]-(int)s2[j])%26;
            if(val<0)
                val=val+26;
            if(val!=dif)
            {

                cnt=1;
                break;
            }
        }
        if(cnt==0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
