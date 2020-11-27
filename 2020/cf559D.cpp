#include<bits/stdc++.h>

using namespace std;
string rev(string inp){
    string rev="";
    for(int i=inp.length()-1;i>=0;i--)
        rev.push_back(inp[i]);
    return rev;
}
int main(){
    int n,k;
    cin>>n>>k;
    string s="";
    if(n==k){
        for(int i=0;i<n;i++)
            s.push_back('1');
        cout<<s;
    }else if(k==2){
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                s.push_back('1');
            else
                s.push_back('0');
        }
        cout<<s;
    }else{
        int l=0;
        if(k%2==0){
            s="1001";
            l=4;
        }
        for(;l<k;l++)
        {
            if(l%2==0)
                s.push_back('1');
            else
                s.push_back('0');
        }

        int rem=(n-k)/2;

        if(k%2==0){
            s[k-1]='1';
        }
        for(int i=0;i<rem;i++)
        {
            s.push_back('0');
        }

        s=rev(s);

        for(int i=0;i<rem;i++)
        {
            s.push_back('0');
        }
        s=rev(s);
        cout<<s;
    }
}
