#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,hor,ver,v;
    cin>>n;
    string s;
    cin>>s;
    int u=0,l=0,d=0,r=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U')
            u++;
        else if(s[i]=='L')
            l++;
        else if(s[i]=='R')
            r++;
        else
            d++;
    }
    hor=min(l,r);
    ver=min(u,d);
    v=hor*2+ver*2;
    cout<<v;
    return 0;
}
