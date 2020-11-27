#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x;
        int a;
        int maxi=-1;
        int s=0;
        int has[10005];
        for(int j=0;j<x;j++){
            has[j]=-2;
        }
        has[0]=-1;
        int cnt=0;
        for(int j=0;j<n;j++){
            cin>>a;
            s=(s+a)%x;
            if(s!=0)
                cnt=1;
            if(has[s]==-2){
                has[s]=j;
                maxi=max(maxi,j+1);
            }else{
                maxi=max(maxi,j-has[s]-1);
            }
        }
        if(cnt==0)
            maxi=-1;
        cout<<maxi<<"\n";
    }
    return 0;
}
