#include<bits/stdc++.h>

using namespace std;
long long int power2[200005];
long long int has[200005];
void setup(long long int l, string s){
    long long int p=1;
    for(long long int i=0;i<=l;i++){
        power2[i]=p;
        p=p*2;
    }
    long long int ctr=0;
    for(long long int i=0;i<s.length();i++){
        if(s[i]=='0')
            ctr++;
        else
            ctr=0;
        has[i]=ctr;
    }
}

long long int bin(long long int l){
    long long int ctr=0;
    while(l>0){
        l=l/2;
        ctr++;
    }
    return ctr;
}

long long int goodStr(string s, long long int k){

    long long int l=s.length();
    long long int sm=0;
    if(k>l)
        return 0;

    long long int v=0;
    for(long long int i=0;i<k;i++){
        v=v*2+(long long int)s[i]-48;

    }

    if(s[0]=='1' && (v-bin(v))==0){
        sm++;
    }
    long long int pk2=power2[k-1];
    for(long long int i=k;i<l;i++){
        if(s[i-k]=='1'){
            v=v-pk2;
        }
        if(s[i]=='1'){
            v=v*2+1;
        }else{
            v=v*2;
        }
        if(s[i-k+1]=='1' && has[i-k]>=(v-bin(v)))
            sm++;
    }
    return sm;
}

long long int goodStrings(string s){
    long long int l =s.length();
    long long int maxL = bin(l);
    setup(maxL,s);
    long long int sm=0;
    for(long long int i=1;i<=maxL;i++){
        sm=sm+goodStr(s,i);
   //     cout<<sm<<"\n";
    }

    return sm;
}

int main(){
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<goodStrings(s)<<"\n";
    }
    return 0;
}
