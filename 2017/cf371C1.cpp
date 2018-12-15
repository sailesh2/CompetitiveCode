#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int conv(long long int a){
    int b,v=0,p=1;
    while(a>0){
        b=(a%10);
        if(b%2!=0){
            v=v+p;
        }
        a=a/10;
        p=p*2;
    }
    return v;
}


int convs(string a){
    int b,v=0,p=1;
    int i=a.length()-1;;
    while(i>=0){
        if(a[i]=='1'){
            v=v+p;
        }
        i--;
        p=p*2;
    }
    return v;
}

int main(){
    int t,cnt;
    int s;
    long long int a;
    char c;
    string str;
    cin>>t;
    map<int,int> mp;
    map<int,int>::iterator mpIt;
    vector<int> ans;
    for(int i=0;i<t;i++){
        cin>>c;

        if(c=='?'){
            cin>>str;
            s=convs(str);
            mpIt=mp.find(s);
            if(mpIt==mp.end()){
                ans.push_back(0);
            } else{
                ans.push_back(mpIt->second);
            }
        } else{
            cin>>a;
            s=conv(a);
            mpIt=mp.find(s);
            if(c=='+'){
                if(mpIt==mp.end()){
                    mp.insert(make_pair(s,1));
                } else{
                    cnt=mpIt->second;
                    mp.erase(mpIt);
                    mp.insert(make_pair(s,cnt+1));
                }
            } else{
                if(mpIt!=mp.end()){
                    cnt=mpIt->second;
                    mp.erase(mpIt);
                    if(cnt-1>=0)
                        mp.insert(make_pair(s,cnt-1));
                }
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1)
            cout<<ans[i];
        else
            cout<<ans[i]<<"\n";
    }
}
