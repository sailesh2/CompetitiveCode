#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>

using namespace std;

bool fun(int a,int b){
    return a>b;
}

int main(){
    long long int b,q,l,m,zero=0,bpre=0,bpren=0;
    cin>>b>>q>>l>>m;
    long long int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
        if(arr[i] == 0){
            zero = 1;
        }
        if(arr[i] == b){
            bpre = 1;
        }
        if(arr[i]==-1*b){
            bpren=1;
        }
    }
    if(b==0) {
        if(zero == 1)
            cout<<"0";
        else
            cout<<"inf";
    } else if(q == 0){
        if(abs(b)<=l) {
            if(zero == 1) {
                if(bpre == 1)
                    cout<<"0";
                else
                    cout<<"1";
            }
            else
                cout<<"inf";
        } else {
            cout<<"0";
        }
    } else if( (q==1 || q==-1) && abs(b)<=l) {
        if(q==1 && bpre == 1)
            cout<<"0";
        else if(q==-1 && bpre==1 && bpren==1)
            cout<<"0";
        else
            cout<<"inf";
    } else if(abs(b)>l){
        cout<<"0";
    } else {
        long long int ctr=0,b1=b;
        int cnt=0;
        set<long long int> has;
        while(abs(b1)<=l){
            has.insert(b1);
            b1 = b1*q;
            ctr++;
        }
        if(cnt==0) {
            for(int i=0;i<m;i++){
                if(has.count(arr[i])!=0){
                    ctr--;
                }
            }
            cout<<ctr;
        }
    }
    return 0;
}
