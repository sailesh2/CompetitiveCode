#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=-1;
    long long int sm;
    for(int i=0;i<n;i++){
        arr[i]=arr[i]*-1;
        sm=0;
        for(int j=0;j<n;j++){
            sm=sm+arr[j];
        }
        if(sm==0){
            cnt=i+1;
            break;
        }
        arr[i]=arr[i]*-1;
    }
    cout<<cnt;
    return 0;
}
