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
struct boundaries{
    int minX;
    int maxX;
    int minY;
    int maxY;
};
int main(){
    int n,m,minX,maxX,minY,maxY;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=lscan();
        }
    }
    int taken[1000]={0};
    int takenMin[1000]={0};
    int takenMax[1000]={0};
    int cnt=0;
    int maxiX,miniX,maxiY,miniY;
    map<int,pair<int,int> > hasX;
    map<int,pair<int,int> >::iterator hasXIt;

    map<int,pair<int,int> > hasY;
    map<int,pair<int,int> >::iterator hasYIt;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            hasXIt=hasX.find(arr[i][j]);
            if(hasXIt==hasX.end()){
                if(taken[i]!=0){
                    if(j>=takenMin[i] && j<=takenMax[i]){
                        cnt=1;
                        break;
                    }
                }

                maxiX=0;
                maxiY=0;
                for(int k=j;k<m;k++){
                    if(arr[i][k]!=arr[i][j]){
                        break;
                    }else{
                        maxiY=max(maxiY,k);
                    }
                }
                for(int k=i;k<n;k++){
                    if(arr[k][j]!=arr[i][j]){
                        break;
                    }else{
                        maxiX=max(maxiX,k);
                    }
                }
                if(maxiX-i!=maxiY-j){
                    cnt=1;
                    break;
                }
                for(int k=i;k<=maxiX;k++){
                    if(taken[k]==0){
                        taken[k]=1;
                        takenMin[k]=j;
                        takenMax[k]=maxiY;

                    }else{
                        takenMin[k]=min(takenMin[k],j);
                        takenMax[k]=min(takenMax[k],maxiY);
                    }
                }
                hasX.insert(make_pair(arr[i][j],make_pair(i,maxiX)));
                hasY.insert(make_pair(arr[i][j],make_pair(j,maxiY)));
            }else{
                miniX=(hasXIt->second).first;
                maxiX=(hasXIt->second).second;
                hasYIt=hasY.find(arr[i][j]);
                miniY=(hasYIt->second).first;
                maxiY=(hasYIt->second).second;
                if(i>=miniX && i<=maxiX && j>=miniY && j<=maxiY){

                }else{
                    cnt=1;
                    break;
                }
            }

        }
       if(cnt==1)
            break;
    }
    cout<<1-cnt;
    return 0;
}
