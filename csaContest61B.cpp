#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int ctr=0,ctr2=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0 && i%2!=0){
            ctr++;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]==0 && i%2==0){
            ctr2++;
        }
    }
    cout<<min(ctr,ctr2);
    return 0;
}
