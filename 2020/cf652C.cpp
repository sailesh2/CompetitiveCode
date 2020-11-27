#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,n,k;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n>>k;
        long long int c[n];
        for(long long int j=0;j<n;j++){
            cin>>c[j];
        }
        long long int w[k];
        for(long long int j=0;j<k;j++){
            cin>>w[j];
        }

        sort(c,c+n);
        sort(w,w+k);

        long long int taken=n-1;
        long long int s=0;
        for(long long int j=0;j<k;j++){
            s=s+c[taken];
            if(w[j]==1)
                s=s+c[taken];
            taken--;
        }
        for(long long int j=0;j<k;j++){
            if(w[j]!=1){
                s=s+c[taken-(w[j]-2)];
                taken=taken-(w[j]-1);
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
