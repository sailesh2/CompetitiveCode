#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m;
    map<long long int,long long int> factorCount;
    map<long long int,long long int>::iterator factorCountIt;

    vector<long long int> factors;
    cin>>n>>m;
    long long int ctr=0;
    while(m%2==0){
        m=m/2;
        ctr++;
    }
    if(ctr>0){
        factorCount.insert(make_pair(2,ctr));
        factors.push_back(2);
    }

    for(long long int i = 3;i*i<=m;i+=2){
        ctr=0;
        while(m%i==0){
            m=m/i;
            ctr++;
        }
        if(ctr>0){
            factorCount.insert(make_pair(i,ctr));
            factors.push_back(i);
        }
    }

    if(m>1){
        factorCount.insert(make_pair(m,1));
        factors.push_back(m);
    }

    long long int f,fc,mini=0;
    for(long long int i=0;i<factors.size();i++){
        f=factors[i];
        factorCountIt=factorCount.find(f);
        fc=factorCountIt->second;
        ctr=0;
        long long int tf=f;
        while(n/tf>0){
            ctr+=n/tf;
            tf=tf*f;
        }
        if(i==0)
            mini=ctr/fc;
        else
            mini=min(mini,ctr/fc);
    }
    cout<<mini;
    return 0;
}
