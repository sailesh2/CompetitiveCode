#include<bits/stdc++.h>

using namespace std;
int shortCycle(int ind, int* arr, int ctr, int* has){

    for(int i=0;i<n;i++){

    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int has[100005]={0};
    for(int i=0;i<n;i++){
        if(has[i]==0){
            has[i]=1;
            mini=min(mini,shortCycle(i,arr,1,has));
        }
    }
    cout<<mini;
    return 0;
}
