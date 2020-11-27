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

int z;

bool isPossible(int jstart, int n, int * arr){
    int i=0,j=jstart;
    int ctr=0,cnt=0;
    while(1){
        cnt=0;
        while(i<jstart && j<n){
            if(arr[j]-arr[i]>=z){
                ctr++;
                cnt=1;
                i++;
                j++;
                break;
            }
            j++;
        }
        if(cnt==0)
            break;
    }

    return i==jstart && j<=n;
}

int binSearMaxPoints(int * arr, int n){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<n && isPossible(save+ctr+1,n,arr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int main(){
    int n;
    n=lscan();
    z=lscan();
    int arr[n];

    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }

    sort(arr,arr+n);
    cout<<binSearMaxPoints(arr,n);
    return 0;
}
