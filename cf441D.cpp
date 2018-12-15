#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=0;
    }
    int endP=n-1;
    int totOne=0;
    vector<int> ans;
    ans.push_back(1);
    for(int i=0;i<n;i++){
        totOne++;
        brr[arr[i]-1]=1;
        while(endP>=0 && brr[endP]==1){
            endP--;
        }
        ans.push_back(totOne-(n-1-endP)+1);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
