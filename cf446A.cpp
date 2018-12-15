#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    long long int sm=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sm=sm+(long long int)arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    sort(brr,brr+n);
    if(n>=2){
        long long int sm2=(long long int)brr[n-1] + (long long int)brr[n-2];
        if(sm2>=sm)
            cout<<"YES";
        else
            cout<<"NO";
    }else{
        cout<<"NO";
    }
    return 0;
}
