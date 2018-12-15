#include<bits/stdc++.h>

using namespace std;
#define gc getchar

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
    long long int n,ctr,cntA,cntB,cntE,v,after,before,eq;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    map<long long int,long long int> mp;
    map<long long int,long long int>::iterator afIt;
    map<long long int,long long int>::iterator befIt;
    map<long long int,long long int>::iterator eqIt;

    long long int totSum=0,sum=0;

    for(int i=n-1;i>=0;i--){
        after=arr[i]+1;
        before=arr[i]-1;
        eq=arr[i];
        cntA=0;
        cntB=0;
        cntE=0;
        afIt=mp.find(after);
        if(afIt!=mp.end()){
            cntA=afIt->second;
        }

        befIt=mp.find(before);
        if(befIt!=mp.end()){
            cntB=befIt->second;
        }

        eqIt=mp.find(eq);
        if(eqIt!=mp.end()){
            cntE=eqIt->second;
        }

        v=sum-((cntA*after) + (cntB*before) + (cntE*eq));
        ctr=(n-1-i)-(cntA+cntB+cntE);
        totSum=totSum + (v-(ctr*arr[i]));

        sum=sum+arr[i];
        if(eqIt!=mp.end()){
           mp.erase(eqIt);
        }
        mp.insert(make_pair(arr[i],cntE+1));
    }
    cout<<totSum;
}
