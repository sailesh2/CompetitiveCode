#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    int has[100005]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(arr,arr+n);
    int curr=n-1;

    for(int i=0;i<n;i++){
        has[brr[i]]=1;
        while(curr>=0 && has[arr[curr]]==1){
            cout<<arr[curr]<<" ";
            curr--;
        }
        if(curr>=0)
            cout<<"\n";
    }

    return 0;
}
