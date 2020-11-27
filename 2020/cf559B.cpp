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
    int n;
    n=lscan();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    int k=1000000009;

    for(int i=0;i<n;i++){
        if(i!=0)
        k=min(k,(int)floor((double)min(arr[i],arr[0])/i));
        if(i!=n-1)
        k=min(k,(int)floor((double)min(arr[i],arr[n-1])/(n-1-i)));

    }

    cout<<k;
    return 0;
}
