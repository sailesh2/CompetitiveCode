#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int q,n,k;
    string s;
    cin>>q;
    for(long long int i=0;i<q;i++){
        cin>>n>>k;
        cin>>s;
        long long int ctr=0,cnt=0;
        for(long long int j=0;j<n;j++){
            if(s[j]=='1'){
                ctr++;
            }else{
                if(k>=ctr){
                    cout<<"0";
                    k=k-ctr;
                }else{
                    for(long long int l=0;l<ctr-k;l++){
                        cout<<"1";
                    }
                    cout<<"0";
                    for(long long int l=0;l<k;l++){
                        cout<<"1";
                    }
                    for(long long int l=j+1;l<n;l++){
                        cout<<s[l];
                    }
                    ctr=0;
                    break;
                }
            }
        }
        for(long long int j=0;j<ctr;j++){
            cout<<"1";
        }

        cout<<"\n";
    }
    return 0;
}
