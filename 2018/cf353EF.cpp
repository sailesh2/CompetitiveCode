#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    int cnt1=0;
    cin>>n>>m;
    int arr[n];
    int mini=1000000009;
    int maxi=-1000000009;
    int save=-1;
    vector<int> maxSave;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<mini){
            mini=arr[i];
            save=i;
        }
        maxi=max(arr[i],maxi);
    }
    for(int i=0;i<n;i++){
        if(arr[i]==maxi)
            maxSave.push_back(i);
    }
    int seg[m][2];
    int x,y;
    vector<int> minSeg;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        seg[i][0]=x-1;
        seg[i][1]=y-1;
        if(cnt1==0){
        for(int j=0;j<maxSave.size();j++){
            if(maxSave[j]<seg[i][0] || maxSave[j]>seg[i][1]){
                cnt1=1;
                break;
            }
        }
        }
    }
    for(int i=0;i<m;i++){
        if(save>=seg[i][0] && save<=seg[i][1]){
            if(minSeg.size()==0)
            minSeg.push_back(i);
            else{
                if(cnt1==1)
                    minSeg.push_back(i);
                else{
                    for(int j=0;j<maxSave.size();j++){
                        if(maxSave[j]>=seg[i][0] && maxSave[j]<=seg[i][1]){
                            cnt1=1;
                            break;
                        }
                    }
                }
            }
        }
    }

    int cnt=0,restMax=-100000000;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<minSeg.size();j++){
            if(i>=seg[minSeg[j]][0] && i<=seg[minSeg[j]][i]){
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            restMax=max(restMax,arr[i]);
    }

    int segMax=-100000000,locMax;
    map<pair<int,int>,int> locMaxMap;
    map<pair<int,int>,int>::iterator locMaxMapIt;
    for(int i=0;i<minSeg.size();i++){

        locMaxMapIt = locMaxMap.find(make_pair(seg[minSeg[i]][0],seg[minSeg[i]][1]));
        if(locMaxMapIt != locMaxMap.end()){
            locMax=locMaxMapIt->second;
            locMaxMap.erase(locMaxMapIt);
            locMax--;
        }else{
            locMax=-100000000;
            for(int j=seg[minSeg[i]][0];j<=seg[minSeg[i]][1];j++){
                locMax=max(locMax,arr[j]);
            }
        }
        locMaxMap.insert(make_pair(make_pair(seg[minSeg[i]][0],seg[minSeg[i]][1]),locMax));
    }

    for(int i=0;i<minSeg.size();i++){
        locMaxMapIt = locMaxMap.find(make_pair(seg[minSeg[i]][0],seg[minSeg[i]][1]));
        locMax=locMaxMapIt->second;
        restMax = max(restMax,locMax);
    }

    cout<<restMax - (mini-minSeg.size())<<"\n";
    cout<<minSeg.size()<<"\n";
    for(int i=0;i<minSeg.size();i++){
        cout<<minSeg[i]+1<<" ";
    }
    return 0;
}
