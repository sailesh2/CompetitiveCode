#include<bits/stdc++.h>

using namespace std;
int n,k,z;
int dp[200005];

void storeSum(int* arr){
    int sm=0;
    for(int i=0;i<n;i++){
        sm=sm+arr[i];
        dp[i]=sm;
    }
}

int getSum(int index, int left, int* arr){
    if(left==0)
        return 0;

    int lastIndex = min(index+left-1,n-1);

    if(index==0)
        return dp[lastIndex];
    else
        return dp[lastIndex] - dp[index-1];
}

int maxPath(int* arr){
    int maxi=0;
    int ctr=1;
    int sm=arr[0];
    maxi=sm;
    for(int i=1;i<n;i++){
        sm=sm+arr[i];
        int lefts = k-ctr;
        if(lefts==0){
            maxi=max(maxi,sm);
            break;
        }
        int leftMoves=min(lefts/2,z);
        int v=sm+(arr[i]+arr[i-1])*(leftMoves);
        if(lefts%2!=0 && (lefts/2+1)<=z){
            v=v+(arr[i-1]);
        }

        if((lefts/2 + lefts%2)>z){
            v=v+getSum(i+1,lefts-2*z,arr);
        }
        maxi=max(maxi,v);
        ctr++;
    }
    return maxi;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>z;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        storeSum(arr);
        cout<<maxPath(arr)<<"\n";
    }
    return 0;
}
