#include<bits/stdc++.h>

using namespace std;
#define gc getchar

long long int cumlSum[300005]={0};
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
    long long int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }

    for(int i=0;i<n;i++){
        if(i==0)
        cumlSum[i]=arr[i];
        else
        cumlSum[i]=cumlSum[i-1]+arr[i];;
    }

    for(int i=0;i<n;i++){

    }
    return 0;
}
