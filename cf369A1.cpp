#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    vector<string> v;
    int cnt=0,ind;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='O' && s[1]=='O'){
            ind=i;
            cnt=1;
        }
        if(s[3]=='O' && s[4]=='O'){
            ind=i;
            cnt=2;
        }
        v.push_back(s);
    }

    if(cnt==0){
        cout<<"NO";
    } else{
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            if(i==ind){
                if(cnt==1){
                    cout<<"++|"<<(v.at(i))[3]<<(v.at(i))[4];
                } else{
                    cout<<(v.at(i))[0]<<(v.at(i))[1]<<"|++";
                }
            } else{
                cout<<v.at(i);
            }
            cout<<"\n";
        }
    }

}
