#include<bits/stdc++.h>

using namespace std;

string trimZeros(string s){
    string trimmed="";
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(cnt==0){
            if(s[i]!='0'){
                cnt=1;
                trimmed = trimmed + s[i];
            }
        }else{
            trimmed = trimmed + s[i];
        }
    }
    return trimmed;
}

bool compareNumeric(pair<string,int> p1, pair<string, int> p2){
    string a=p1.first;
    string b=p2.first;
    bool isSmaller =false;
    if(a.length() != b.length()){
        isSmaller = a.length()<b.length();
    }else{
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                cnt=1;
                isSmaller = a[i]<b[i];
                break;
            }
        }
        if(cnt==0){
            isSmaller = p1.second<p2.second;
        }
    }
    return isSmaller;
}

bool funInt(pair<string,int> a, pair<string,int> b){
    return compareNumeric(a,b);
}


bool funStr(pair<string,int> a, pair<string,int> b){
    return a.first.compare(b.first) < 0;
}


std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main() {
    int n;
    string s,out;
    stringstream ss;
    cin>>n;
    vector<vector<string> > col;
    cin.ignore();

    for(int i=0;i<n;i++){
        getline(cin,s);
        col.push_back(split(s,' '));
    }

    string rev,order;
    int key;
    cin>>key>>rev>>order;
    vector<pair<string,int> > toSort;

    if(order == ("numeric")){
        for(int i=0;i<col.size();i++){
            toSort.push_back(make_pair(trimZeros(col[i][key-1]),i));
        }
        sort(toSort.begin(),toSort.end(),funInt);
    }else{
        for(int i=0;i<col.size();i++){
            toSort.push_back(make_pair(col[i][key-1],i));
        }
        sort(toSort.begin(),toSort.end(),funStr);

    }

    for(int i=0;i<toSort.size();i++){
        if(rev=="false")
            key=toSort[i].second;
        else
            key=toSort[toSort.size()-1-i].second;
        for(int j=0;j<col[key].size();j++){
            cout<<col[key][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
