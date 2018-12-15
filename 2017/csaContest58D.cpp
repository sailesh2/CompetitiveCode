#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n,x,p;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>p;
        n=pow(2,p);

        pair<int,int> arr[n];
        int ans[n];
        for(int j=0;j<n;j++){
            cin>>x;
            arr[j]=make_pair(x,j);
        }
        sort(arr,arr+n);
        for(int j=0;j<n;j++){
            ans[arr[j].second-1]=(int)floor(log2(j+1));
        }
        for(int j=0;j<n;j++){
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
