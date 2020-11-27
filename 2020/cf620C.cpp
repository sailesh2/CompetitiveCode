#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int q,n,m,t,l,h;
    cin>>q;
    long long int cl,ch;
    for(long long int i=0;i<q;i++){
        cin>>n>>m;
        cl=m;
        ch=m;
        int cnt=0;
        long long int prevT=0;
        for(long long int j=0;j<n;j++){
            cin>>t>>l>>h;

            cl=cl-(t-prevT);
            ch=ch+(t-prevT);

            if(ch<l || cl>h){
                cnt=1;
            }

            cl=max(cl,l);
            ch=min(ch,h);

            prevT=t;
        }
        if(cnt==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
