#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,k,sm=0;
    cin>>n>>k>>m;

    long long int arr[n];
    long long int cuml=0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        sm=sm+arr[i];
    }
    sort(arr,arr+n);
    long long int i=0;

    long long int ctr=n;
    double maxi=(double)sm/ctr;
    while(i<n){
        maxi=max(maxi,(double)(sm-cuml+min(m-min(m,i),(n-min(m,i))*k))/(ctr-min(m,i)));
        cuml=cuml+arr[i];
        i++;
    }
    cout<<fixed<<setprecision(20)<<maxi;
    return 0;
}
