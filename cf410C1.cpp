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

    int ctr=0,t1,t2;
    if(l[n-1]>1){
        cout<<"YES\n0";
    } else{
        int val,gcd1 = arr[0],gcd2=0;
        for(int i=1;i<n;i++){
                int cnt =0;
            val = gcd(gcd1,arr[i]);
            if(val==1){
                t1=arr[i]+arr[i-1];
                t2=abs(arr[i]-arr[i-1]);
                if(gcd(gcd(gcd2,t1),t2) >1){
                    arr[i]=t1;
                    arr[i-1]=t2;
                    gcd2=gcd(gcd2,t1);
                    gcd1=gcd(gcd2,t2);
                    ctr++;
                    cnt = 1;
                }

                if(cnt ==0 && i+1<n){
                    t1=arr[i]+arr[i+1];
                    t2=abs(arr[i]-arr[i+1]);
                    if(gcd(gcd(gcd2,t1),t2) >1){
                        arr[i]=t1;
                        arr[i+1]=t2;
                        gcd2 =gcd(gcd2,t1);
                        gcd1=gcd(gcd2,t2);
                        ctr++;
                    }
                }
            }
        }
        l[0]=arr[0];
        for(int i=1;i<n;i++){
            l[i] = gcd(arr[i],l[i-1]);
        }
        if(l[n-1]>1){
            cout<<"YES\n"<<ctr;
        } else{
            cout<<"NO";
        }
    }
    return 0;
}
