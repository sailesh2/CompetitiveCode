#include<bits/stdc++.h>

using namespace std;

int n;
string a,b;

char inv(char x){
    return x=='0'?'1':'0';
}

vector<int> getOps(){
    vector<int> flips;
    int f=0,r=n-1;

    int cnt=0;

    for(int k=n-1;k>=0;k--){
        if(cnt==0){
            if(a[f]==b[k]){
                flips.push_back(1);
                flips.push_back(k+1);
            }else{
                flips.push_back(k+1);
            }
            f++;
        }else{
            if(inv(a[r])==b[k]){

                flips.push_back(1);
                flips.push_back(k+1);
            }else{

                flips.push_back(k+1);
            }
            r--;
        }

        cnt=1-cnt;
    }

    return flips;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>a>>b;
        vector<int> ops = getOps();
        cout<<ops.size()<<" ";
        for(int i=0;i<ops.size();i++)
            cout<<ops[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
