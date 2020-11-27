#include<bits/stdc++.h>

using namespace std;
double INF = 1000000000;
long long int infs=0;
long long int zeros=0;
set<long long int> infSet;
set<long long int> zeroSet;

double getSlope(pair<long long int,long long int> p1,pair<long long int,long long int> p2){
    if(p2.first==p1.first)
        return INF;
    return (double)(p2.second-p1.second)/(p2.first-p1.first);
}

long long int getLines(vector<pair<long long int, long long int> > poles){
    set<double> slopes;
    for(int i=0;i<poles.size();i++){
        for(int j=i+1;j<poles.size();j++){
            double m = getSlope(poles[i],poles[j]);
            if(m==INF){
                infSet.insert(poles[i].first);
            }else if(m==0){
                zeroSet.insert(poles[i].second);
            }else
                slopes.insert(m);
        }
    }
    return (long long int)(slopes.size());
}

int main(){
    int n;
    cin>>n;
    long long int x,y;
    vector<pair<long long int,long long int> > poles;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        poles.push_back(make_pair(x,y));
    }

    long long int lines = getLines(poles);
    infs = (long long int)(infSet.size());
    zeros = (long long int)(zeroSet.size());
    long long int intersections = (lines*(lines-1))/2 + infs*lines + zeros*lines + infs*zeros;
    cout<<intersections;
    return 0;
}
