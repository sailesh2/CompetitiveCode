#include<bits/stdc++.h>

#define gc getchar

using namespace std;

inline long long int lscan()
{
long long int n=0,c=gc();
long long int neg=1;

if(c==45)
    neg=-1;
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return neg*n;
}


int main(){
    long long int n,k;
    n=lscan();
    k=lscan();
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        arr[i]=lscan();
    }

    if(k<=0){
        long long int mini=0;
        long long int s=0;
        long long int start=-1;
        long long int endi;
        for(long long int i=0;i<n;i++){
            s=s+arr[i];
            if(s>0){
                s=0;
            }
            mini=min(mini,s);
        }

        s=0;
        for(long long int i=0;i<n;i++){
            if(arr[i]<0 && start==-1){
                start=i;
            }
            s=s+arr[i];
            if(s>0){
                s=0;
                start=-1;
            }
            if(s==mini){
                endi=i;
                break;
            }
        }

        if(start!=-1){
            //    cout<<start<<" "<<endi;
            for(long long int i=start;i<=endi;i++){
                arr[i]=arr[i]*k;
            }
        }
    }else{
        long long int maxi2=0;
        long long int s=0;
        long long int start=-1;
        long long int endi;
        for(long long int i=0;i<n;i++){
            s=s+arr[i];
            if(s<0){
                s=0;
            }
            maxi2=max(maxi2,s);
        }

        s=0;
        for(long long int i=0;i<n;i++){
            if(arr[i]>0 && start==-1){
                start=i;
            }
            s=s+arr[i];
            if(s<0){
                s=0;
                start=-1;
            }
            if(s==maxi2){
                endi=i;
                break;
            }
        }

        if(start!=-1){
            //    cout<<start<<" "<<endi;
            for(long long int i=start;i<=endi;i++){
                arr[i]=arr[i]*k;
            }
        }

    }

    long long int ans=0,maxi=0;
    for(long long int i=0;i<n;i++){
        ans=ans+arr[i];
        //cout<<arr[i];
        ans=max(0LL,ans);
        maxi=max(maxi,ans);
    }
    cout<<maxi;
    return 0;
}
