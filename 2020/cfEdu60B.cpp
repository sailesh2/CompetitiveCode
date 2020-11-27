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
    int n,m;
    long long int k;
    n=lscan();
    m=lscan();
    k=lscan();
    int save;
    long long int arr[n],maxi=0;
    for(int i=0;i<n;i++){
        arr[i]=lscan();
        if(arr[i]>maxi){
            maxi=arr[i];
            save=i;
        }
    }
    long long int sm=0,maxi2=0;
    for(int i=0;i<n;i++){
        if(i!=save){
            if(arr[i]>maxi2){
            maxi2=arr[i];
            }
        }
    }
    long long int ans=(maxi*k+maxi2)*(m/(k+1)) + maxi*(m%(k+1));
    cout<<ans;
}
