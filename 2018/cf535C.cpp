#include<bits/stdc++.h>

using namespace std;

int n;

string generateNice(char a, char b, char c){
    string nice="";
    for(int i=0;i<n;i++){
        if(i%3==0)
            nice.push_back(a);
        else if(i%3==1)
            nice.push_back(b);
        else
            nice.push_back(c);
    }
    return nice;
}

int main(){
    cin>>n;
    string s;
    cin>>s;
    vector<string> nice;
    nice.push_back(generateNice('R','G','B'));
    nice.push_back(generateNice('R','B','G'));
    nice.push_back(generateNice('B','R','G'));
    nice.push_back(generateNice('B','G','R'));
    nice.push_back(generateNice('G','R','B'));
    nice.push_back(generateNice('G','B','R'));

    int mini=n+1,ctr=0;
    int save=-1;
    for(int i=0;i<6;i++){
        ctr=0;
        for(int j=0;j<n;j++){
            if(s[j]!=nice[i][j])
                ctr++;
            if(ctr==mini)
                break;
        }
        if(ctr<mini){
            mini=ctr;
            save=i;
        }
    }
    cout<<mini<<"\n";
    cout<<nice[save];
    return 0;
}
