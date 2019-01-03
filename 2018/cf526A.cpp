#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int minx=0;
    int mini=1000000000;
    for(int x=0;x<n;x++){
        int sm=0;
        for(int i=0;i<n;i++){
            sm=sm+2*abs(x-i)+arr[i]*2*(i)+2*x;
            if(arr[i]>0)
                sm=sm+2*(arr[i]-1)*i;
        }
        if(sm<mini){
            mini=sm;
            minx=x;
        }
    }
    cout<<mini;
    return 0;
}
