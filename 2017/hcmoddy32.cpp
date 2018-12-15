#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k,ctr,mod=1000000007;
    cin>>n>>m>>k;
    long long int endP,startP;
    vector<long long int> pascalSum;
    vector<long long int> tempPascal;
    ctr=0;
    for(int i=1;i<=n;i++){
        if(i<=k)
            ctr++;
        pascalSum.push_back(ctr);
    }
    for(int i=1;i<=m-1;i++){
        ctr=0;
        while(1){
            if(ctr==n)
                break;
            if(ctr<pascalSum.size())
                endP=pascalSum[ctr]%mod;
            else
                endP=pascalSum[pascalSum.size()-1]%mod;
            if(ctr-k-1>=0)
                startP=pascalSum[ctr-k-1]%mod;
            else
                startP=0;
            if(ctr-1>=0){
                if(ctr-k>=0)
                    tempPascal.push_back((((tempPascal[ctr-1]+endP)%mod-startP)%mod+mod)%mod);
                else
                    tempPascal.push_back((((tempPascal[ctr-1]+endP)%mod-startP+1)%mod+mod)%mod);
            }
            else{
                if(ctr-k>=0)
                    tempPascal.push_back(((endP-startP)%mod+mod)%mod);
                else
                    tempPascal.push_back(((endP-startP+1)%mod+mod)%mod);
            }
            ctr++;
        }
        pascalSum=tempPascal;
        tempPascal.clear();

        /*for(int i=0;i<pascalSum.size();i++){
            cout<<pascalSum[i]<<" ";
        }
        cout<<"\n";*/
    }
    if(pascalSum.size()==1)
        cout<<pascalSum[pascalSum.size()-1]%mod;
    else{
        if(n-2>=0)
            cout<<(pascalSum[n-1]-pascalSum[n-2]+mod)%mod;
        else if(n-1>=0)
            cout<<(pascalSum[n-1])%mod;
        else
            cout<<(pascalSum[pascalSum.size()-1]-pascalSum[pascalSum.size()-2]+mod)%mod;
    }
    return 0;
}
