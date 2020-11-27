#include<bits/stdc++.h>

using namespace std;

#define gc getchar


long long int fastPow(long long int a, long long int b, long long int mod){
    long long int bin=a%mod,p=1;
    while(b>0){
        if(b%2==1){
            p=(p*bin)%mod;
        }
        bin=(bin*bin)%mod;
        b=b/2;
    }
    return p;
}
inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
int main(){
    long long int n,k,x;
    n=lscan();
    long long int mod=998244353;

    vector<vector<long long int> > items;
    long long int has[1000005]={0};
    for(long long int i=0;i<n;i++){
        k=lscan();
        vector<long long int> a;
        for(long long int j=0;j<k;j++){
            x=lscan();
            a.push_back(x);
            has[x]++;
        }
        items.push_back(a);
    }
    long long int smDen=0,smNum=0;
    for(long long int i=0;i<n;i++){
        k=items[i].size();
        long long int num=0;
        for(long long int j=0;j<k;j++){
            num=(num+n-has[items[i][j]])%mod;
        }

        if(i==0){
            smDen=k;
            smNum=num;
        }
        else{
            smNum=((smNum*k)%mod + (smDen*num)%mod)%mod;
            smDen=(smDen*k);
        }
    }

    smDen=(smDen*(n*n));
    smNum=(smDen-smNum+mod)%mod;
    long long int ans = (smNum%mod * fastPow(smDen,(mod-2),mod) )%mod;
    cout<<ans;
    return 0;
}
