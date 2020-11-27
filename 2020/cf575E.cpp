#include<bits/stdc++.h>

using namespace std;

vector<string> generateMatches(int k){
    vector<string> matches;
    string match="";
    char arr[3];
    arr[0]='R';
    arr[1]='G';
    arr[2]='B';

    for(int i=0;i<k;i++){
        match.push_back(arr[i%3]);
    }
    matches.push_back(match);
    match="";

    for(int i=0;i<k;i++){
        match.push_back(arr[(i+1)%3]);
    }

    matches.push_back(match);
    match="";

    for(int i=0;i<k;i++){
        match.push_back(arr[(i+2)%3]);
    }
    matches.push_back(match);

    return matches;
}

int diff(string s, string match){
    int ctr=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=match[i]){
            ctr++;
        }
    }

    return ctr;
}

vector<int> diff(string s, vector<string> matches){
    vector<int> d;
    for(int i=0;i<3;i++){
        d.push_back(diff(s,matches[i]));
    }

    return d;
}

int main(){
    int q,n,k;
    cin>>q;
    char colr[3];
    colr[0]='R';
    colr[1]='G';
    colr[2]='B';
    for(int i=0;i<q;i++){
        cin>>n>>k;
        string s;
        cin>>s;

        vector<string> matches = generateMatches(k);
        int mini=k;
        string sub="";
        vector<int> d,d2;
        d2.push_back(k);
        d2.push_back(k);
        d2.push_back(k);
        for(int j=0;j<k && j<n;j++){
            sub.push_back(s[j]);
        }
        if(sub.length()==k){
            d=diff(sub,matches);

            mini=min(mini,d[0]);
            mini=min(mini,d[1]);
            mini=min(mini,d[2]);
        }
        //cout<<mini<<"\n";
        for(int j=1;j<n;j++){
            if(j+k-1>=n)
                break;
            d2[0]=d[2] - ((s[j-1]=='B')?0:1) + ((s[j+k-1]==colr[(k-1+3)%3])?0:1);
            d2[1]=d[0] - ((s[j-1]=='R')?0:1) + ((s[j+k-1]==colr[(k+3)%3])?0:1);
            d2[2]=d[1] - ((s[j-1]=='G')?0:1) + ((s[j+k-1]==colr[(k+1+3)%3])?0:1);
            //cout<<"d";
            //cout<<d[2]<<" "<<d2[0]<<"\n";
            d[0]=d2[0];
            d[1]=d2[1];
            d[2]=d2[2];
            mini=min(mini,d[0]);
            mini=min(mini,d[1]);
            mini=min(mini,d[2]);

          //  cout<<mini<<" in"<<j<<"\n";
        }
        cout<<mini<<"\n";
    }
    return 0;
}
