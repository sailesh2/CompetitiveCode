#include<bits/stdc++.h>
#define gc getchar

using namespace std;
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

int main(){
    int n,m,minX,maxX,minY,maxY;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=lscan();
        }
    }
    int has[100005]={0};
    int cnt=0,cnt2=0,save;
    while(1){
        cnt=0;
        save=-1;
        minX=n;
        maxX=0;
        minY=m;
        maxY=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(save==-1){
                    if(has[arr[i][j]]==0){
                        save=arr[i][j];
                        has[arr[i][j]]=1;
                        cnt=1;

                        minX=min(minX,i);
                        maxX=max(maxX,i);
                        minY=min(minY,j);
                        maxY=max(maxY,j);
                    }
                }else{
                    if(arr[i][j]==save){
                        minX=min(minX,i);
                        maxX=max(maxX,i);
                        minY=min(minY,j);
                        maxY=max(maxY,j);
                    }else{
                        if(i==maxX && j>=minY && j<=maxY){
                            cnt2=1;
                            break;
                        }
                    }
                }
            }
            if(cnt2==1)
                break;
        }
        if(cnt==0 || cnt2==1)
            break;

        if(maxY-minY!=maxX-minX){
            cnt2=1;
            break;
        }
        for(int i=minX;i<=maxX;i++){
            for(int j=minY;j<=maxY;j++){
                if(arr[i][j]!=save){
                    cnt2=1;
                    break;
                }
            }
            if(cnt2==1)
                break;
        }
        if(cnt2==1)
            break;
    }
    cout<<1-cnt2;
    return 0;
}
