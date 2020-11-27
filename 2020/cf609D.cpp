#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;

    cin>>n;
    long long int stk[n];
    for(long long int i=0;i<n;i++){
        cin>>stk[i];
    }

    long long int ans=0;
    long long int x=0,y=0,last=0;
    long long int cnt=1;
    for(long long int i=n-1;i>=0;i--){

        ans=ans+((i+1)*(stk[i]-x))/2;
        if(((i+1)*(stk[i]-x))%2!=0){
            y++;
        }else{
            ans=ans+y/2;
            y=0;
        }
        x=stk[i];
    }
    cout<<ans+y/2;
    return 0;
}
