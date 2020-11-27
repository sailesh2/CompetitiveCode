#include<bits/stdc++.h>

using namespace std;
int n,m;

bool canBeForged(vector<string> mat, int i , int j){
    //First
    bool ispossible = false;
    ispossible = (j+1<m && mat[i][j+1]=='#')
            && (j+2<m && mat[i][j+2]=='#')
            && (i+1<n && mat[i+1][j]=='#')
            && (i+2<n && mat[i+2][j]=='#')
            && (i+2<n && j+1<m && mat[i+2][j+1]=='#')
            && (i+2<n && j+2<m && mat[i+2][j+2]=='#')
            && (i+1<n && j+2<m && mat[i+1][j+2]=='#');

    //second
    ispossible = ispossible ||
                (j-1>=0 && mat[i][j-1]=='#')
            && (j+1<m && mat[i][j+1]=='#')
            && (i+1<n && j-1>=0 && mat[i+1][j-1]=='#')
            && (i+1<n && j+1<m && mat[i+1][j+1]=='#')
            && (i+2<n && j-1>=0 && mat[i+2][j-1]=='#')
            && (i+2<n && mat[i+2][j]=='#')
            && (i+2<n && j+1<m && mat[i+2][j+1]=='#');

    //third
    ispossible = ispossible ||
                (j-1>=0 && mat[i][j-1]=='#')
            && (j-2>=0 && mat[i][j-2]=='#')
            && (i+1<n && j-2>=0 && mat[i+1][j-2]=='#')
            && (i+1<n && mat[i+1][j]=='#')
            && (i+2<n && j-2>=0 && mat[i+2][j-2]=='#')
            && (i+2<n && j-1>=0 && mat[i+2][j-1]=='#')
            && (i+2<n && mat[i+2][j]=='#');

    //forth
    ispossible = ispossible ||
                (i-1>=0 && mat[i-1][j]=='#')
            && (i-1>=0 && j+1<m && mat[i-1][j+1]=='#')
            && (i-1>=0 && j+2<m && mat[i-1][j+2]=='#')
            && (j+2<m && mat[i][j+2]=='#')
            && (i+1<n && mat[i+1][j]=='#')
            && (i+1<n && j+1<m && mat[i+1][j+1]=='#')
            && (i+1<n && j+2<m && mat[i+1][j+2]=='#');

    //fifth
    ispossible = ispossible ||
                (i-1>=0 && mat[i-1][j]=='#')
            && (i-1>=0 && j-1>=0 && mat[i-1][j-1]=='#')
            && (i-1>=0 && j-2>=0 && mat[i-1][j-2]=='#')
            && (j-2>=0 && mat[i][j-2]=='#')
            && (i+1<n && mat[i+1][j]=='#')
            && (i+1<n && j-1>=0 && mat[i+1][j-1]=='#')
            && (i+1<n && j-2>=0 && mat[i+1][j-2]=='#');

    //sixth
    ispossible = ispossible ||
                (i-1>=0 && mat[i-1][j]=='#')
            && (i-2>=0 && mat[i-2][j]=='#')
            && (i-2>=0 && j+1<m && mat[i-2][j+1]=='#')
            && (i-2>=0 && j+2<m && mat[i-2][j+2]=='#')
            && (i-1>=0 && j+2<m && mat[i-1][j+2]=='#')
            && (j+1<m && mat[i][j+1]=='#')
            && (j+2<m && mat[i][j+2]=='#');

    //seventh
    ispossible = ispossible ||
                (j-1>=0 && mat[i][j-1]=='#')
            && (j+1<m && mat[i][j+1]=='#')
            && (i-1>=0 && j-1>=0 && mat[i-1][j-1]=='#')
            && (i-1>=0 && j+1<m && mat[i-1][j+1]=='#')
            && (i-2>=0 && j-1>=0 && mat[i-2][j-1]=='#')
            && (i-2>=0 && mat[i-2][j]=='#')
            && (i-2>=0 && j+1<m && mat[i-2][j+1]=='#');

    //eighth
    ispossible = ispossible ||
                (j-1>=0 && mat[i][j-1]=='#')
            && (j-2>=0 && mat[i][j-2]=='#')
            && (i-1>=0 && mat[i-1][j]=='#')
            && (i-1>=0 && j-2>=0 && mat[i-1][j-2]=='#')
            && (i-2>=0 && j-1>=0 && mat[i-2][j-1]=='#')
            && (i-2>=0 && mat[i-2][j]=='#')
            && (i-2>=0 && j-2>=0 && mat[i-2][j-2]=='#');

    return ispossible;
}

int main(){
    cin>>n>>m;
    vector<string> mat;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        mat.push_back(s);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='#'){
                if(!canBeForged(mat ,i , j)){
                    cnt=1;
                    break;
                }
            }
        }
    }
    if(cnt==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
