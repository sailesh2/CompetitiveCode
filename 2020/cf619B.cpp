#include<bits/stdc++.h>

using namespace std;

long long int getDiff(long long int* arr, long long int n){
    long long int maxi=0;
    for(long long int i=0;i<n;i++){
        if(i>0 && arr[i]!=-1 && arr[i-1]!=-1){
            maxi=max(maxi,abs(arr[i]-arr[i-1]));
        }
    }
    return maxi;
}

long long int getDiff(long long int* arr, long long int n, long long int e){
    long long int brr[n];
    for(long long int i=0;i<n;i++){
        if(arr[i]==-1){
            brr[i]=e;
        }else{
            brr[i]=arr[i];
        }
    }
    long long int maxi=0;
    for(long long int i=0;i<n;i++){
        if(i>0)
        maxi=max(maxi,abs(brr[i]-brr[i-1]));
    }
    return maxi;
}

int main(){
    long long int t;
    cin>>t;
    long long int n;
    for(long long int i=0;i<t;i++){
        cin>>n;
        long long int arr[n];
        for(long long int j=0;j<n;j++){
            cin>>arr[j];
        }
        long long int diff=getDiff(arr,n);
        long long int s=0,ctr=0;
        long long int maxi=0,mini=1000000009;
        set<long long int> st;
        for(long long int j=0;j<n;j++){
            if(arr[j]>=0){
                if((j-1>=0 && arr[j-1]==-1) || (j+1<n && arr[j+1]==-1)){
                    if(st.count(arr[j])==0){
                    st.insert(arr[j]);
                    s=s+arr[j];
                    ctr++;
                    maxi=max(maxi,arr[j]);
                    mini=min(mini,arr[j]);
                    }
                }
            }
        }
        if(ctr==0){
            cout<<diff<<" 1\n";
        }else{
            long long int diff1=getDiff(arr,n,(maxi+mini)/2);
            long long int diff2=getDiff(arr,n,(maxi+mini)/2+1);

            if(diff1<diff2)
            cout<<max(diff,diff1)<<" "<<(maxi+mini)/2<<"\n";
            else
            cout<<max(diff,diff2)<<" "<<1+(maxi+mini)/2<<"\n";

        }
    }
    return 0;
}
