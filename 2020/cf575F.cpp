#include<bits/stdc++.h>

using namespace std;
int maxX=1000000000;
int maxY=1000000000;
bool isBlack(pair<int,int> cell){
    return (cell.first + cell.second)%2!=0;
}

vector<pair<int,int> > neighbourCells(pair<int,int> cell,set<pair<int,int> > has){
    int x=cell.first;
    int y=cell.second;
    vector<pair<int,int> > ncells;
    if(x+1<=maxX && has.count(make_pair(x+1,y))==0){
        ncells.push_back(make_pair(x+1,y));
    }

    if(x-1>=1 && has.count(make_pair(x-1,y))==0){
        ncells.push_back(make_pair(x-1,y));
    }

    if(y-1>=1 && has.count(make_pair(x,y-1))==0){
        ncells.push_back(make_pair(x,y-1));
    }

    if(y+1<=maxY && has.count(make_pair(x,y+1))==0){
        ncells.push_back(make_pair(x,y+1));
    }

    return ncells;

}

vector<pair<int,int> > chessCells(int b, int w){
    vector<pair<int,int> > cells;
    set<pair<int,int> > has;

    if(b>w){
        w--;
        cells.push_back(make_pair(500000000,500000000));
        has.insert(make_pair(500000000,500000000));
    }
    else{
        b--;
        cells.push_back(make_pair(500000000,500000001));
        has.insert(make_pair(500000000,500000001));
    }
    int front=0;
    while(b+w>0 && front<cells.size()){

        pair<int,int> cell=cells[front];
        vector<pair<int,int> > v = neighbourCells(cell,has);
        if(v.size()==0)
            break;
        for(int i=0;i<v.size();i++){
            if(isBlack(v[i]) && b>0){
                b--;
                cells.push_back(v[i]);
            }
            else if(!isBlack(v[i]) && w>0){
                w--;
                cells.push_back(v[i]);
            }
            has.insert(v[i]);
        }
        front++;
    }

    return cells;
}

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int b,w;
        cin>>b>>w;

        vector<pair<int,int> > cells=chessCells(b,w);
        if((int)cells.size()==b+w){
            cout<<"YES\n";
            for(int j=0;j<b+w;j++){
                cout<<cells[j].first<<" "<<cells[j].second<<"\n";
            }
        }else
            cout<<"NO\n";
    }
    return 0;
}
