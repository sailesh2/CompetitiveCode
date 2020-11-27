#include<bits/stdc++.h>

using namespace std;
#define gc getchar

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
    long long int n,m,k;
    long long int sm=0;
    cin>>n>>m>>k;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=0,save=0;
    long long int gMax=0;
    for(int i=0;i<n;i++){
        ctr++;
        if(ctr==1)
            save=i;
        sm=sm+(long long int)(arr[i]);
        while((sm - k*(long long int)(ceil(((float)ctr/m))))  < 0){
             ctr--;
             sm=sm-arr[save];
             save++;
             if(ctr==0)
                break;
        }
        gMax=max(gMax,(sm - k*(long long int)(ceil(((float)ctr/m)))));

    }
    while((sm - k*(long long int)(ceil(((float)ctr/m))))  > 0){
         gMax=max(gMax,(sm - k*(long long int)(ceil(((float)ctr/m)))));
         ctr--;
         sm=sm-arr[save];
         save++;
         if(ctr==0)
            break;
    }


    cout<<gMax;
    return 0;
}
