#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,a;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int z=0,s=0;
        for(int j=0;j<n;j++){
            cin>>a;
            if(a==0)
                z++;
            s=s+a;
        }
        if(z>0){
            if(s+z==0)
            cout<<z+1<<"\n";
            else
            cout<<z<<"\n";
        }else{
            if(s==0)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}
