#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+n);

        vector<int> ans;
        int j=0,k=n-1;
        int cnt=0;
        while(j<k){
            if(cnt==0){

                ans.push_back(arr[j]);
                j++;
            }
            else{

                ans.push_back(arr[k]);
                k--;
            }
            cnt=1-cnt;
        }
        if(j==k)
            ans.push_back(arr[j]);
        for(int j=n-1;j>=0;j--)
            cout<<ans[j]<<" ";
        cout<<"\n";
    }
    return 0;
}
