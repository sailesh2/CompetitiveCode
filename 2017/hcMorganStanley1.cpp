#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n],brr[n];
    int maxi=m*k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    for(int i=0;i<n;i++){
        maxi=max(maxi,m*arr[i]*brr[i]);
    }
    cout<<maxi;
    return 0;
}
