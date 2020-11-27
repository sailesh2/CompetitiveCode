#include<bits/stdc++.h>

using namespace std;

struct Envelope{
    long long int coins;
    int restriction;
    int end;
};

struct EnvelopeCompare{

    bool operator () (const Envelope& a, const Envelope& b){
        if(a.coins == b.coins)
            return a.restriction>b.restriction;
        return a.coins>b.coins;
    }

};

int n,m,k;
long long int dp[100005][205];

multiset<Envelope,EnvelopeCompare> envelopeSet;
multiset<Envelope,EnvelopeCompare>::iterator envelopeSetIt;

vector<Envelope> envelopes[100005];
vector<pair<long long int,int> > envelepeArr;

void clearDP(){
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            dp[i][j]=-1;
        }
    }
}

long long int minCoins(int index, int disturbed){

    if(index>n)
        return 0;
   // cout<<envelepeArr[index].first<<" ";

    if(envelepeArr[index].first==0){
        dp[index][disturbed] = minCoins(index+1,disturbed);
        return dp[index][disturbed];
    }

    long long int v;
    int next;
    next=envelepeArr[index].second+1;
    if(dp[next][disturbed]==-1)
        v=minCoins(next,disturbed) + envelepeArr[index].first;
    else
        v=dp[next][disturbed] + envelepeArr[index].first;

    if(disturbed<m){
        if(dp[index+1][disturbed+1]==-1)
            v=min(v,minCoins(index+1,disturbed+1));
        else
            v=min(v,dp[index+1][disturbed+1]);
    }

    dp[index][disturbed]=v;
    return v;
}

int main(){
    int s,t,d;
    long long int w;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>s>>t>>d>>w;
        Envelope envelope;
        envelope.coins=w;
        envelope.restriction=d;
        envelope.end = t;

        envelopes[s].push_back(envelope);
    }

    envelepeArr.push_back(make_pair(0,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<envelopes[i].size();j++){
            envelopeSet.insert(envelopes[i][j]);
        }
//        cout<<i<<"----\n";
        int cnt=0;
        envelopeSetIt = envelopeSet.begin();
        while(envelopeSetIt!=envelopeSet.end()){

            if(envelopeSetIt->end <i){
                envelopeSet.erase(envelopeSetIt);
                envelopeSetIt = envelopeSet.begin();
            }
            else{
                cnt=1;
                envelepeArr.push_back(make_pair(envelopeSetIt->coins,envelopeSetIt->restriction));
                break;
            }
        }

        if(cnt==0){
            envelepeArr.push_back(make_pair(0,0));
        }
    }
    clearDP();

    cout<<minCoins(1,0);
    return 0;
}
