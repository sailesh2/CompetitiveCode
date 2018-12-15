#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,e1,e2;
    cin>>n>>e1>>e2;
    int s,d;
    int up[100005]={0};
    int down[100005]={0};
    for(int i=0;i<n;i++){
        cin>>s>>d;
        if(s<d)
        up[s]++;
        else
        down[s]++;
    }
    long long int s1u=0,s1d=0,s2u=0,s2d=0;
    for(int i=e1;i<=n;i++){
        s1u=s1u+up[i];
    }
    for(int i=e1;i>=1;i--){
        s1d=s1d+down[i];
    }
    for(int i=e2;i<=n;i++){
        s2u=s2u+up[i];
    }
    for(int i=e2;i>=1;i--){
        s2d=s2d+down[i];
    }
    cout<<max(max(s1u,s2u),max(s1u+s2d,max(s1d+s2u,max(s1d,s2d))));
    return 0;
}
