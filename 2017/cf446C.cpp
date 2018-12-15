#include<bits/stdc++.h>

using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}



int main(){
    int g,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        g=gcd(arr[i],arr[i+1]);
        if(g==1){
            cnt=1;
            break;
        }
    }

    if(cnt==0){
        cout<<"-1";
    }else{

        int ctr=0;
        while(1){
            cnt=0;

            for(int i=0;i<n-1;i++){
                if(arr[i]!=1 || arr[i+1]!=1){
                    g=gcd(arr[i],arr[i+1]);
                    if(g==1){
                        if(arr[i]!=1){
                            arr[i]=1;
                        }else{
                            arr[i+1]=1;
                        }
                        cnt=1;
                        ctr++;
                        break;
                    }
                }
            }


            if(cnt==0)
                break;
        }

        cout<<ctr;
    }
    return 0;
}
