#include<bits/stdc++.h>

using namespace std;
int MAX=100000;

struct Triples{
    int ans1;
    int ans2;
    int ans3;
};

pair<bool,Triples> getTripples(int k,int b){
    cout<<"Tripples"<<b<<"\n";
    for(int i=1;i*i<=b;i++){
        if(b%i==0){
            int one=i;
            int two=b/i;

            cout<<one<<" "<<two<<"\n";
            if(one+two+k<=MAX){
                Triples tr;
                tr.ans1=one;
                tr.ans2=k;
                tr.ans3=two;
                return make_pair(true,tr);
            }
        }
    }

    Triples tr;
    return make_pair(false,tr);
}

pair<bool,Triples> isPossible(int a, int b){
    int k1=(int)floor((1+(sqrt(1+8*a)))/(float)2);
    int k2=(int)ceil((1-(sqrt(1+8*a)))/(float)2);

    cout<<a<<" "<<b<<" "<<k1<<"\n";
    cout<<a<<" "<<b<<" "<<k2<<"\n";
    for(int i=k2;i<=k1;i++){
    if( i>=2 && ((i*(i-1))/2 == a)){
        pair<bool,Triples> tr=getTripples(i,b);
        if(tr.first)
        return make_pair(true,tr.second);
    }
    }

    /*if( k1>=2 && ((k1*(k1-1))/2 == a)){
        pair<bool,Triples> tr=getTripples(k1,b);
        if(tr.first)
        return make_pair(true,tr.second);
    }

    if( k2>=2 && ((k2*(k2-1))/2 == a)){

        pair<bool,Triples> tr=getTripples(k2,b);
        if(tr.first)
        return make_pair(true,tr.second);
    }*/
    Triples t2;
    return make_pair(false,t2);
}

Triples getK(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            int a=i;
            int b=n/i;

            pair<bool,Triples> p=isPossible(a,b);

            if(p.first){
                return p.second;
            }

            p=isPossible(b,a);
            if(p.first){
                return p.second;
            }
        }
    }
    Triples tr;
    tr.ans1=1;
    tr.ans2=2;
    tr.ans3=n;
    return tr;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        Triples p=getK(n);
        cout<<p.ans1<<" "<<p.ans2<<" "<<p.ans3<<"\n";
        for(int j=0;j<p.ans1;j++){
            cout<<'1';

        }
        for(int j=0;j<p.ans2;j++){
            cout<<'3';
        }
        for(int j=0;j<p.ans3;j++){
            cout<<'7';
        }
        cout<<"\n";
    }
    return 0;
}
