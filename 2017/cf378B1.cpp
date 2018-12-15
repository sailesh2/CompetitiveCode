#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>


using namespace std;

int main(){
    int n;
    cin>>n;
    int l[n],r[n];
    long long int ls=0,rs=0,vl=0,vr=0;
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        ls=ls+l[i];
        rs=rs+r[i];
    }

    long long int maxi=abs(ls-rs);

    int save=-1;
    for(int i=0;i<n;i++){
        vl=ls-l[i]+r[i];
        vr=rs-r[i]+l[i];
        if(abs(vl-vr)>maxi){
            maxi=abs(vl-vr);
            save=i;
        }
    }
    cout<<save+1;
}
