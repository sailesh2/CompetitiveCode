#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2==0)
        cout<<"NO";
    else{
        int l[n];
        int r[n];
        l[0]=1;
        int i=1,j=0;
        int ctr=2;
        while(i<n || j<n){
            if(j<n)
            r[j++]=ctr++;
            if(j<n)
            r[j++]=ctr++;

            if(i<n)
            l[i++]=ctr++;
            if(i<n)
            l[i++]=ctr++;
        }
        cout<<"YES\n";
        for(int k=0;k<n;k++){
            cout<<l[k]<<" ";
        }
        for(int k=0;k<n;k++){
            cout<<r[k]<<" ";
        }
    }
    return 0;
}
