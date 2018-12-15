#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<string> tictac[3][3];
    string s,blank;
    int x,y;
    for(int k=0;k<3;k++){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>s;
                tictac[k][j].push_back(s);
            }
        }
        getline(cin,blank);
    }

    cin>>x>>y;


    int x1=x%3;
    if(x1==0)
        x1=3;
    int y1=y%3;
    if(y1==0)
        y1=3;
    x1--;
    y1--;
    int cnt=0;
    vector<string> v1;
    vector<string> v= tictac[x1][y1];
    for(int k=0;k<v.size();k++){
        s=v[k];
        for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                cnt=1;
                s[i]='!';
            }
        }
        v1.push_back(s);
    }
    if(cnt==0){
        vector<string> strs;
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<tictac[i][j].size();k++){
                    s=tictac[i][j][k];
                    for(int l=0;l<s.length();l++){
                        if(s[l]=='.')
                            s[l]='!';
                    }
                    strs.push_back(s);
                }
                tictac[i][j].clear();
                tictac[i][j] = strs;
                strs.clear();
            }
        }
    }else{
        tictac[x1][y1].clear();
        tictac[x1][y1]=v1;
    }

    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            for(int j=0;j<3;j++){
                cout<<tictac[i][j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
