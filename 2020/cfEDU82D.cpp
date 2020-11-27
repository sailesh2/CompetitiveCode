#include<bits/stdc++.h>

using namespace std;

string getDig(long long int n){
    string s="";
    while(n>0){
        s.push_back((char)(n%2+48));
        n=n/2;
    }
    return s;
}

long long int getMinDiv(long long int x, long long int m){
    string digX=getDig(x);
    string digM=getDig(m);
    long long int j=0;
    long long int c=0;
    for(long long int i=0;i<digM.length();i++){
        if(digM[i]=='1'){
            while(j<digX.length()){
                if(digX[j]=='1'){
                    c=c+j-i;
                    break;
                }
                j++;
            }
        }
        j++;
    }
    return c;
}

int main(){
    long long int t,n,m,x;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>m>>n;
        long long int s=0;
        for(long long int j=0;j<n;j++){
            cin>>x;
            s=s+x;
        }

        if(s<m){
            cout<<"-1\n";
        }else{
            cout<<getMinDiv(s,m)<<"\n";
        }
    }
    return 0;
}
