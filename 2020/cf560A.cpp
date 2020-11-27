#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    y++;
    string pre="";
    for(int i=n-x;i<n;i++)
        pre.push_back(s[i]);
    string req="";
    for(int i=0;i<x;i++)
        req.push_back('0');
    req[x-y]='1';

    int ctr=0;
    for(int i=0;i<x;i++)
    {

        if(pre[i]!=req[i])
            ctr++;
    }

    cout<<ctr;
    return 0;
}
