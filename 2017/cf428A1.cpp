#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    long long int sm=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=0;
    for(int i=0;i<n;i++){
        if(sm>=k)
            break;
        if(arr[i]<=8){
            sm = sm +arr[i];
        } else {
            sm=sm+8;
            if(i+1<n)
                arr[i+1]=arr[i+1] + (arr[i]-8);
        }
        ctr++;
    }
    if(sm>=k)
        cout<<ctr;
    else
        cout<<"-1";
    return 0;
}
