#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n, m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        int mat[n][m];
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>mat[j][k];
            }
        }

        int top=0,down=n-1+m-1;
        int s=0;
        while(top<down){
            int z=0,o=0;
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    if(j+k==top || j+k==down){
                        if(mat[j][k]==0)
                            z++;
                        else
                            o++;
                    }
                }
            }

            s=s+min(z,o);
            top++;
            down--;
        }
        cout<<s<<"\n";
    }
    return 0;
}
