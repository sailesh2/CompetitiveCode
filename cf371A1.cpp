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
    long long int l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    long long int ans=0;
    if(l2>r1 || r2<l1){
        ans=0;
    } else{
        long long int arr[4];
        arr[0]=l1;
        arr[1]=r1;
        arr[2]=l2;
        arr[3]=r2;
        sort(arr,arr+4);
        ans=arr[2]-arr[1]+1;
        if(k<=arr[2] && k>=arr[1])
            ans--;
    }
    cout<<ans;
    return 0;
}
