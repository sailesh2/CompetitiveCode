#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int mini,maxi;
    int a,sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        sum=sum+a;
        if(i==0){
            mini=a;
            maxi=a;
        }else{
            mini=min(mini,a);
            maxi=max(maxi,a);
        }
    }
    cout<<(sum-(mini+maxi))/(n-2);
    return 0;
}
