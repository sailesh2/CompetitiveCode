#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m,x,y;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>x>>y;

        string mat[n];
        for(int j=0;j<n;j++){
            cin>>mat[j];
        }
        int c=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(mat[j][k]=='.'){
                    if(k+1<m && mat[j][k+1]=='.'){
                        c=c+min(2*x,y);
                        k++;
                    }else{
                        c=c+x;
                    }
                }
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}
