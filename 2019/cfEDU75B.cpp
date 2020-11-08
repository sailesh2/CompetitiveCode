#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,n;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        string s;
        int a[n];
        int zeros=0,ones=0;
        for(int j=0;j<n;j++){
            cin>>s;
            for(int k=0;k<s.length();k++){
                if(s[k]=='0')
                    zeros++;
                else
                    ones++;
            }
            a[j]=s.length();
        }
        int c=0;
        for(int j=0;j<n;j++){
            int l = 2*(a[j]/2);
            for(int k=0;k<=l;k=k+2){
                if(k<=zeros && (l-k)<=ones){
                    zeros=zeros-k;
                    ones=ones-(l-k);
                    c++;
                    break;
                }
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}
