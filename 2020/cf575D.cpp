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

int diff(string s, vector<string> matches){
    int mini=matches[0].size();
    for(int i=0;i<3;i++){
        mini=min(mini,diff(s,matches[i]));
    }

    return mini;
}

int main(){
    int q,n,k;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n>>k;
        string s;
        cin>>s;

        vector<string> matches = generateMatches(k);
        int mini=k;
        for(int l=0;l<n;l++){
            string sub="";
            for(int j=l;j<l+k && j<n;j++){
                sub.push_back(s[j]);
            }
            if(sub.length()==k)
            mini=min(mini,diff(sub,matches));
        }
        cout<<mini<<"\n";
    }
    return 0;
}
