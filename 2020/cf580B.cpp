#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int sm=0,z=0,cnt=0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        sm=sm+abs(abs(arr[i])-1);
        if(arr[i]<0)
            cnt++;
        if(arr[i]==0){
            z++;
        }
    }
    sm=sm+(max(0LL,(cnt%2)-z))*2;
    cout<<sm;
    return 0;
}
