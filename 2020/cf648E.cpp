#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    long long int maxi=0;
    if(n==1)
        maxi=arr[0];
    else if(n==2)
        maxi=arr[0]|arr[1];
    else if(n==3)
        maxi=arr[0]|arr[1]|arr[2];
    else{
        for(long long int i=0;i<n;i++){
            for(long long int j=i+1;j<n;j++){
                for(long long int k=j+1;k<n;k++)
                    maxi=max(maxi,arr[i]|arr[j]|arr[k]);
            }
        }
    }
    cout<<maxi;
    return 0;
}
