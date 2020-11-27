#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int rains[n];
    for(int i=0;i<n;i++){
        cin>>rains[i];
    }

    int d=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i-x;j<i && j>=0;j++){
            if(rains[j]<=rains[i]){
                cnt=1;
                break;
            }
        }
        for(int j=i+1;j<=i+y && j<n;j++){
            if(rains[j]<=rains[i]){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            d=i+1;
            break;
        }
    }
    cout<<d;
    return 0;
}
