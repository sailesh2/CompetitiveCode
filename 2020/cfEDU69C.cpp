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
    int n,k;
    n=lscan();
    k=lscan();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    int sm=0;
    for(int i=n-1;i>=0;i--){
        if(k==1){
            sm=arr[i]-arr[0];
            break;
        }

        if(i==n-1 || arr[i]!=arr[i+1])
        k--;
    }

    cout<<sm;
    return 0;
}
