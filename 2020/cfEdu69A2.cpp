#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        int l[n];
        for(int j=0;j<n;j++){
            cin>>l[j];
        }
        sort(l,l+n);
        cout<<min(l[n-2]-1,n-2)<<"\n";
    }
    return 0;
}
