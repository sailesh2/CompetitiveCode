#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int ans=0;
        for(int j=n;j>=1;j--){
            int ctr=0;
            for(int k=0;k<n;k++){
                if(arr[k]>=j){
                    ctr++;
                }
            }
            if(ctr>=j){
                ans=j;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
