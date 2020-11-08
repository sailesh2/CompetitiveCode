#include<bits/stdc++.h>

using namespace std;

bool trainComp(pair<long long int,long long int> a,pair<long long int,long long int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

bool trainSqrtComp(pair<long long int,long long int> a,pair<long long int,long long int> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

struct TrainInfo{
    long long int maxT;
    vector<long long int> trainStatus;
    long long int nextTrain;
};

int main(){
    long long int n,p;
    cin>>n>>p;
    vector<vector<pair<long long int,long long int> > > trains;
    long long int x;
    long long int ans[n];
    pair<long long int,long long int> arr[n];
    for(long long int i=0;i<n;i++){
        cin>>x;
        arr[i]=make_pair(x,i);
    }

    sort(arr,arr+n,trainComp);
    long long int root = sqrt(n);
    for(long long int i=0;i<n;i++){
        if(i%root==0){
            vector<pair<long long int,long long int> > v;
            trains.push_back(v);
        }
        trains[trains.size()-1].push_back(arr[i]);
    }

    long long int tz=trains.size();
    for(long long int i=0;i<tz;i++){
        sort(trains[i].begin(),trains[i].end(),trainSqrtComp);
    }

    vector<TrainInfo> trainInfos;

    for(long long int i=0;i<tz;i++){
        vector<long long int> v;
        long long int maxi=0;
        for(long long int j=0;j<trains[i].size();j++){
            maxi=max(maxi,trains[i][j].first);
            v.push_back(0);
        }
        TrainInfo trainInfo;
        trainInfo.maxT=maxi;
        trainInfo.nextTrain=0;
        trainInfo.trainStatus=v;
        trainInfos.push_back(trainInfo);
    }

    long long int startT=0,mini,saveI,saveJ;
    while(1){
        saveI=-1;
        saveJ=-1;
        mini=1000000000000000;
        for(long long int i=0;i<tz;i++){
            if(startT<trainInfos[i].maxT && trainInfos[i].nextTrain<trainInfos[i].trainStatus.size()){
                for(long long int j=0;j<trainInfos[i].trainStatus.size();j++){
                    if(trainInfos[i].trainStatus[j]==0){
                        if(trains[i][j].first<=startT){
                            if(trains[i][j].second<mini){
                                mini=trains[i][j].second;
                                saveI=i;
                                saveJ=j;
                            }
                        }
                    }
                }
                break;
            }
            if(trainInfos[i].nextTrain<trainInfos[i].trainStatus.size()){
                if(trains[i][trainInfos[i].nextTrain].second<mini){
                    mini=trains[i][trainInfos[i].nextTrain].second;
                    saveI=i;
                    saveJ=trainInfos[i].nextTrain;
                }
            }
        }

        if(saveI==-1){
            for(long long int i=0;i<tz;i++){
                if(trainInfos[i].nextTrain<trainInfos[i].trainStatus.size()){
                    saveI=i;
                    for(long long int j=0;j<trainInfos[i].trainStatus.size();j++){
                        if(trainInfos[i].trainStatus[j]==0){
                            if(trains[i][j].first<mini){
                                mini=trains[i][j].first;
                                saveJ=j;
                            }
                        }
                    }
                    break;
                }
            }
        }

        if(saveI==-1)
            break;

        long long int cnt=0;
        trainInfos[saveI].trainStatus[saveJ]=1;
        startT=max(startT,trains[saveI][saveJ].first)+p;
        ans[trains[saveI][saveJ].second]=startT;
        for(long long int i=trainInfos[saveI].nextTrain;i<trainInfos[saveI].trainStatus.size();i++){
            if(trainInfos[saveI].trainStatus[i]==0){
                cnt=1;
                trainInfos[saveI].nextTrain=i;
                break;
            }
        }
        if(cnt==0)
            trainInfos[saveI].nextTrain=trainInfos[saveI].trainStatus.size();
    }

    for(long long int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
}
