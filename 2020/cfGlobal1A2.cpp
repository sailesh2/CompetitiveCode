#include<bits/stdc++.h>

using namespace std;

int main(){
    int b,k;
    cin>>b>>k;
    int arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    int pb=1;
    int sm=0;
    for(int i=k-1;i>=0;i--){
        sm=(sm+arr[i]*pb)%10;
        pb=(pb*b)%10;
    }
    if(sm%2==0)
        cout<<"even";
    else
        cout<<"odd";
    return 0;
}
