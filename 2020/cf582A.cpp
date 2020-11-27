#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int mini=1000000009;
    int s;
    for(int i=0;i<n;i++){
        s=0;
        for(int j=0;j<n;j++){
            s=s+(abs(arr[i]-arr[j]))%2;
        }
        mini=min(mini,s);
        s=1;
        for(int j=0;j<n;j++){
            s=s+(abs((arr[i]+1)-arr[j]))%2;
        }
        mini=min(mini,s);
    }
    cout<<mini;
    return 0;
}
