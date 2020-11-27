#include<bits/stdc++.h>

using namespace std;
bool areAllDivisors(long long int p,long long int* div,long long int s){
    vector<long long int> d;
    for(long long int i=2;i*i<=p;i++){
        if(p%i==0){
            d.push_back(i);
            if(i!=p/i)
                d.push_back(p/i);
        }
    }
    sort(d.begin(),d.end());
    if(d.size()!=s)
        return false;
    for(long long int i=0;i<d.size();i++){
        if(d[i]!=div[i])
            return false;
    }
    return true;
}
int main(){
    long long int t;
    long long int n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        long long int div[n];
        for(long long int j=0;j<n;j++){
            cin>>div[j];
        }

        sort(div,div+n);
        long long int save;
        long long int cnt=0;
        for(long long int j=0,l=n-1;j<=l;j++,l--){
            if(j==0)
                save=div[j]*div[l];
            if(div[j]*div[l]!=save){
                cnt=1;
                break;
            }
        }

        if(cnt==0 && areAllDivisors(save,div,n))
            cout<<save<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
