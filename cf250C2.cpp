#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int ones[n];
    int ctrO=0;
    long long int mod=1000000007;
    for(int i=0;i<n;i++){
        ctrO=ctrO+(int)s[i]-48;
        ones[i]=ctrO;
    }

    long long int pow2[n+1];
    long long int p2=1;
    for(int i=0;i<=n;i++){
        pow2[i]=p2;
        p2=(p2*2)%mod;
    }

    int l,r,total,totalO,totalZ;
    long long ans;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        total=r-l+1;
        l--;
        r--;
        if(l-1>=0)
            totalO=ones[r]-ones[l-1];
        else
            totalO=ones[r];
        totalZ = total - totalO;
        ans = (pow2[totalZ] * (pow2[totalO] - 1 + mod)%mod)%mod;
        cout<<ans<<"\n";
    }
    return 0;
}
