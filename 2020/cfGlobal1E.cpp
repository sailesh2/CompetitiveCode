#include<bits/stdc++.h>
#define gc getchar

using namespace std;

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    int n;
    n=lscan();
    long long int c,prev,s0,t0,sl,tl;
    vector<long long int> diff1,diff2;
    for(int i=0;i<n;i++){
        c=lscan();
        if(i!=0){
            diff1.push_back(prev-c);
        }else{
            s0=c;
        }

        if(i==n-1){
            sl=c;
        }
        prev=c;
    }

    for(int i=0;i<n;i++){
        c=lscan();
        if(i!=0){
            diff2.push_back(prev-c);
        }else{
            t0=c;
        }

        if(i==n-1){
            tl=c;
        }
        prev=c;
    }

    sort(diff1.begin(),diff1.end());
    sort(diff2.begin(),diff2.end());

    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(diff1[i]!=diff2[i]){
            cnt=1;
            break;
        }
    }

    if(cnt==0 && s0==t0 && sl==tl){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
