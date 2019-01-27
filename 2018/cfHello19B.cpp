#include<bits/stdc++.h>

using namespace std;

int n;
bool isPossibleRotation(int* arr, int ind, int sm){
    if(ind>=n){
        return sm==0;
    }
    bool isPos = isPossibleRotation(arr, ind+1, (sm+arr[ind])%360);
    if(isPos){
        return isPos;
    }
    else{
        return isPossibleRotation(arr, ind+1, (sm-arr[ind]+360)%360);
    }
}
int main(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isPossibleRotation(arr,0,0)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

    return 0;
}
