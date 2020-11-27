#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int a,b,ctr,temp;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        ctr=0;
        if(b>a){

        }else{
            temp=a;
            a=b;
            b=temp;

        }

        ctr=ctr+(b-a)/5;
        a=a+5*((b-a)/5);
        ctr=ctr+(b-a)/2;
        a=a+2*((b-a)/2);
        ctr=ctr+(b-a);

        cout<<ctr<<"\n";
    }
    return 0;
}
