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
        sort(arr,arr+n);

        int ans=0;
        int ctr=0;
        int stop=0;
        for(int i=0;i<n;i++){
            ctr++;
            if(arr[i]>ctr){
                stop=arr[i]-ctr+i;
            }
            if(stop==i){
                ans++;
                ctr=0;
                stop=i+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
