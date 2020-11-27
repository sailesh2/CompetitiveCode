#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    maxi=arr[n-1];
    int ctr[200005]={0};
    int ops[200005]={0};

    for(int i=0;i<n;i++){
        int num=arr[i];
        int c=0;
        while(num>0){
            ctr[num]++;
            if(ctr[num]<=k)
            ops[num]=ops[num]+c;
            c++;
            num=num/2;
        }
        ctr[0]++;
        if(ctr[0]<=k)
        ops[0]=ops[0]+c;
    }

    int mini=1000000009;
    for(int i=0;i<=maxi;i++){
     //   cout<<ctr[i]<<" "<<ops[i]<<"\n";
        if(ctr[i]>=k){
            mini=min(mini,ops[i]);
        }
    }
    cout<<mini;
    return 0;
}
