#include<bits/stdc++.h>

using namespace std;

int getT(int v){
    return (int)ceil(log2(v+1));
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        int maxT=0;
        int maxi=arr[0];
        for(int j=1;j<n;j++){
            if(arr[j]<maxi){
                maxT=max(maxT,getT(maxi-arr[j]));
            }
            maxi=max(maxi,arr[j]);
        }
        cout<<maxT<<"\n";
    }
    return 0;
}
