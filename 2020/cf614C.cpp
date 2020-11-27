#include<bits/stdc++.h>

using namespace std;

#define gc getchar

int taken[2][100005]={0};
inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

bool isPresent(int y){
    return taken[1][y]==1 || taken[1][y-1]==1 || taken[1][y+1]==1;
}

int main(){
    int n,q,x,y;
    n=lscan();
    q=lscan();
    int ctr=0;
    int blocking[100005]={0};
    for(int i=0;i<q;i++){
        x=lscan();
        y=lscan();
        x--;
        y--;
        if(taken[x][y]==0){

            if(x==0){
                if(taken[1-x][y]==1){
                    if(blocking[y]==0){
                        blocking[y]=1;
                        ctr++;
                    }
                }else if(y-1>=0 && taken[1-x][y-1]==1){
                    if(blocking[y]==0){
                        blocking[y]=1;
                        ctr++;
                    }
                }else if(y+1<n && taken[1-x][y+1]==1){
                    if(blocking[y]==0){
                        blocking[y]=1;
                        ctr++;
                    }
                }
            }else{
                if(taken[1-x][y]==1){
                    if(blocking[y]==0){
                        blocking[y]=1;
                        ctr++;
                    }
                }
                if(y-1>=0 && taken[1-x][y-1]==1){
                    if(blocking[y-1]==0){
                        blocking[y-1]=1;
                        ctr++;
                    }
                }
                if(y+1<n && taken[1-x][y+1]==1){
                    if(blocking[y+1]==0){
                        blocking[y+1]=1;
                        ctr++;
                    }
                }
            }

            taken[x][y]=1;
        }else{

            taken[x][y]=0;

            if(x==0){
                if(blocking[y]==1){
                    blocking[y]=0;
                    ctr--;
                }
            }
            else{
                if(blocking[y]==1 && !isPresent(y)){
                    blocking[y]=0;
                    ctr--;
                }
                if(blocking[y-1]==1 && !isPresent(y-1)){
                    blocking[y-1]=0;
                    ctr--;
                }
                if(blocking[y+1]==1 && !isPresent(y+1)){
                    blocking[y+1]=0;
                    ctr--;
                }
            }

        }

        if(ctr==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
