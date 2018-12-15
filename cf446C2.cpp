#include<bits/stdc++.h>

#define gc getchar
using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}


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
    int g,n,savei,savej,mini=100000000;
    n=lscan();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
        if(i==0){
            g=arr[i];
        }else{
            g=gcd(g,arr[i]);
        }
    }

    if(g!=1){
        cout<<"-1";
    }else{
        if(n==1){
            cout<<"0";
        }else{
            int ctr2=0;
            for(int i=0;i<n;i++){
                if(arr[i]==1)
                    ctr2++;
            }
            if(ctr2>0){
                cout<<n-ctr2;
            }else{
            for(int i=0;i<n;i++){
                g=arr[i];
                for(int j=i+1;j<n;j++){
                    g=gcd(g,arr[j]);
                    if(g==1){
                        if(abs(j-i)<mini){
                            mini=j-i;
                            savei=i;
                            savej=j;
                        }
                    }
                }
            }
            cout<<mini+n-1;
            }
        }
    }
    return 0;
}
