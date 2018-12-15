#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,k;
    double s;
    cin>>s>>q>>k;
    int arr[q];
    for(int i=0;i<q;i++){
        cin>>arr[i];
    }
    sort(arr,arr+q);
    for(int i=0;i<q;i++){
        s=max(s+k,(s*(100+arr[i]))/100);
    }
    cout<<s;
    return 0;
}
