#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int brr[n];
    int ctr=0;
    long long int s=0,s1=0,maxis=-1000000000000;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(ctr>0)
            s1=s+arr[i]-k*(i-brr[ctr-1]-1)*(i-brr[ctr-1]-1);
        else
            s1=s+arr[i];
        if(s1>0){
            s=s1;
            maxis=max(maxis,s);
            brr[ctr++]=i;
        }
    }
    cout<<maxis;
    return 0;
}
