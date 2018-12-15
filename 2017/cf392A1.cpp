#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    long long int sm=0;
    for(int i=0;i<n;i++){
        sm=sm+(maxi-arr[i]);
    }
    cout<<sm;
    return 0;
}
