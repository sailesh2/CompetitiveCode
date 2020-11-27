#include<bits/stdc++.h>

using namespace std;

int power[31];

void setup(){
    power[0]=1;
    for(int i=1;i<=30;i++){
        power[i]=power[i-1]*2;
    }

}

int main(){
    int t;
    cin>>t;
    setup();
    int n;
    for(int i=0;i<t;i++){
        cin>>n;
        int j=1;
        int k=n;
        int sma=0,smb=0;
        int cnt=0;
        int ctr=0;
        while(j<k){
            if(k-j==1){
                if(ctr%2==0)
                    break;
            }
            if(cnt==0)
            sma=sma+power[j]+power[k];
            else
            smb=smb+power[j]+power[k];
            cnt=1-cnt;
            ctr++;
            j++;
            k--;
        }

        if(k-j==1){
            if(cnt==0){
                sma=sma+power[j];
                smb=smb+power[k];
            }else{
                smb=smb+power[j];
                sma=sma+power[k];
            }
        }

        cout<<abs(sma-smb)<<"\n";
    }
    return 0;
}
