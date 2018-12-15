#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    int n;
    cin>>n;
    int arr[n],l[n],r[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    l[0]=arr[0];
    for(int i=1;i<n;i++){
        l[i] = gcd(arr[i],l[i-1]);
    }

    int ctr=0,cnt=0,t1,t2;
    if(l[n-1]>1){
        cout<<"YES\n0";
    } else{
        for(int i=0;i<n-1;){
            if(arr[i]%2!=0){
                if(i==n-2){
                    cnt=1;
                }
                if(arr[i+1]%2==0)
                    ctr=ctr+2;
                else
                    ctr++;
                i=i+2;
            } else{
                i++;
            }
        }
        if(cnt==0 && arr[n-1]%2!=0){
            ctr=ctr+2;
        }
        cout<<"YES\n"<<ctr;
    }
    return 0;
}
