#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int s=0;
        int mini=arr[n-1];
        for(int j=n-2;j>=0;j--){
            if(arr[j]>mini){
                s++;
            }else{
                mini=arr[j];
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
