#include<bits/stdc++.h>

using namespace std;
int n;

void attackNight(pair<int,int> knight, string* chess, vector<pair<int,int> >& knights){
    int x=knight.first;
    int y=knight.second;
    //cout<<x<<" "<<y<<" "<<chess[x][y]<<"\n";
    char c;
    if(chess[x][y]=='W')
        c='B';
    else
        c='W';

    if(x+2<n && y+1<n && chess[x+2][y+1]=='0'){
        chess[x+2][y+1]=c;
        knights.push_back(make_pair(x+2,y+1));
    }
    if(x+2<n && y-1>=0 && chess[x+2][y-1]=='0'){
        chess[x+2][y-1]=c;
        knights.push_back(make_pair(x+2,y-1));
    }
    if(x-2>=0 && y+1<n && chess[x-2][y+1]=='0'){
        chess[x-2][y+1]=c;
        knights.push_back(make_pair(x-2,y+1));
    }
    if(x-2>=0 && y-1>=0 && chess[x-2][y-1]=='0'){
        chess[x-2][y-1]=c;
        knights.push_back(make_pair(x-2,y-1));
    }


    if(x+1<n && y+2<n && chess[x+1][y+2]=='0'){
        chess[x+1][y+2]=c;
        knights.push_back(make_pair(x+1,y+2));
    }
    if(x+1<n && y-2>=0 && chess[x+1][y-2]=='0'){
        chess[x+1][y-2]=c;
        knights.push_back(make_pair(x+1,y-2));
    }
    if(x-1>=0 && y+2<n && chess[x-1][y+2]=='0'){
        chess[x-1][y+2]=c;
        knights.push_back(make_pair(x-1,y+2));
    }
    if(x-1>=0 && y-2>=0 && chess[x-1][y-2]=='0'){
        chess[x-1][y-2]=c;
        knights.push_back(make_pair(x-1,y-2));
    }
}

void fillKnight(vector<pair<int,int> > knights, string* chess){

    vector<pair<int,int> > nextNights;
    for(int i=0;i<knights.size();i++){
        pair<int,int> knight = knights[i];
        if(chess[knight.first][knight.second]=='0')
            chess[knight.first][knight.second]='W';
        attackNight(knight,chess,nextNights);
    }

    if(nextNights.size()>0)
    fillKnight(nextNights, chess);
}

int main(){
    cin>>n;
    string chess[n];
    for(int i=0;i<n;i++){
        chess[i]="";
        for(int j=0;j<n;j++){
            chess[i].push_back('0');
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(chess[i][j]=='0'){
                vector<pair<int,int> > knights;
                knights.push_back(make_pair(i,j));
                fillKnight(knights,chess);
            }
        }
    }

    //cout<<chess[1][1];
    for(int i=0;i<n;i++)
        cout<<chess[i]<<"\n";
    return 0;
}
