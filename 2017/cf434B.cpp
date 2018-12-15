#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    set<int> fl;
    cin>>n>>m;
    int f,k;
    int flatMin[105]={0};
    int flatMax[105]={0};
    for(int i=0;i<105;i++){
        flatMin[i]=500;
    }
    for(int i=0;i<m;i++){
        cin>>f>>k;
        flatMax[k]=max(flatMax[k],f);
        flatMin[k]=min(flatMin[k],f);
        fl.insert(k);
    }
    if(m==0){
        if(n==1){
            cout<<"1";
        }
        else{
            cout<<"-1";
        }
    } else{
        vector<int> ans;
        vector<int>::iterator ansIt;
        int cnt=0,flrc,flr=0,flmin,flmax,save;
        for(int i=1;i<=101;i++){
            flr=1;
            cnt=0;
            flrc=0;
            save=-1;
            for(int j=1;j<=101;){
                flmin=j;
                flmax=j+i-1;
                if(fl.count(flr)>0){
                   if(flatMin[flr]<flmin || flatMax[flr]>flmax){
                    cnt=1;
                    break;
                   }
                   flrc++;
                }
                if(n>=flmin && n<=flmax){
                    save=flr;
                }
                flr++;
                j=j+i;
            }
            if(cnt==0 && flrc>=fl.size() && save!=-1){
                ansIt=find(ans.begin(),ans.end(),save);
                if(ansIt==ans.end())
                    ans.push_back(save);
            }
        }
        if(ans.size()==0 || ans.size()>1){
            cout<<"-1";
        }else{
            cout<<ans[0];
        }
    }
    return 0;
}
