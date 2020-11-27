#include<bits/stdc++.h>

#define gc getchar
using namespace std;
long long int dp[300005][3];

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

long long int costGreatFence(long long int start, pair<long long int,long long int>* arr,long long int n, long long int prev,int cnt){

    if(start>=n)
        return 0LL;

    long long int val=-1;
    pair<long long int,long long int> f=arr[start];

    if(f.first!=prev){
        long long int v=dp[start+1][0]==-1?costGreatFence(start+1,arr,n,f.first,0):dp[start+1][0];
        if(val==-1)
        val=v;
        else
        val=min(val,v);
    }
    if(f.first+1!=prev){
        long long v=f.second+ (dp[start+1][1]==-1?costGreatFence(start+1,arr,n,f.first+1,1):dp[start+1][1]);
        if(val==-1)
        val=v;
        else
        val=min(val,v);
    }
    if(f.first+2!=prev){
        long long v=2*f.second + (dp[start+1][2]==-1?costGreatFence(start+1,arr,n,f.first+2,2):dp[start+1][2]);
        if(val==-1)
        val=v;
        else
        val=min(val,v);
    }

    dp[start][cnt]=val;
    return val;
}

int main(){
    long long int q;
    q=lscan();
    long long int n;
    long long int a,b;
    for(long long int i=0;i<q;i++){
        n=lscan();
        pair<long long int,long long int> arr[n];
        for(long long int j=0;j<n;j++){
            dp[j][0]=-1;
            dp[j][1]=-1;
            dp[j][2]=-1;
            a=lscan();
            b=lscan();
            arr[j]=make_pair(a,b);
        }
        dp[n][0]=-1;
        dp[n][1]=-1;
        dp[n][2]=-1;
        long long int v=costGreatFence(0,arr,n,-1,0);
        v=min(v,costGreatFence(0,arr,n,-1,1));
        v=min(v,costGreatFence(0,arr,n,-1,2));
        cout<<v<<"\n";
    }
    return 0;
}
