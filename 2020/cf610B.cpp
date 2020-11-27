#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,p,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>p>>k;
        int arr[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        sort(arr,arr+n);
        int s=0;
        for(int j=n-1;j>=0;j--){
            if(arr[j]<=p){
                p=p-arr[j];
                s=s+min(j+1,k);
                j=j-k+1;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
