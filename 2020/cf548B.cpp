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
    long long int n;
    n=lscan();
    long long int arr[n];
    long long int choc=0;
    for(long long int i=0;i<n;i++){
        arr[i]=lscan();
    }
    long long int maxi=arr[n-1];
    choc=maxi;
    for(long long int i=n-2;i>=0;i--){
        maxi=max(0LL,min(arr[i],maxi-1));
        choc=choc+maxi;
    }
    cout<<choc;
    return 0;
}
