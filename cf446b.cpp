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
    int ctr=0,save=n;
    for(int i=n-1;i>=0;i--){
        if(i<save){
            ctr++;
        }
        save=min(save,i-arr[i]);
    }
    cout<<ctr;
    return 0;
}
