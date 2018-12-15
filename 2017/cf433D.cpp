#include<bits/stdc++.h>

using namespace std;


int binSear(int date,vector<pair<int,int> > flights){
    int ctr=1;
    int save=-1;
    int save2=-1;
    int n=flights.size();

    while(1){
        while(save+ctr<n && flights[save+ctr].first<date){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int date,c1,c2,cost;
    vector<pair<int,int> > returnFlights[n+2];
    vector<pair<int,int> > goFlights[n+2];
    for(int i=0;i<m;i++){
        cin>>date>>c1>>c2>>cost;
        if(c1==0){
            returnFlights[c2].push_back(make_pair(date,cost));
        }else{
            goFlights[c1].push_back(make_pair(date,cost));
        }
    }
    pair<int,int> flight;
    int miniC,returnCost;
    long long int tc=0;
    int cnt2=0,cnt,ind;
    for(int i=1;i<=n;i++){
        sort(returnFlights[i].begin(),returnFlights[i].end());
        int mini;
        int minCost[returnFlights[i].size()];
        for(int j=returnFlights[i].size()-1;j>=0;j--){
            if(j==returnFlights[i].size()-1){
                mini=returnFlights[i][j].second;
            }else{
                mini=min(mini,returnFlights[i][j].second);
            }
            minCost[j]=mini;
        }
        cnt=0;

        for(int j=0;j<goFlights[i].size();j++){
            flight=goFlights[i][j];
            ind=binSear(flight.first+k+1,returnFlights[i]);
          //  cout<<ind<<"\n";
            if(ind >=0 && ind<returnFlights[i].size()){
                returnCost=minCost[ind]+flight.second;
                if(cnt==0)
                    miniC=returnCost;
                else
                    miniC=min(miniC,returnCost);
                cnt=1;
            }
        }
        //cout<<i<<" "<<cnt<<"\n";
        if(cnt==0){
            cnt2=1;
            break;
        }
        tc=tc+(long long int)miniC;
    }
    if(cnt2==1){
        cout<<"-1";
    }else{
        cout<<tc;
    }
    return 0;
}
