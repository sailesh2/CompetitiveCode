#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n,a;
        cin>>n;
        long long int s=0;
        for(int j=0;j<n;j++){
            cin>>a;
            s=s+a;
        }
        cout<<(long long int)ceil((double)s/n)<<"\n";
    }
    return 0;
}
