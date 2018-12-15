#include<bits/stdc++.h>

using namespace std;

int main(){
    set<int> s;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s.insert(arr[i]+arr[j]);
        }

    }
    cout<<s.size();
    return 0;
}
