#include<bits/stdc++.h>

using namespace std;

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
    map<int,long long int> costMatrix;
    map<int,long long int>::iterator costMatrixIt;


    map<int,int> goCount;
    map<int,int>::iterator goCountIt;

    map<int,long long int> costMatrixR;
    map<int,long long int>::iterator costMatrixRIt;


    map<int,int> returnCount;
    map<int,int>::iterator returnCountIt;

    pair<int,int> flight;

    int prev,cnt,no,mini;
    long long int c;
    for(int i=1;i<=n;i++){
        sort(goFlights[i].begin(),goFlights[i].end());

        prev=0;
        cnt=0;
        for(int j=0;j<goFlights[i].size();j++){
            flight=goFlights[i][j];
            date=flight.first;
            cost=flight.second;
            if(cnt==0){
                mini=cost;
            }else{
                mini=min(mini,cost);
            }
            c=0;
            costMatrixIt=costMatrix.find(date);
            if(costMatrixIt!=costMatrix.end()){
                c=costMatrixIt->second;
                costMatrix.erase(costMatrixIt);
            }
            costMatrix.insert(make_pair(date,c+mini-prev));
            prev=mini;
            if(cnt==0){
                goCountIt=goCount.find(date);
                no=0;
                if(goCountIt!=goCount.end()){
                    no=goCountIt->second;
                    goCount.erase(goCountIt);
                }
                no++;
                goCount.insert(make_pair(date,no));
            }
            cnt=1;
        }
    }

long long int sm=0;
    int gc=0;
    for(costMatrixIt=costMatrix.begin();costMatrixIt!=costMatrix.end();costMatrixIt++){
        date=costMatrixIt->first;
        c=costMatrixIt->second;
        sm=sm+c;
        costMatrix.erase(costMatrixIt);
        costMatrix.insert(make_pair(date,sm));

        goCountIt=goCount.find(date);
        if(goCountIt!=goCount.end()){
            gc=gc+goCountIt->second;
            goCount.erase(goCountIt);
        }
        goCount.insert(make_pair(date,gc));

        costMatrixIt=costMatrix.find(date);
    }


    for(int i=1;i<=n;i++){
        sort(returnFlights[i].begin(),returnFlights[i].end());

        prev=0;
        cnt=0;
        for(int j=returnFlights[i].size()-1;j>=0;j--){
            flight=returnFlights[i][j];
            date=flight.first;
            cost=flight.second;
            if(cnt==0){
                mini=cost;
            }else{
                mini=min(mini,cost);
            }
            c=0;
            costMatrixRIt=costMatrixR.find(date);
            if(costMatrixRIt!=costMatrixR.end()){
                c=costMatrixRIt->second;
                costMatrixR.erase(costMatrixRIt);
            }
            costMatrixR.insert(make_pair(date,c+mini-prev));
            prev=mini;
            if(cnt==0){
                returnCountIt=returnCount.find(date);
                no=0;
                if(returnCountIt!=returnCount.end()){
                    no=returnCountIt->second;
                    returnCount.erase(returnCountIt);
                }
                no++;
                returnCount.insert(make_pair(date,no));
            }
            cnt=1;
        }
    }

    sm=0;
    int rc=0;
    if(costMatrixR.size()>0){
        costMatrixRIt=costMatrixR.end();
        costMatrixRIt--;
        while(1){
            date=costMatrixRIt->first;
            c=costMatrixRIt->second;
            sm=sm+c;
            costMatrixR.erase(costMatrixRIt);
            costMatrixR.insert(make_pair(date,sm));

            returnCountIt=returnCount.find(date);
            if(returnCountIt!=returnCount.end()){
                rc=rc+returnCountIt->second;
                returnCount.erase(returnCountIt);
            }
            returnCount.insert(make_pair(date,rc));

            costMatrixRIt=costMatrixR.find(date);
            if(costMatrixRIt==costMatrixR.begin())
                break;
            costMatrixRIt--;
        }
    }


    cnt=0;
    long long int miniC;
    int goDate,returnDate;
    /*for(costMatrixIt=costMatrix.begin();costMatrixIt!=costMatrix.end();costMatrixIt++){
        cout<<costMatrixIt->first<<" "<<costMatrixIt->second<<"\n";
    }*/
    for(costMatrixIt=costMatrix.begin();costMatrixIt!=costMatrix.end();costMatrixIt++){
       // cout<<"c\n";
        goDate=costMatrixIt->first;
        returnDate=goDate+k+1;

        goCountIt=goCount.find(goDate);
        //cout<<goDate<<" "<<returnDate<<"\n";

        returnCountIt=returnCount.lower_bound(returnDate);
        if(returnCountIt!=returnCount.end()){
            gc=goCountIt->second;
            rc=returnCountIt->second;
          //  cout<<gc<<" "<<rc<<"\n";
            if(gc==n && rc==n){
                costMatrixRIt=costMatrixR.lower_bound(returnDate);
                if(costMatrixRIt!=costMatrixR.end()){
                    c=costMatrixIt->second + (costMatrixRIt)->second;
                    if(cnt==0){
                        miniC=c;
                    }else{
                        miniC=min(miniC,c);
                    }
                    cnt=1;
                }
            }
        }
    }
    if(cnt==0){
        cout<<"-1";
    }else{
        cout<<miniC;
    }

    return 0;
}
