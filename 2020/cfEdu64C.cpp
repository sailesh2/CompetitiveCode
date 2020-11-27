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
    int n,z;
    n=lscan();
    z=lscan();
    int arr[n];

    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }

    sort(arr,arr+n);
    set<int> has;

    int i=0,j=1;
    int ctr=0,cnt=0;
    while(1){
        cnt=0;
        while(i<n && j<n){
            if(arr[j]-arr[i]>=z){
                ctr++;
                cnt=1;
                has.insert(j);
                i++;
                j++;
                break;
            }
            j++;
        }
        if(cnt==0)
            break;
        while(i<n && has.count(i)>0){
            i++;
        }
        if(has.count(i)>0)
            break;
        if(i==j){
            j++;
        }
    }

    cout<<ctr;
    return 0;
}
