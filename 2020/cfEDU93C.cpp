#include<bits/stdc++.h>

using namespace std;

long long int stkArray(string s, long long int n){

    long long int stk[n];
    long long int top=-1;
    long long int has[100005]={0};
    long long int ctr=0;
    for(long long int i=0;i<n;i++){
        char c = s[i];

        if(c=='1'){
            has[i]=((i-1>=0)?(has[i-1]+1):1);
            ctr=ctr+has[i];
        }else if(c=='0'){
            if(top>-1){
                s[stk[top]]=s[stk[top]]-1;
                if(s[stk[top]]=='1'){

                    has[stk[top]]=((stk[top]-1>=0)?(has[stk[top]-1]+1):1);
                    ctr=ctr+has[stk[top]];
                    top--;
                }
            }
        }else{
            stk[++top]=i;
        }
    }

    //cout<<ctr<<"\n";
    return ctr;
}

string rev(string s, long long int n){
    string r="";
    for(long long int i=n-1;i>=0;i--)
        r.push_back(s[i]);

    return r;
}

long long int oneSubarray(string s, long long int n){
    long long int sm=0;
    long long int ctr=0;
    for(long long int i=0;i<n;i++){
        if(s[i]=='1')
            ctr++;
        else{
            sm=sm+(ctr*(ctr+1))/2;
            ctr=0;
        }
    }
    sm=sm+(ctr*(ctr+1))/2;
    return sm;
}

long long int goodSubArrays(string s, long long int n){
    long long int ans = stkArray(s,n) + stkArray(rev(s,n),n) - oneSubarray(s,n);
    return ans;
}

long long int goodSubArrays(string s){
    long long int n = s.length();
    long long int sm=0;
    long long int ctr=0;

    for(long long int i=0;i<n;i++){
        long long int rem = s[i]-'0'-1;
        if(rem>=0){
            long long int cnt=0;
            long long int save=i;
            for(long long int j=i+1;j<i+1+rem;j++){
                if(s[j]!='0'){
                    cnt=1;
                    break;
                }
                save=j;
            }
            if(cnt==0)
                ctr++;
            else{

                sm=sm+(ctr*(ctr+1))/2;
                ctr=0;
                i=save;
            }

        }else{
            sm=sm+(ctr*(ctr+1))/2;
            ctr=0;
        }
    }
    sm=sm+(ctr*(ctr+1))/2;
    return sm;
}

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;

        string s;
        cin>>s;
        cout<<goodSubArrays(s,n)<<"\n";
    }
    return 0;
}
