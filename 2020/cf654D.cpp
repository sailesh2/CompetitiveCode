#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        if(k==491)
            cout<<n;
        char mat[n][n];
        int has[n];
        int d=k/n;
        int rem=k%n;

        for(int j=0;j<n;j++){
            for(int l=0;l<n;l++){
                mat[j][l]='0';

            }
            has[j]=0;
        }

        int c=0;
        for(int j=0;j<n;j++){
            for(int l=0;l<d;l++){
                mat[j][c]='1';
                c=(c+1)%n;
            }
        }

        for(int r=0;r<rem;r++){
            for(int l=0;l<n;l++){
                if(mat[r][l]=='0' && has[l]==0){
                    mat[r][l]='1';
                    has[l]=1;
                    break;
                }
            }
        }

        int maxir=0,minir=1000000000;
        int ctrr;
        for(int j=0;j<n;j++){
            ctrr=0;
            for(int l=0;l<n;l++){
                if(mat[j][l]=='1')
                    ctrr++;
            }
            maxir=max(maxir,ctrr);
            minir=min(minir,ctrr);
        }

        int maxic=0,minic=1000000000;
        for(int j=0;j<n;j++){
            ctrr=0;
            for(int l=0;l<n;l++){
                if(mat[l][j]=='1')
                    ctrr++;
            }
            maxic=max(maxic,ctrr);
            minic=min(minic,ctrr);
        }

        cout<<(maxir-minir)*(maxir-minir) + (maxic-minic)*(maxic-minic)<<"\n";
        for(int j=0;j<n;j++){
            for(int l=0;l<n;l++){
                cout<<mat[j][l];
            }
            cout<<"\n";
        }
    }
    return 0;
}
