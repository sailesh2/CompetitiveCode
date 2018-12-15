#include<bits/stdc++.h>

using namespace std;

void findCommands(int i,int val, char * com){
    if(i>5)
        return;
    int x;
    char c;
    for(int j=0;j<i;j++){
        c=com[j];
        if(c=='|'){
            x=x | curr;
        } else if(c=='&'){
            x=x & curr;
        } else{
            x=x ^ curr;
        }
    }
    if(val==x){
        for(int j=0;j<i;j++){
            ans.push_back(char[j]);
        }
        return;
    }
    com[i+1]='|';
    findCommands(i+1,val,com);


    com[i+1]='&';
    findCommands(i+1,val,com);


    com[i+1]='^';
    findCommands(i+1,val,com);
}

int main(){
    int n;
    char c;
    int curr;
    cin>>n;
    int x=2;
    for(int i=0;i<n;i++){
        cin>>c>>curr;
        if(c=='|'){
            x=x | curr;
        } else if(c=='&'){
            x=x & curr;
        } else{
            x=x ^ curr;
        }
    }
    char com[6];
    findCommands(0,x,com);

    for(int i=0;i<ans.size();i++){
        cout<<
    }
    return 0;
}
