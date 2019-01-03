#include<bits/stdc++.h>

using namespace std;

long long int findMin(long long int minExists, long long int maxExists, long long int b){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<=b && (save+ctr<minExists || (b-save-ctr)>maxExists)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+ctr;
}

int main(){
    int n;
    cin>>n;
    long long int b[n/2];
    long long int a[n];
    for(int i=0;i<n/2;i++){
        cin>>b[i];
    }


    long long int minExists=0;
    long long int maxExists=b[0];
    for(int i=0;i<n/2;i++){
        a[i]=findMin(minExists, maxExists, b[i]);
        minExists = a[i];
        a[n-i-1] = b[i] - a[i];
        maxExists = a[n-i-1];
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
