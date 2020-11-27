#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n,x;
        cin>>n;
        int arr[n];
        set<int> has;
        int maxi=0,ctr=0;
        for(int j=0;j<n;j++){
            cin>>x;
            arr[j]=x;
            if(maxi>x){
                if(has.count(x)==0){
                    has.insert(x);
                    ctr++;
                }
            }

            maxi=max(maxi,x);
        }
        set<int> has2;
        int mini=1000000000;
        int ctr2=0;
        for(int j=n-1;j>=0;j--){
            x=arr[j];
            if(mini<x){
                if(has2.count(x)==0){
                    has2.insert(x);
                    ctr2++;
                }
            }
            mini=min(x,mini);
        }
        cout<<min(ctr,ctr2)<<"\n";
    }
    return 0;
}
