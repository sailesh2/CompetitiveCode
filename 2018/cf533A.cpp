#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int mini=1000000000;
    int sm=0;
    int savet=-1;
    for(int t=1;t<=100;t++){
        sm=0;
        for(int i=0;i<n;i++){
            if(arr[i]>t)
                sm=sm+arr[i]-t-1;
            else if(arr[i]<t)
                sm=sm+t-1-arr[i];
        }
        if(sm<mini){
            mini=sm;
            savet=t;
        }
    }
    cout<<savet<<" "<<mini;
    return 0;
}
