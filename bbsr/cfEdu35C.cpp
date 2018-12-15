#include<bits/stdc++.h>

using namespace std;

int main(){
    int k1,k2,k3;
    int cnt=0;
    int s;
    cin>>k1>>k2>>k3;
    int maxi=max(k1,max(k2,k3));
    if(maxi==k1){
        s=maxi/k2+maxi/k3;
        if(s==k1-1)
            cnt=1;
    }else if(maxi==k2){
        s=maxi/k1+maxi/k3;
        if(s==k2-1)
            cnt=1;

    }else{
        s=maxi/k2+maxi/k1;
        if(s==k3-1)
            cnt=1;

    }
    if(cnt==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
