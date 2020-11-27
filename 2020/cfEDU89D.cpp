#include<bits/stdc++.h>

using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

pair<int,int> prime(int n){
    int n2=n;
    int v;
    int p=0;
    if(n%2==0){
        v=2;
        p=1;
        while(n%2==0){
            n=n/2;
        }
    }

    for(int i=3;i*i<=n;i=i+2){
        if(n%i==0){
            if(p==1){
                p=2;
                break;
            }else{
                p=1;
                v=i;
                while(n%i==0){
                    n=n/i;
                }
            }
        }
    }

    if(n>2){
        if(p==1){
            p=2;
        }else{
            p=1;
            v=n;
        }
    }



    if(p==2){
        return make_pair(v,n);

    }else{
        return make_pair(-1,-1);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    int ans1[n],ans2[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        pair<int,int> p = prime(arr[i]);
        ans1[i]=p.first;
        ans2[i]=p.second;
    }
    for(int i=0;i<n;i++){
        cout<<ans1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}
