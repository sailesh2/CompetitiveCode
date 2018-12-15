#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,l,c,a,b;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                ctr++;
            }
        }
    }
    int v=(n*(n-1))/2;
    v=v%2;
    ctr=ctr%2;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(v==0){
            c=b-a+1;
            l=((c*(c-1))/2)%2;
            if(l==0){
                if(ctr==0)
                cout<<"even\n";
                else
                cout<<"odd\n";
            }else{
                ctr=1-ctr;
                if(ctr==0)
                cout<<"even\n";
                else
                cout<<"odd\n";
            }
        }else{
            c=b-a+1;
            l=((c*(c-1))/2)%2;
            if(l==0){
                if(ctr==0)
                cout<<"even\n";
                else
                cout<<"odd\n";
            }else{
                ctr=1-ctr;
                if(ctr==0)
                cout<<"even\n";
                else
                cout<<"odd\n";
                v=0;
            }
        }
    }
    return 0;
}
