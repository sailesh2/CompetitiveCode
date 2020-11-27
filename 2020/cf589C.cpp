#include<bits/stdc++.h>
#include<math.h>

using namespace std;
long long int mod=1000000007;

long long int calPow(long long int a, long long int b){
    vector<int> revDig;
    while(b>0){
        revDig.push_back(b%2);
        b=b/2;
    }

    long long int power=a;
    long long int ans=1;
    for(int i=0;i<revDig.size();i++){

        if(revDig[i]==1)
        ans=(ans*power)%mod;

        power=(power*power)%mod;
    }
    return ans;
}

vector<long long int> getPrimeDivs(long long int x){
    vector<long long int> primeDivs;
    set<long long int> has;

    while(x%2==0){
        if(has.count(2)==0){
            has.insert(2);
            primeDivs.push_back(2);
        }
        x=x/2;
    }

    for(long long int i=3;i*i<=x;i=i+2){
        while(x%i==0){
            if(has.count(i)==0){
                has.insert(i);
                primeDivs.push_back(i);
            }
            x=x/i;
        }
    }

    if(x>2){
        primeDivs.push_back(x);
    }

    return primeDivs;
}

long long int getProdDivs(long long int p, long long int n){
    long long int ans=1;
    for(long long int i=p;i<=n;i=i*p){

        ans=(ans*calPow(p,(n/i)))%mod;
        if(n/i<p)
            break;
    }
    return ans;
}

int main(){
    long long int x,n;
    cin>>x>>n;

    vector<long long int> primeDivs=getPrimeDivs(x);

    long long int ans=1;
    for(int i=0;i<primeDivs.size();i++){

        long long int primeDiv=primeDivs[i];

        ans=(ans*getProdDivs(primeDiv,n))%mod;
    }

    cout<<ans;
    return 0;
}
