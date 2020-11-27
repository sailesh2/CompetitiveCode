#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t;
    cin>>t;
    long long int n,m;
    for(long long int i=0;i<t;i++){
        cin>>n>>m;
        long long int st,p,ans=0;
        map<long long int,long long int> mp;
        map<long long int,long long int>::iterator mpIt;
        for(long long int j=0;j<n;j++){
            cin>>st;
            mp.insert(make_pair(st,j));
        }
        long long int maxi=-1;
        for(long long int j=0;j<m;j++){
            cin>>p;
            mpIt=mp.find(p);
            long long int pos=mpIt->second;
            if(pos<=maxi){
                ans++;
            }else{
                ans=ans+1+2*(pos-j);
                maxi=pos;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
