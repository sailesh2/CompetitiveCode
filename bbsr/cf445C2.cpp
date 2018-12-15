#include<bits/stdc++.h>

using namespace std;
vector<char> commands;
int mod=1000000007;
map<int, long long int> dp1;
map<int, long long int>::iterator dp1It;


map<int, long long int> dp2;
map<int, long long int>::iterator dp2It;
long long int noOfSyntax(int pos,int indent,int type){
    long long int c=0;
    if(pos==commands.size())
        return 1;
    if(type==0){
        if(commands[pos]=='s'){
            dp1It=dp1.find(pos+1);
            if(dp1It==dp1.end())
                c=((indent+1)*noOfSyntax(pos+1,indent,0))%mod;
            else
                c=((indent+1)*dp1It->second)%mod;
            c=c%mod;


        }else{
            dp2It=dp2.find(pos+1);
            if(dp2It==dp2.end())
                c=((indent+1)*noOfSyntax(pos+1,indent,1))%mod;
            else
                c=((indent+1)*dp2It->second)%mod;
            c=c%mod;


        }
    }else {

        if(commands[pos]=='s'){
            dp1It=dp1.find(pos+1);

            if(dp1It==dp1.end())
                c=(noOfSyntax(pos+1,indent+1,0))%mod;
            else
                c=(dp1It->second)%mod;
        }else{
            dp2It=dp2.find(pos+1);

            if(dp2It==dp2.end())
                c=(noOfSyntax(pos+1,indent+1,1))%mod;
            else
                c=(dp2It->second)%mod;
        }
        c=c%mod;
    }
    if(type==0)
        dp1.insert(make_pair(pos,c));
    else
        dp2.insert(make_pair(pos,c));
    return c;
}
int main(){
    int n;
    cin>>n;
    char ch;
    for(int i=0;i<n;i++){
        cin>>ch;
        commands.push_back(ch);
    }
    cout<<noOfSyntax(0,0,0);
    return 0;
}
