#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int x,mini,j,n,k;
    cin>>n>>k;

    mini=1000000000;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            j=n/i;

            x=k*i+j;
            if((x/k)*(x%k)==n)
                mini=min(mini,x);

            x=k*j+i;
            if((x/k)*(x%k)==n)
                mini=min(mini,x);

        }
    }
    cout<<mini;
    return 0;
}
