#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int arr[n][n];
    long long int row[n],col[n];
    long long int sm=0,rows=0,cols=0,diag=0,revDiag=0;

    int savei,savej,cnt=0;
    for(int i=0;i<n;i++){
        rows=0;
        cnt=0;
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0){
                savei=i;
                savej=j;
                cnt=1;
            }
            rows=rows+arr[i][j];
        }
        row[i]=rows;
        if(cnt==0){
            sm=sm+row[i];
        }
    }


    if(n==1){
        cout<<"1";
    } else {
        long long int diff=(sm/(n-1)) - row[savei];
        row[savei]=row[savei]+diff;

        arr[savei][savej]=diff;

        for(int i=0;i<n;i++){
            cols=0;
            for(int j=0;j<n;j++){
                cols=cols+arr[j][i];
            }
            col[i]=cols;
        }

        for(int i=0;i<n;i++){
            diag=diag+arr[i][i];
        }

        for(int i=0,j=n-1;i<n;i++,j--){
            revDiag=revDiag+arr[i][j];
        }

        cnt=0;
        for(int i=0;i<n-1;i++){
            if(row[i]!=row[i+1]){
                cnt=1;
                break;
            }
            if(col[i]!=col[i+1]){
                cnt=1;
                break;
            }
        }

        if(row[0]!=col[0]){
            cnt=1;
        }

        if(diag!=revDiag || row[0]!=diag){
            cnt=1;
        }

        if(cnt==0){
            if(diff>1000000000000000000 || diff<1)
                cout<<"-1";
            else
                cout<<diff;
        } else{
            cout<<"-1";
        }
    }

    return 0;
}
