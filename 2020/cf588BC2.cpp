#include<bits/stdc++.h>

using namespace std;

bool allDistinct(int cnt, int* has){
    int cnt2=0;
        if(has[cnt+1]>0){
            cnt2=has[cnt+1];
            if(cnt2==1)
                return true;
        }else if(has[cnt-1]>0){
            if(has[cnt]==1)
                return true;
        }
    return has[1]==1;
}

int main(){
    int n;
    cin>>n;
    int col[n];
    for(int i=0;i<n;i++){
        cin>>col[i];
    }

    int colCnt[100005]={0};
    int colHas[100005]={0};
    int distCol=0;

    int save=-1;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(i==0){
            save=col[i];
            maxi=max(maxi,i+1);
        }else{
            if(save==col[i]){
                maxi=max(maxi,i+1);
            }else{
                save=-1;
            }
        }
        if(colCnt[col[i]]>0){
            colHas[colCnt[col[i]]]--;
            if(colHas[colCnt[col[i]]]==0)
                distCol--;
        }
        colCnt[col[i]]++;
        if(colHas[colCnt[col[i]]]==0)
            distCol++;

        colHas[colCnt[col[i]]]++;

        if(distCol==2){
            if(allDistinct(colCnt[col[i]],colHas)){
                maxi=max(maxi,i+1);
            }
        }
        if(distCol==1 && colHas[1]>0){
            maxi=max(maxi,i+1);
        }
    }
    cout<<maxi;
    return 0;
}
