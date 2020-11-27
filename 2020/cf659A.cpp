#include<bits/stdc++.h>

using namespace std;

char getDiffChar(string s, int pos){
    if(pos<s.length()){
        return s[pos]=='a'?'b':'a';
    }else{
        return 'a';
    }
}

vector<string> getStrings(int n, int* arr){
    vector<string> strs;

    for(int i=0;i<n;i++){

        string s="";
        if(i==0){
            if(arr[i]==0){
                strs.push_back("a");
                strs.push_back("b");
            }else{
                for(int j=0;j<arr[i];j++)
                    s.push_back('a');
                strs.push_back(s);
                strs.push_back(s);
            }
        }else{
            string prev = strs[strs.size()-1];

            if(arr[i]<=arr[i-1]){
                if(arr[i]==0){
                    s.push_back(getDiffChar(prev,0));
                }else{
                    for(int j=0;j<arr[i];j++){
                        s.push_back(prev[j]);
                    }
                }

                strs.push_back(s);
            }else{
                int rem = arr[i]-arr[i-1];
                if(arr[i-1]!=0){

                    prev.push_back(getDiffChar(strs[strs.size()-2],prev.length()));
                }
                for(int j=0;j<rem-1;j++)
                    prev.push_back('a');

                strs[strs.size()-1]=prev;
                strs.push_back(prev);
            }
        }
    }

    return strs;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        vector<string> strs = getStrings(n,arr);
        for(int j=0;j<n+1;j++)
            cout<<strs[j]<<"\n";
    }
    return 0;
}
