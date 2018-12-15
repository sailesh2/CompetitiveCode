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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    sort(arr,arr+n);
    int has[6000]={0};
    int ctr=n,cnt;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i] && has[j]==0){
                has[j]=1;
                cnt=1;
                break;
            }
        }
        if(cnt==1){
            ctr--;
        }
    }
    cout<<ctr;
    return 0;
}
