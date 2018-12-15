#include<bits/stdc++.h>

using namespace std;

string per[24];
int ctr=0;
void formPer(int ind,string s){
    if(ind==4){
        per[ctr++]=s;
        return;
    }
    int cnt;
    cnt=0;
    for(int i=0;i<ind;i++){
        if(s[i]=='u'){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        formPer(ind+1,s+'u');
    }

    cnt=0;
    for(int i=0;i<ind;i++){
        if(s[i]=='d'){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        formPer(ind+1,s+'d');
    }

    cnt=0;
    for(int i=0;i<ind;i++){
        if(s[i]=='l'){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        formPer(ind+1,s+'l');
    }


    cnt=0;
    for(int i=0;i<ind;i++){
        if(s[i]=='r'){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        formPer(ind+1,s+'r');
    }

}
int main(){
    int n,m,savei,savej;
    cin>>n>>m;
    string s;
    char maze[n][m];
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            maze[i][j]=s[j];
            if(maze[i][j]=='S'){
                savei=i;
                savej=j;
            }
        }
    }
    string dir;
    cin>>dir;
    formPer(0,"");
    int ans=0;
    int nexti,nextj;
    int cnt=0;
    char c;
    for(int j=0;j<24;j++){
        nexti=savei;
        nextj=savej;
        cnt=0;

        for(int i=0;i<dir.length();i++){
             c=per[j][(int)dir[i]-48];
             if(c=='u'){
                nexti=nexti-1;
             }else if(c=='d'){
                nexti=nexti+1;
             }else if(c=='l'){
                nextj=nextj-1;
             }else{
                nextj=nextj+1;
             }

             if(nexti>=n || nexti<0 || nextj>=m || nextj<0){
                cnt=1;
                break;
             }
             if(maze[nexti][nextj]=='#'){
                cnt=1;
                break;
             }
             if(maze[nexti][nextj]=='E')
                break;
        }
        if(cnt==0 && maze[nexti][nextj]=='E'){
            ans++;
        }

    }
    cout<<ans;
    return 0;
}
