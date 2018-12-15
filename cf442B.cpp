#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int l=s.length();
    int a[l],b[l];
    for(int i=0;i<l;i++){
        if(s[i]=='a'){
            if(i==0){
                a[i]=1;
            }else{
                a[i]=a[i-1]+1;
            }
        }else{
            if(i==0){
                a[i]=0;
            }else{
                a[i]=a[i-1];
            }
        }
    }

    for(int i=0;i<l;i++){
        if(s[i]=='b'){
            if(i==0){
                b[i]=1;
            }else{
                b[i]=b[i-1]+1;
            }
        }else{
            if(i==0){
                b[i]=0;
            }else{
                b[i]=b[i-1];
            }
        }
    }

    int sma1,sma2,smb1,smb2,sm1,sm2,sm3,sm=0,maxi=0;

    for(int i=-1;i<=l;i++){
        for(int j=i;j<=l;j++){
            if(i==-1){
                sma1=0;
            }else if(i==l){
                sma1=a[l-1];
            }else{
                sma1=a[i];
            }

            if(j==-1){
                sma2=0;
            }else if(j==l){
                sma2=a[l-1];
            }else{
                sma2=a[j];
            }

            if(j==-1){
                smb1=0;
            }else if(j==l){
                smb1=b[l-1];
            }else{
                smb1=b[j];
            }

            if(i==-1){
                smb2=0;
            }else if(i==l){
                smb2=b[l-1];
            }else {
                smb2=b[i];
            }

            sm1=sma1;
            sm2=smb1-smb2;
            sm3=a[l-1]-sma2;

            sm=sm1+sm2+sm3;
            maxi=max(maxi,sm);
        }
    }
    cout<<maxi;
    return 0;
}
