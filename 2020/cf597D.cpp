#include<bits/stdc++.h>

using namespace std;
long long int n;
long long int mini;
struct Coordinate{
    long long int index;
    long long int x;
    long long int y;
    long long int c;
    long long int k;
};

bool coordinateComp(Coordinate a, Coordinate b){
    return (a.x+a.y)*a.k-a.c < (b.x+b.y)*b.k-b.c;
}

vector<Coordinate> coordinates;
vector<long long int> lightsAns;
vector<pair<long long int,long long int> > supportsAns;

void choose(long long int index){
    long long int cost=0;
    long long int sx=coordinates[index].x;
    long long int sy=coordinates[index].y;
    long long int si=coordinates[index].index;
    long long int sk=coordinates[index].k;
    cost=cost+coordinates[index].c;

    vector<long long int> lights;
    vector<pair<long long int,long long int> > supports;

    lights.push_back(si);
    for(long long int i=index+1;i<n;i++){
        if( ( (abs(coordinates[i].x-sx) + abs(coordinates[i].y-sy)) * (sk+coordinates[i].k)) < coordinates[i].c){
            cost=cost+( (abs(coordinates[i].x-sx) + abs(coordinates[i].y-sy)) * (sk+coordinates[i].k));
            supports.push_back(make_pair(si,coordinates[i].index));
        }else{
            sx=coordinates[i].x;
            sy=coordinates[i].y;
            si=coordinates[i].index;
            sk=coordinates[i].k;
            cost=cost+coordinates[i].c;
            lights.push_back(si);
        }
    }

    sx=coordinates[index].x;
    sy=coordinates[index].y;
    si=coordinates[index].index;
    sk=coordinates[index].k;

    for(long long int i=index-1;i>=0;i--){
        if(( (abs(coordinates[i].x-sx) + abs(coordinates[i].y-sy)) * (sk+coordinates[i].k)) < coordinates[i].c){
            cost=cost+( (abs(coordinates[i].x-sx) + abs(coordinates[i].y-sy)) * (sk+coordinates[i].k));
            supports.push_back(make_pair(si,coordinates[i].index));
        }else{
            sx=coordinates[i].x;
            sy=coordinates[i].y;
            si=coordinates[i].index;
            sk=coordinates[i].k;
            cost=cost+coordinates[i].c;
            lights.push_back(coordinates[i].index);
        }
    }

    if(index==0){
        mini=cost;
        lightsAns=lights;
        supportsAns=supports;
    }
    else if(cost<=mini){
        mini=cost;
        lightsAns=lights;
        supportsAns=supports;
    }
}

int main(){
    long long int x,y,c,k;
    cin>>n;

    for(long long int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        Coordinate coordinate;
        coordinate.index=i;
        coordinate.x=x;
        coordinate.y=y;
        coordinates.push_back(coordinate);
    }

    for(long long int i=0;i<n;i++){
        cin>>c;
        coordinates[i].c=c;
    }
    for(long long int i=0;i<n;i++){
        cin>>k;
        coordinates[i].k=k;
    }

    sort(coordinates.begin(),coordinates.end(),coordinateComp);

    for(long long int i=0;i<n;i++){
        choose(i);
    }
    cout<<mini<<"\n";
    cout<<lightsAns.size()<<"\n";
    for(long long int i=0;i<lightsAns.size();i++){
        cout<<lightsAns[i]+1<<" ";
    }
    cout<<"\n";
    cout<<supportsAns.size()<<"\n";
    for(long long int i=0;i<supportsAns.size();i++){
        cout<<supportsAns[i].first+1<<" "<<supportsAns[i].second+1<<"\n";
    }
    return 0;
}
