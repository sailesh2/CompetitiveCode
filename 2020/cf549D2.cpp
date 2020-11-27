#include<bits/stdc++.h>

using namespace std;
long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

long long int lcm(long long int a, long long int b){
    return a/gcd(a,b);
}
int main(){
    long long int n,k;
    cin>>n>>k;
    long long int a,b;
    cin>>a>>b;
    long long int tot=n*k;
    long long int f=(1+a)%tot;
    if(f==0)
        f=tot;
    vector<long long int> l;
    long long int mini=1000000000,maxi=0,v,val;
    for(long long int i=1;i<=tot;i=i+k){
        v=(i+b)%tot;
        if(v==0)
            v=tot;
        l.push_back(v);
        v=(i-b+tot)%tot;
        if(v==0)
            v=tot;
        l.push_back(v);

    }

    for(long long int i=0;i<l.size();i++){

        v=(f-l[i]+tot)%tot;
        if(v==0)
            v=tot;
        val=lcm(tot,v);
        if(i==0){
                mini=val;
                maxi=val;
        }else{
        mini=min(mini,val);
        maxi=max(maxi,val);
        }
        v=(l[i]-f+tot)%tot;
        if(v==0)
            v=tot;
        val=lcm(tot,v);
        mini=min(mini,val);
        maxi=max(maxi,val);
    }

    f=(1-a+tot)%tot;
    if(f==0)
        f=tot;

    for(long long int i=0;i<l.size();i++){

        v=(f-l[i]+tot)%tot;
        if(v==0)
            v=tot;
        val=lcm(tot,v);
        mini=min(mini,val);
        maxi=max(maxi,val);

        v=(l[i]-f+tot)%tot;
        if(v==0)
            v=tot;
        val=lcm(tot,v);
        mini=min(mini,val);
        maxi=max(maxi,val);
    }
    if(tot==1){
        mini=0;
        maxi=0;
    }
    cout<<mini<<" "<<maxi;
    return 0;
}
