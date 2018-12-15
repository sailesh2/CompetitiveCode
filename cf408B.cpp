#include<bits/stdc++.h>

#define gc getchar
using namespace std;


inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}


int main(){
    int n,m,k;
    n=lscan();
    m=lscan();
    k=lscan();
    int arr[n];
    for(int i=1;i<n;i++){
        arr[i]=0;
    }
    arr[0]=1;
    int h;
    set<int> holes;
    for(int i=0;i<m;i++){
        h=lscan();
        holes.insert(h-1);
    }
    int u,v,temp,ans=0,cnt=0;
    if(holes.count(0)>0)
        arr[0]=0;
    for(int i=0;i<k;i++){
        u=lscan();
        v=lscan();
        u--;
        v--;
        temp=arr[u];
        arr[u]=arr[v];
        arr[v]=temp;
        if(arr[u]==1){
            ans=u;
        }
        if(holes.count(u)>0)
            arr[u]=0;
        if(arr[v]==1){
            ans=v;
        }
        if(holes.count(v)>0)
            arr[v]=0;


    }
    cout<<ans+1;
    return 0;
}
