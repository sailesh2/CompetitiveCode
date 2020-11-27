#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x;
        int arr[n];
        int maxi=-1;
        int s=0;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            s=(s+arr[j])%x;
            if(s!=0)
                maxi=max(maxi,j+1);
        }
        s=0;
        for(int j=n-1;j>=0;j--){

            s=(s+arr[j])%x;
            if(s!=0)
                maxi=max(maxi,n-1-j+1);
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
