#include<bits/stdc++.h>

using namespace std;
map<pair<int,int>,int> game;


map<pair<int,int>,int> ans;
map<pair<int,int>,int>::iterator ansIt;

int bruteForceDist(map<pair<int,int>,int>::iterator gameIt,int n,int k){

    if(gameIt == game.end()){

        int arr[n][n];
        for(int i=0;i<n;i++)
            arr[i][i]=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                gameIt=game.find(make_pair(i,j));
                arr[i][j]=gameIt->second;
                arr[j][i]=1-gameIt->second;
            }
        }
        int ts=0,sm=0;
        for(int i=0;i<n;i++){
            sm=0;
            for(int j=0;j<n;j++){
                sm=sm+arr[i][j];
            }
            ts=ts+sm*sm;
        }
        if(ts==k){
            ans=game;
            return 1;
        }
        return 0;
    }

    int i=(gameIt->first).first;
    int j=(gameIt->first).second;
    int v=gameIt->second;
    gameIt++;
    int r=bruteForceDist(gameIt,n,k);
    if(r==1)
        return 1;
    gameIt=game.find(make_pair(i,j));

    game.erase(gameIt);
    game.insert(make_pair(make_pair(i,j),1-v));
    gameIt=game.find(make_pair(i,j));
    gameIt++;
    return bruteForceDist(gameIt,n,k);

}

int main(){
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        game.clear();
        ans.clear();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                game.insert(make_pair(make_pair(i,j),0));
            }
        }

        if(bruteForceDist(game.begin(),n,k)==0)
            cout<<"-1\n";
        else{
            int arr[n][n];
            for(int i=0;i<n;i++)
                arr[i][i]=0;

            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ansIt=ans.find(make_pair(i,j));
                    arr[i][j]=ansIt->second;
                    arr[j][i]=1-ansIt->second;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<arr[i][j];
                }
                cout<<"\n";
            }

        }
    }
    return 0;
}
