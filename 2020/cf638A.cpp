#include<bits/stdc++.h>

using namespace std;

long long int power[31];
map<pair<string,int>,int> dp;
map<pair<string,int>,int>::iterator dpIt;
long long int MAX=1000000000000000;
void setup(){
    power[0]=1;
    for(long long int i=1;i<=30;i++){
        power[i]=power[i-1]*2;
    }


}
long long int mini;
long long int minimize(long long int index, long long int n, long long int ctr, long long int sum, string s){

    if(ctr==n/2){
            //cout<<sum;
        return abs(2*(power[n]-1-sum));
    }
    if(index==n+1){
        return MAX;
    }

    if(ctr>n/2)
        return MAX;


    s[index]=='1';
    dpIt=dp.find(make_pair(s,n/2));

    long long int a = dpIt==dp.end()?minimize(index+1,n,ctr+1,sum+power[index],s):dpIt->second;
    s[index]='0';

    dpIt=dp.find(make_pair(s,n/2));

    long long int b=dpIt==dp.end()?minimize(index+1,n,ctr,sum,s):dpIt->second;

    dp.insert(make_pair(make_pair(s,n/2),min(a,b)));
    return min(a,b);
}

int main(){
    long long int t;
    cin>>t;
    setup();
    long long int n;
    for(long long int i=0;i<t;i++){
        cin>>n;
        string s="";
        for(int j=0;j<=30;j++)
            s.push_back('0');
        cout<<minimize(1,n,0,0,s)<<"\n";
    }
    return 0;
}
