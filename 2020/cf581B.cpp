#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,l,r;
    cin>>n>>l>>r;

    long long int power2[22];
    long long int p=1;
    for(long long int i=0;i<22;i++){
        power2[i]=p;
        p=p*2;
    }

    long long int miniArr[n];
    long long int maxiArr[n];

    long long int miniS=0,maxiS=0;

    for(long long int i=0;i<l;i++){
        miniArr[i]=power2[i];
    }
    for(long long int i=0;i<r;i++){
        maxiArr[i]=power2[i];
    }
    for(long long int i=l;i<n;i++){
        miniArr[i]=1;
    }
    for(long long int i=r;i<n;i++){
        maxiArr[i]=maxiArr[r-1];
    }
    for(long long int i=0;i<n;i++){
        miniS=miniS+miniArr[i];
    }
    for(long long int i=0;i<n;i++){
        maxiS=maxiS + maxiArr[i];
    }

    cout<<miniS<<" "<<maxiS;

    return 0;
}
