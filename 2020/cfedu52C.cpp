#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int arr[n],maxi=0;
    long long int cumlht[200005]={0};
    long long int cumlBlocks[200005]={0};
    long long int mini=100000000;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
        mini=min(mini,arr[i]);
        cumlht[arr[i]]++;
    }

    for(int i=1;i<=maxi;i++){
        cumlht[i]=cumlht[i]+cumlht[i-1];
    }
    long long int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=mini){
            cnt=1;
            break;
        }
    }
    for(int i=maxi;i>=0;i--){
        cumlBlocks[i]=cumlBlocks[i+1]+n-cumlht[i];
    }

    if(cnt==0){
        cout<<"0";
    }else{
        long long int minH=maxi;
        for(int i=mini;i<=maxi;i++){
            if(cumlBlocks[i]<=k){
                minH=i;
                break;
            }
        }
        long long int start=minH;
        long long int stop=mini,ctr=1;
        long long int sm=0;
        if(start!=stop)
            ctr++;
        while(start>stop){
            sm=sm+n-cumlht[start-1];
            if(sm>k){
                ctr++;
                sm=n-cumlht[start-1];
            }
            start--;
        }
        cout<<ctr;
    }
    return 0;
}
