#include<bits/stdc++.h>

#define gc getchar

using namespace std;


inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

bool songComp(pair<long long int,long long int> song1, pair<long long int,long long int> song2){
    if(song1.second == song2.second){
        return song1.first>song2.first;
    }
    return song1.second>song2.second;
}

int main(){
    int n,k;
    cin>>n>>k;
    pair<long long int,long long int> songs[n];
    long long int l,b;

    for(int i=0;i<n;i++){
        l=lscan();
        b=lscan();
        songs[i]=make_pair(l,b);
    }

    sort(songs,songs+n,songComp);

    long long int sm=0;
    multiset<long long int> lengths;
    int ctr=0;
    long long int currPleasure=0,firstSm;
    long long int maxPleasure = currPleasure;
    for(int i=0;i<n;i++){
        if(ctr<k){
                ctr++;
                sm+=songs[i].first;
                currPleasure=sm*songs[i].second;
                lengths.insert(songs[i].first);
                maxPleasure = max(maxPleasure, currPleasure);
        }else{
            firstSm = *(lengths.begin());
                sm=sm+ songs[i].first - firstSm;
                currPleasure=sm*songs[i].second;
                lengths.erase(lengths.begin());
                lengths.insert(songs[i].first);

                maxPleasure = max(maxPleasure, currPleasure);

        }
    }
    cout<<maxPleasure;
    return 0;
}
