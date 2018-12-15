#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> save;
    int mini=1000000007;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mini=min(mini,arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]==mini){
            save.push_back(i);
        }
    }
    int miniD=100000000;
    for(int i=1;i<save.size();i++){
        miniD=min(miniD,abs(save[i]-save[i-1]));
    }
    cout<<miniD;
    return 0;
}
