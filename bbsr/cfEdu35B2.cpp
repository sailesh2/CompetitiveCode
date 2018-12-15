#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,p,r,rp,p2,r2,maxi=0,min1,min2,j;
    cin>>n>>a>>b;
    for(int i=1;i<n;i++){
        p=a/i;
        r=a%i;

            min1=p;

        if(r==0)
        j=n-i;
        else
        j=n-i-1;

        if(j>0){
        p2=b/j;
        r2=b%j;
        min2=p2;
        maxi=max(maxi,min(min1,min2));
        }
    }
    cout<<maxi;
    return 0;
}
