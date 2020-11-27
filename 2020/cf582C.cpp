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
    long long int q,n,m;
    q=lscan();
    vector<long long int> mat[10];

    for(long long int i=0;i<10;i++){
        for(long long int j=1;j<=10;j++){
            long long int mod=(i*j)%10;
            mat[i].push_back(mod);
            if(mod==0)
                break;
        }
    }

    for(long long int i=0;i<q;i++){
        n=lscan();
        m=lscan();
        long long int div=n/m;
        long long int last=m%10;
        long long int sm=0;
        long long int st = (long long int)(mat[last].size());
        long long matDiv=div/st;
        long long int matRem=div%st;
        for(long long int j=0;j<st;j++){
            sm=sm+mat[last][j];
        }

        long long int ans=matDiv*sm;

        for(long long int j=0;j<matRem;j++){
            ans=ans+mat[last][j];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
