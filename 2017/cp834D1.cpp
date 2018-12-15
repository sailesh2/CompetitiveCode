#include<stdio.h>
#include<iostream>

using namespace std;

int n,k;
int fun(int *,int,int);
int dp[32001][51];

int main(){
    cin>>n>>k;
    int arr[n];
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<fun(arr,0,k);
    return 0;
}

int fun(int *arr,int i,int l){
    int has[32001] = {0};
    int disCount = 0;
    if(l == 1) {
        for(int j = i; j<n;j++){
            if(has[arr[j]] == 0) {
                has[arr[j]] = 1;
                disCount++;
            }
        }
        return disCount;
    }

    if(i == n)
        return -1;

    int maxi = 0,val;
    for(int j = i; j<n ;j++){

        if(has[arr[j]] == 0) {
            has[arr[j]] = 1;
            disCount++;
        }

        val = dp[j+1][l-1];
        if(val == 0){
            val = fun(arr,j+1,l-1);
        }
        maxi = max(maxi,val+disCount);
    }
    dp[i][l] = maxi;
    return maxi;
}
