#include<bits/stdc++.h>

using namespace std;

int cycles(string s){
    int ctr=0,c=0;
    pair<char,int> stk[s.length()];
    int top=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            stk[++top]=make_pair(s[i],i);
        }else{
            if(top>=0 && stk[top].first=='(')
                top--;
            else
                stk[++top]=make_pair(s[i],i);
        }
    }
    int firstO=s.length();
    for(int i=0;i<=top;i++){
        if(stk[i].first=='('){
            firstO=stk[i].second;
            break;
        }
    }

    string t="";
    for(int i=firstO;i<s.length();i++){
        t.push_back(s[i]);
    }
    for(int i=0;i<firstO;i++){
        t.push_back(s[i]);
    }

    for(int i=0;i<t.length();i++){
        if(t[i]=='('){
            ctr++;
        }else{
            ctr--;
        }

        if(ctr==0)
            c++;
    }
    return ctr==0?c:0;
}

int main(){
    int n,savei=0,savej=0;
    cin>>n;
    string s;
    cin>>s;
    int maxi=0;
    char temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;

            int k=cycles(s);
            if(k>maxi){
                maxi=k;
                savei=i;
                savej=j;
            }

            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }

    cout<<maxi<<"\n";
    cout<<savei+1<<" "<<savej+1;
    return 0;
}
