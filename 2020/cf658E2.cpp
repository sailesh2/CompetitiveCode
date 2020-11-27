#include<bits/stdc++.h>

using namespace std;
int n;

bool subsetSum(vector<int> sub){
    int l = sub.size();
    int target = n;

    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=0;

    dp[0]=1;

    for(int i=0;i<l;i++){
        for(int j=n;j>=0;j--){
            if(dp[j]==1){

                if(j+sub[i]==n)
                    return true;
                if(j+sub[i]<n)
                    dp[j+sub[i]]=1;

            }
        }
    }

    return false;
}

bool possible(int* arr){
    vector<int> sub;

    int f=arr[0];
    int ctr=1;
    for(int i=1;i<2*n;i++){
        if(arr[i]<f){
            ctr++;
        }else{
            sub.push_back(ctr);
            f=arr[i];
            ctr=1;
        }
    }

    return subsetSum(sub);
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[2*n];
        for(int j=0;j<2*n;j++){
            cin>>arr[j];
        }

        if(possible(arr)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
