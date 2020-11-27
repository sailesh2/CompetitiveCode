#include<bits/stdc++.h>

using namespace std;

long long int maxChecks(long long int a,long long int b){
    long long int maxi=0;
    long long int i=0;
    long long int has[10]={0};
    while(i<100000){
        long long int lb=b*i;
        long long int hb=b*(i+1);

        long long int k2=lb/a+1;
        long long int la=a*k2;
        long long int k3=hb/a;
        long long int ha=a*k3;
        /*if(has[la%10]==1)
            break;
        has[la%10]=1;*/
        if(ha==hb){
            maxi=max(maxi,k3-k2);
        }else{
            maxi=max(maxi,k3-k2+1);
        }
        //cout<<maxi<<" ";
        i++;
    }
    return maxi;
}

int main(){
    long long int t,a,b,k;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>a>>b>>k;
        long long int mini=min(a,b);
        long long int maxi=max(a,b);

        if(maxChecks(mini,maxi)>=k){
            cout<<"REBEL\n";
        }else{
            cout<<"OBEY\n";
        }
    }
    return 0;
}
