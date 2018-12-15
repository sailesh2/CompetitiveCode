#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int s=0,a;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i]=a;
        s=s+a;
    }
    long long int ts=0;
    int save=0;
    for(int i=0;i<n;i++){
        ts=ts+arr[i];
        if(2*ts>=s){
            save=i;
            break;
        }
    }
    cout<<save+1;
    return 0;
}
