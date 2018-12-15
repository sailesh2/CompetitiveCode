#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char c;
    int curr;
    cin>>n;
    int x=1023,orig=1023;
    for(int i=0;i<n;i++){
        cin>>c>>curr;
        if(c=='|'){
            x=x | curr;
        } else if(c=='&'){
            x=x & curr;
        } else{
            x=x ^ curr;
        }
    }
    //cout<<x;
    int digs[11]={0};
    int k=0;
    while(x>0){
        digs[k]=x%2;
        x=x/2;
        k++;
    }

    int origDigs[11]={0};
    int k1=0;
    while(orig>0){
        origDigs[k1]=orig%2;
        orig=orig/2;
        k1++;
    }
    int ansDigs[11]={0};
    int k2=0;
    while(k2<11){
        if(digs[k2]==1){
            ansDigs[k2]=1-origDigs[k2];
        }else{
            ansDigs[k2]=origDigs[k2];
        }
        k2=k2+1;
    }

    int ans=0;
    int p=1;
    int k3=0;
    while(k3<11){
        ans=ans+ansDigs[k3]*p;
        p=p*2;
        k3=k3+1;
    }
    cout<<"1\n";
    cout<<"^ "<<ans;
    return 0;
}
