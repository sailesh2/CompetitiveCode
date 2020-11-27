#include<bits/stdc++.h>

using namespace std;

int n,k;

string s;
vector<vector<int>> ans;

char change(char a){
    if(a=='L')
        return 'R';
    else
        return 'L';
}

bool valid(){
    if(ans.size()>k)
        return false;

    for(int i=0;i<n-1;i++){
        if(s[i]=='R' && s[i+1]=='L'){
            return false;
        }
    }

    return true;
}

void print(){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].size()<<" ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]+1<<" ";
        }
        cout<<"\n";
    }
}

void modifyPrint(){
    int rem = ans.size();
    rem=k-rem;

    if(rem!=0){
        int lastIndex = ans.size()-1;
        for(int i=0;i<rem;i++){
            vector<int> v;
            ans.push_back(v);
        }

        int cnt=0;
        for(int i= k-1;i>=0;i--){
            if(ans[i].size()>0)
                break;
            if(lastIndex==-1){
                cnt=1;
                break;
            }
            ans[i].push_back(ans[lastIndex][ans[lastIndex].size()-1]);
            ans[lastIndex].pop_back();
            if(ans[lastIndex].size()==0)
                lastIndex--;

        }

        if(cnt==1){
            cout<<"-1";
        }else{
            print();
        }
    }else
        print();
}

int main(){
    cin>>n>>k;

    cin>>s;
    int turn=0;

    vector<int> heads;
    for(int i=0;i<n-1;i++){
        if(s[i]=='R' && s[i+1]=='L'){
            heads.push_back(i);
        }
    }
    while(turn<n*n && ans.size()<k){

        if(heads.size()==0)
            break;
        vector<int> que;
        int has[3005]={0};
        for(int i=0;i<heads.size();i++){
            s[heads[i]]='L';
            s[heads[i]+1]='R';
            if(s[heads[i]]=='L' && heads[i]-1>=0 && has[heads[i]-1]==0 && s[heads[i]-1]=='R'){
                que.push_back(heads[i]-1);
                has[heads[i]-1]=1;
            }
            if(s[heads[i]+1]=='R' && heads[i]+2<n && has[heads[i]+1]==0 && s[heads[i]+2]=='L'){
                que.push_back(heads[i]+1);
                has[heads[i]+1]=1;
            }
            turn=turn+2;

            if(turn>=n*n)
                break;
        }

        ans.push_back(heads);
        heads = que;
    }

    if(valid()){
        modifyPrint();
    }else{
        cout<<"-1";
    }
    return 0;
}
