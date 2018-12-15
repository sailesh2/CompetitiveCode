#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){
    int n,k,n1,n2;
    cin>>n>>n1>>n2;
    k=n1+n2;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    vector<int> v;
    long long int sm=0,sm1=0;

    int j;
    if(n1>n2){
        j=n1;
    } else{
        j=n2;
    }
    for(int i=n-k;i<n;i++){
        sm=sm+arr[i];
        v.push_back(arr[i]);
    }
    for(int i=0;i<k;i++){
        if(i<j){
            sm1=sm1+v.at(i);
        }
    }
    long long int sm2=sm-sm1;
    double maxi=(double)sm1/j+(double)sm2/(k-j);

    printf("%0.8lf",maxi);
    return 0;
}
