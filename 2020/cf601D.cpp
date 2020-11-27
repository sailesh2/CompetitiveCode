#include<bits/stdc++.h>

using namespace std;

vector<char> hen;

void fillHen(){
    for(char i='a';i<='z';i++){
        hen.push_back(i);
    }
    for(char i='A';i<='Z';i++){
        hen.push_back(i);
    }
    for(char i='0';i<='9';i++){
        hen.push_back(i);
    }
}

int getCount(string * grid, int r , int c){
    int ctr=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='R')
                ctr++;
        }
    }
    return ctr;
}

void changeGrid(string * grid, int r , int c, int k){
    int ctr=0,cnt=0;
    int countRice = getCount(grid,r,c);
    int req = countRice/k;
    int left = countRice%k;
    if(left>0)
        req++;

    int rev=0;
    for(int i=0;i<r;i++){
        if(rev==0){
            for(int j=0;j<c;j++){

                char temp=hen[cnt];
                if(grid[i][j]=='R'){
                    ctr++;
                }
                grid[i][j]=temp;

                if(ctr==req){

                    cnt++;
                    if(cnt==k)
                    cnt--;
                    ctr=0;
                    if(left>0){
                        left--;
                        if(left==0)
                            req--;
                    }
                }
            }
        }else{

            for(int j=c-1;j>=0;j--){

                char temp=hen[cnt];
                if(grid[i][j]=='R'){
                    ctr++;
                }
                grid[i][j]=temp;

                if(ctr==req){
                    cnt++;
                    if(cnt==k)
                        cnt--;
                    ctr=0;
                    if(left>0){
                        left--;
                        if(left==0)
                            req--;
                    }
                }
            }

        }

        rev=1-rev;
    }
}

int main(){
    int t,r,c,k;
    cin>>t;
    fillHen();
    for(int i=0;i<t;i++){
        cin>>r>>c>>k;
        string grid[r];
        for(int j=0;j<r;j++){
            cin>>grid[j];
        }

        changeGrid(grid,r,c,k);
        for(int j=0;j<r;j++){
            cout<<grid[j]<<"\n";
        }
    }
    return 0;
}
