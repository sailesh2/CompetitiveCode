#include<bits/stdc++.h>

using namespace std;

string prefix(string inp, int front, int rear){
    string ans="";
    for(int i=front;i<=rear;i++)
        ans.push_back(inp[i]);
    return ans;
}

string join(string a, string b){
    for(int i=0;i<b.length();i++)
        a.push_back(b[i]);
    return a;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ctr=0;
    while(1){
        int save=-1;
        for(int i=n-1;i>0;i--){

                if((s[i]-s[i-1]==1)){
                    save=i;
                    break;
                }

        }
        if(save==-1){
            for(int i=0;i<n-1;i++){

                    if((s[i]-s[i+1]==1)){
                        save=i;
                        break;
                    }

            }
        }
        if(save==-1)
            break;
        string pre = prefix(s,0,save-1);
        string post = prefix(s,save+1,n-1);
        s=join(pre,post);
        n=s.length();
        ctr++;
    }
    cout<<s<<"\n";
    cout<<ctr;
    return 0;
}
