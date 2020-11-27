#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int grannies[n];
        for(int j=0;j<n;j++){
            cin>>grannies[j];
        }
        sort(grannies,grannies+n);
        int ctr=1;
        for(int j=n-1;j>=0;j--){
            if(grannies[j]<=j+1){
                ctr=j+2;
                break;
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
