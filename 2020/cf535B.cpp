#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int has[300]={0};
    int m=arr[n-1];
    int div[100005]={0};
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            div[i]++;
            if(i!=(m/i))
            div[m/i]++;
        }
    }
    for(int i=0;i<n;i++){
        if(div[arr[i]]>0){
            has[i]=1;
            div[arr[i]]--;
        }
    }
    int b=1;
    for(int i=0;i<n;i++){
        if(has[i]==0){
            b=arr[i];
        }
    }

    cout<<arr[n-1]<<" "<<b;
    return 0;
}
