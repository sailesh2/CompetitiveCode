#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    int i,n,maxi=0;
    cin>>n;
    string s,save;
    map<string,int> mp;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(mp.find(s)==mp.end())
        {
            mp.insert(make_pair(s,1));
        }
        else
        {
            mp[s]=mp[s]+1;
        }
        if(mp[s]>maxi)
        {
            maxi=mp[s];
            save=s;
        }
    }
    cout<<save;
    return 0;
}
