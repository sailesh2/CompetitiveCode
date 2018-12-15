#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int crr[1000]={0};
    int drr[1000]={0};
    int x,a=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(crr[x]==0){
            drr[a++]=x;
        }
        crr[x]++;
    }
    if(a==2){
        if(crr[drr[0]]==crr[drr[1]]){
            cout<<"YES\n";
            cout<<drr[0]<<" "<<drr[1];
        } else{
            cout<<"NO";
        }
    } else{
        cout<<"NO";
    }
    return 0;
}
