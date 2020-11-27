#include<bits/stdc++.h>
#define MAX_COOKIE_EAT_TIME 1000005
#define LOGGER_ON false

using namespace std;
long long int t,l;
int n,p;
vector<int> tree[100005];
long long int cookies[100005];
long long int cookieEatTimes[100005];
long long int travelTime[100005];

pair<long long int,long long int> getBIT(pair<long long int,long long int>* BTree, int index)
{
    pair<long long int,long long int> sum = make_pair(0,0);


    while (index>0)
    {
        sum.first += (BTree[index]).first;
        sum.second += (BTree[index]).second;

        index -= index & (-index);
    }
    return sum;
}

pair<long long int,long long int> getOneBIT(pair<long long int,long long int>* BTree, int index)
{
    pair<long long int, long long int> curr = getBIT(BTree, index);
    pair<long long int, long long int> prev = getBIT(BTree, index-1);
    return make_pair(curr.first - prev.first, curr.second - prev.second);
}

void insertBIT(pair<long long int,long long int>* BTree, long long int val, long long int index)
{
    long long int timeV = val*index;
    while (index < MAX_COOKIE_EAT_TIME)
    {
        BTree[index].first += timeV;
        BTree[index].second += val;

        index += index & (-index);
    }
}

void removeBIT(pair<long long int,long long int>* BTree, long long int val, long long int index)
{
    insertBIT(BTree, -val, index);
}


bool canGOBackInTree(long long int time, pair<long long int,long long int> cookiesEatBTValue){
    return time*2 + cookiesEatBTValue.first <=t;
}

bool canGOBackInTree(long long int time, long long int cookiesEatTime){
    return time*2 + cookiesEatTime <=t;
}

long long int getMaxCookiesCanEat(long long int time, pair<long long int,long long int>* cookieEatBT){
    int ctr=1;
    int save=0;
    int save2=0;

    while(1){
        while(save+ctr<MAX_COOKIE_EAT_TIME && canGOBackInTree(time, getBIT(cookieEatBT,save+ctr))){
            save2=save+ctr;
            ctr=ctr*2;
        }


        if(LOGGER_ON){
        if(save+ctr<MAX_COOKIE_EAT_TIME){
        cout<<time<<"getBIT(cookieEatBT,save+ctr-1).first"<<save+ctr-1<<"-";
        cout<<getBIT(cookieEatBT,save+ctr).first<<"\n";
        }
        }


        if(save+ctr<MAX_COOKIE_EAT_TIME
           && canGOBackInTree(time, getBIT(cookieEatBT,save+ctr-1).first + save+ctr)){

            pair<long long int,long long int> cookieBTValue = getBIT(cookieEatBT,save+ctr-1);
            long long int timerem = t - 2*time - cookieBTValue.first;
            return cookieBTValue.second + timerem/(save+ctr);
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    //cout<<save;
    if(save==0)
        return 0;
    return getBIT(cookieEatBT,save).second;
}

long long int eatMaxCookies(int root, long long int time, pair<long long int,long long int>* cookieEatBT){

    vector<long long int> cookiesAte;
    if(time*2>=t){
        return 0;
    }
if(LOGGER_ON)
cout<<"root"<<root<<"\n";
    long long int currentMaxCookie=getMaxCookiesCanEat(time, cookieEatBT);

    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        insertBIT(cookieEatBT, cookies[child], cookieEatTimes[child]);
        cookiesAte.push_back(eatMaxCookies(child, time+travelTime[child], cookieEatBT));
        removeBIT(cookieEatBT, cookies[child], cookieEatTimes[child]);
    }

    sort(cookiesAte.begin(), cookiesAte.end());

    long long int maxCookies=currentMaxCookie;
    if(root==1){
        if(cookiesAte.size()>0)
        maxCookies = max(maxCookies, cookiesAte[cookiesAte.size()-1]);
    }else{
        if(cookiesAte.size()>1){
            maxCookies = max(maxCookies, cookiesAte[cookiesAte.size()-2]);
        }
    }
    return maxCookies;
}

int main(){
    cin>>n>>t;

    for(int i=1;i<=n;i++){
        cin>>cookies[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cookieEatTimes[i];
    }

    for(int i=2;i<=n;i++){
        cin>>p>>l;
        tree[p].push_back(i);
        travelTime[i]=l;
    }

    pair<long long int,long long int> BTree[MAX_COOKIE_EAT_TIME];
    for(int i=1;i<MAX_COOKIE_EAT_TIME;i++){
        BTree[i] = make_pair(0,0);
    }

    insertBIT(BTree, cookies[1], cookieEatTimes[1]);
    cout<<eatMaxCookies(1,0,BTree);
    return 0;
}
