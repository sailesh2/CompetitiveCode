#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int maxi=-1;
        int x;
        int ctr=0;
        for(int j=0;j<n;j++){
            cin>>x;
            if(maxi!=-1){
                if(x<maxi)
                    ctr++;
            }
            maxi=max(maxi,x);
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
