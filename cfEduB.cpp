#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,pos,l,r,ctr=0;
    cin>>n>>pos>>l>>r;
    if(l>1){
        ctr++;
    }
    if(r<n){
        ctr++;
    }
    if(pos<l){
        if(r<n)
            cout<<ctr+r-pos;
        else if(l>1)
            cout<<ctr+l-pos;
        else
            cout<<ctr;
    }else if(pos>r){
        if(l>1)
            cout<<ctr+pos-l;
        else if(r<n)
            cout<<ctr+pos-r;
        else
            cout<<ctr;
    }else{
        if(l>1 && r<n)
            cout<<ctr+min(pos-l,r-pos)+(r-l);
        else if(l>1)
            cout<<ctr+pos-l;
        else if(r<n)
            cout<<ctr+r-pos;
        else
            cout<<ctr;
    }
    return 0;
}
