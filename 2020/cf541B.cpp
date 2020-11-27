#include<bits/stdc++.h>
#define gc getchar

using namespace std;

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
    int n;
    long long int a,b;
    n=lscan();
    long long int maxi=0,sm=0;
    set<long long int> draws;
    for(int i=0;i<n;i++){
        a=lscan();
        b=lscan();
        if(draws.count(min(a,b))==0 && min(a,b)>=maxi){
            sm=sm+min(a,b)-maxi+1-draws.count(maxi);
            draws.insert(min(a,b));

        }
        if(i==0)
            draws.insert(0);
        maxi=max(a,b);
    }
    cout<<sm;
    return 0;
}
