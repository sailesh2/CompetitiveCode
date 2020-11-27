#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n,s,x;
    for(int i=0;i<t;i++){
        cin>>n>>s;
        int ans=0,maxi=0,sm=0,cnt=0,save=1;
        for(int j=0;j<n;j++){
            cin>>x;
            if(x>=maxi){
                        maxi=x;
                        save=j+1;
                    }
            if(cnt==0){
                sm=sm+x;
                if(sm>s){
                    if(sm-maxi<=s)
                    ans=save;
                    else
                    ans=0;
                    cnt=1;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
