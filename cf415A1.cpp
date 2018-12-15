#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n,k,m;
    cin>>n>>k;
    int s = 0;
    for(int i = 0 ;i<n;i++) {
        cin>>m;
        s = s+m;
    }
    int ctr = 0;
    for(int i =0 ;i<=1000000;i++){
        if(round((float)s/(n+ctr))==k)
            break;
        s=s+k;
        ctr++;
    }
    cout<<ctr;
    return 0;
}
