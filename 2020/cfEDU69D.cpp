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
    int n,m,k;
    long long int sm=0;
    n=lscan();
    m=lscan();
    k=lscan();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    int ctr=0;
    long long int gMax=0;
    for(int i=0;i<n;i++){
        if(i%m==0){
            ctr=1;

            sm=(long long int)(arr[i] - k*(int)(ceil(((float)ctr/m))));
            gMax=max(gMax,sm);
            if(sm<0){
                sm=0;
                ctr=0;
            }
        }else{
            ctr++;
            sm=sm+(long long int)(arr[i] - k*(int)(ceil(((float)ctr/m))));
            gMax=max(gMax,sm);
            if(sm<0){
                ctr=1;

                sm=(long long int)(arr[i] - k*(int)(ceil(((float)ctr/m))));
                gMax=max(gMax,sm);
                if(sm<0){
                    sm=0;
                    ctr=0;
                }
            }
        }
    }

    sm=0;
    ctr=0;
    for(int i=n-1;i>=0;i--){
        if(i%m==m-1){
            ctr=1;

            sm=(long long int)(arr[i] - k*(int)(ceil(((float)ctr/m))));
            gMax=max(gMax,sm);
            if(sm<0){
                sm=0;
                ctr=0;
            }
        }else{
            ctr++;
            sm=sm+(long long int)(arr[i] - k*(int)(ceil(((float)ctr/m))));
            gMax=max(gMax,sm);
            if(sm<0){
                ctr=1;

                sm=(long long int)(arr[i] - k*(int)(ceil(((float)ctr/m))));
                gMax=max(gMax,sm);
                if(sm<0){
                    sm=0;
                    ctr=0;
                }
            }
        }
    }

    sm=0;
    for(int i=0;i<n;i++){
        if(i%m==0){
            sm=arr[i]-k;
        }else{
            sm=sm+(long long int)(arr[i]-k);
        }
        gMax=max(gMax,sm);
    }
    cout<<gMax;
    return 0;
}
