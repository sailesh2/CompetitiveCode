#include<bits/stdc++.h>

#define gc getchar
using namespace std;
int z;
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

int findRem(int i, int n, int *arr, set<int> has){
    while(i<n && has.count(i)>0){
            i++;
    }

    if(i==n)
        return 0;
    int j=i+1;
    while(j<n && has.count(j)>0){
            j++;
    }

    if(j==n)
        return 0;

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

    return ctr;
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
    set<int> has;

    int i=0,j=1,j2;
    int ctr=0,cnt=0;
    while(1){
        while(j<n){
            if(arr[j]-arr[i]>=z){
                break;
            }
            j++;
        }
        if(j>=n)
            break;
        j2=j;
        while(j2<n){
            if(arr[j]-arr[j2]>=z){
                j2--;
                break;
            }
            j2++;
        }
        if(j2==n)
            j2--;
        has.insert(j2);
        j2++;
        ctr++;
        i++;
        if(j2==n){
            ctr=ctr+findRem(i,n,arr,has);
            break;
        }
        while(i<j2 && has.count(i)>0){
            i++;
        }
        if(has.count(i)>0)
            break;
        if(i==j2){
            j2++;
        }
        j=j2;
    }

    cout<<ctr;
    return 0;
}
